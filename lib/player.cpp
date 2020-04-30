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
  std::cout << "Human Player " << m_order << "  Move\n";
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
  std::cout << "Random Player Created!!\n";
  m_game = game;
}

RandomPlayer::
~RandomPlayer(){
  std::cout << "Random Player Destroyed!!\n";
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
  std::cout << "MiniMax Player Created!!\n";
  m_game = game;
}

MiniMaxPlayer::
~MiniMaxPlayer(){
  std::cout << "MiniMax Player Destroyed!!\n";
}

GameState
MiniMaxPlayer::
move(){
  Action* a  = search(m_game->current_state(), true);
  if(!a) return S_FAILED;
  GameState result = m_game->make_move(*a);
  delete a;
  return result;
}

Action*
MiniMaxPlayer::
search(State* s, bool is_maximize){
  if(!s) return NULL;
  std::vector<Action*> act_set = s->action_set(m_order);
  std::cout << "following states: \n";
  for(int i = 0; i < act_set.size(); i++){
    State* ns = s->copy();
    ns->act(*(act_set[i]));
    ns->display();
    int next_char;
    std::cin >> next_char;
    if(ns->status() == S_TERMINAL) continue;
    search(ns, !is_maximize);
  }
  return new ConnectFourAction(0, m_order);
}

