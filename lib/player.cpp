#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <stdio.h>


#include "player.hpp"



int
Player::
count = 0;


/*
 * Player: an abstraction over all sorts of all intelligent players whether it's 
 * natural or artifitial
 */

Player::
~Player(){
  // std::cout << "Player Destroyed !!\n";
}



/*
 * HumanPlayer: realies on the user input to play the game
 */

HumanPlayer::
HumanPlayer(Game* game)
{
  // std::cout << "Human Player Created !!\n";
  m_game = game;
  m_order = count + 1;
  // std::cout << "order : " << m_order << "\n";
  count++;
}



HumanPlayer::
~HumanPlayer()
{
  // std::cout << "Human Player Destroyed !!\n";
}




GameState
HumanPlayer::
move(){
  // std::cout << "Human Player " << m_order << "  Move\n";
  return m_game->make_human_move(m_order);
}


/*
 * ComputerPlayer: an abstraction over all Artifitially Intelligent agents that would
 * sorlve any given game
 */

ComputerPlayer::
~ComputerPlayer(){
  // std::cout << "Computer Player Destroyed !!\n";
}




/*
 * RandomPlayer: goes through the action set and picks one at random
 */

RandomPlayer::
RandomPlayer(Game* game)
{
  // std::cout << "Random Player Created!!\n";
  m_game = game;
}

RandomPlayer::
~RandomPlayer(){
  // std::cout << "Random Player Destroyed!!\n";
}


GameState
RandomPlayer::
move(){
  std::vector<Action*> act_set = m_game->action_set(m_order);
  int random_move = 0;
  if(act_set.size() > 1) random_move = get_random_number(act_set.size());
  GameState result =  m_game->make_move(*act_set[random_move]);
  for(int i = 0; i < act_set.size(); i++) delete act_set[i];
  return result;
}


int
RandomPlayer::
get_random_number(int bound){
  srand(time(NULL));
  return rand() % bound;
}


/*
 * MiniMax player solves the game based on building the decision tree and traversing it
 * to find the next move through MiniMax algorithms
 */

MiniMaxPlayer::
MiniMaxPlayer(Game* game){
  // std::cout << "MiniMax Player Created!!\n";
  m_game = game;
  m_order = count + 1;
  count++;
}

MiniMaxPlayer::
~MiniMaxPlayer(){
  // std::cout << "MiniMax Player Destroyed!!\n";
}

GameState
MiniMaxPlayer::
move(){
  StateNode root(m_game->current_state(), m_order);
  std::vector<Action*> act_set = root.state()->action_set(m_order);
  std::pair<int,int> max_val = {INT_MIN, INT_MAX};
  Action* best_action;
  // std::cout << "outcomes: \n";
  StateNode::count = 0;
  for(int i = 0; i < act_set.size(); i++){
    StateNode child = root;
    child.update(*(act_set[i]), m_order);
    std::pair<int,int> val = eval(child, false, 1);
    // child.state()->display();
    // std::cout << "(" << val.first << "," << val.second <<  ") \n";
    if(val.first > max_val.first || ((val.first == max_val.first) && (val.second < max_val.second))){ 
      max_val = val;
      best_action = act_set[i];
    }
  }
  std::cout << "\n";
  std::cout << "count : " << StateNode::count << std::endl;;
  if(best_action == NULL)
    return S_FAILED;
  return m_game->make_move(*best_action);
}

std::pair<int,int>
MiniMaxPlayer::
eval(StateNode root, bool is_maximize, int depth){
  if(root.is_terminal()) return {root.utility(),depth};
  int player = (is_maximize?((m_order == 1)? 1:2 ) : ((m_order == 1)? 2: 1));
  std::vector<Action*> act_set = root.state()->action_set(player);
  std::pair<int,int> max_val = {INT_MIN,INT_MAX};
  std::pair<int,int> min_val = {INT_MAX,INT_MAX};
  Action* best_action;
  for(int i = 0; i< act_set.size(); i++){
    StateNode child = root;
    child.update(*(act_set[i]), m_order);
    std::pair<int,int> val = eval(child, !is_maximize, depth +1);
    // char c;
    // std::cin >> c;
    // std::cout << "(" << val.first << "," << val.second << ")\n";
    // child.state()->display();
    if(is_maximize){
      if(val.first > max_val.first || ((val.first == max_val.first) && (val.second < max_val.second))){
        max_val = val;
      }
    }
    else{
      if(val.first < min_val.first || ((val.first == min_val.first) && (val.second < min_val.second)))
        min_val = val;
    }
  }

  return (is_maximize? max_val: min_val);
}


StateNode&
MiniMaxPlayer::
search(StateNode& sn, int player_order, int depth, bool is_maximize){
  return sn;
}


/*
GameState
MiniMaxPlayer::
move(){
  StateNode root(m_game->current_state(), m_order);
  std::cout << "the root is for player : " << m_order << "\n";
  StateNode::count = 0;
  StateNode result  = search(root, m_order, 0, true);
  std::cout << "searched : " << StateNode::count << " states\n";
  // std::cout << "AI plays: \n";
  // result.state()->display();
  // GameState result = m_game->make_move(*a);
  // delete a;
  return (result.is_terminal())? S_DONE: S_GOING;
}

StateNode&
MiniMaxPlayer::
search(StateNode& sn, int player_order, int depth, bool is_maximize){
  // if(!s) return NULL;
  std::vector<Action*> act_set = sn.state()->action_set(player_order);
  std::vector<int> outcomes(act_set.size());
  // std::cout << "following states: \n";
  for(int i = 0; i < act_set.size(); i++){
    StateNode state_node = sn;
    // State* ns = state_node.state()->copy();
    state_node.update(*(act_set[i]));
    // std::cout << "new State Node : \n";
    // state_node.state()->display();
    // std::cout << "original State Node : \n";
    // std::cout << "DEPTH : " << depth << "\n";
    // state_node.state()->display();
    // if(state_node.is_terminal())std::cout << "this state is terminal with utility : " << state_node.utility() << " with: " << act_set.size() << "\n";
    if(state_node.is_terminal()){
      outcomes[i] = state_node.utility();
      continue;
    }

    outcomes[i] = (search(state_node, ((player_order == 1)? 2 : 1), depth + 1, is_maximize)).utility();
  }
  // int next_char;
  // std::cin >> next_char;
  // return new ConnectFourAction(0, m_order);
  // std::cout << "finding the best outcome\n";
  
  int choice = -1;
  // std::cout << "the root player : " << sn.player() << " the current player : " << player_order <<" with depth : " << depth <<  std::endl;
  // std::cout << "the outcomes: ";
  // for(int i = 0; i < outcomes.size(); i++){
    // std::cout << outcomes[i] << " "; 
  // }
  // std::cout << "\n";
  if(is_maximize) choice = std::max_element(outcomes.begin(), outcomes.end()) - outcomes.begin();
  else choice = std::min_element(outcomes.begin(), outcomes.end()) - outcomes.begin();
  // std::cout << "the action is with the best return " << choice << std::endl;
  sn.update(*(act_set[choice]));
  // sn.state()->display();
  return sn;
}
*/

