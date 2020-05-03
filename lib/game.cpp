#include <iostream>

#include "game.hpp"

Game::
~Game(){
}

ConnectFour::
ConnectFour(int width, int height, int connect)
 //  : m_state(new ConnectFourState())
{
  // std::cout << "Connect Four Game Created !!\n";
  m_state = new ConnectFourState(width, height, connect);
  m_state->display();
}

ConnectFour::
~ConnectFour(){
  // std::cout << "Connect Four Game Destroyed !!\n";
  delete m_state;
}

GameState
ConnectFour::
make_human_move(int player_order){
  //std::cout << "Human is making a move in Connect Four \n";
  int move = -1;
  bool valid_move = false;

  while(!valid_move){
    std::cout << "Please provide a column for input: ";
    std::cin >> move;
    valid_move = m_state->act(ConnectFourAction(move, player_order), player_order);
    is_player1 = !is_player1;
  }
  return status(m_state);
}


int
ConnectFour::
utility(const State* s) const {
  return s->utility();
}

GameState
ConnectFour::
status(const State* s) const {
  StateStatus status = s->status();
  return (status == S_TERMINAL)? S_DONE: S_GOING;
}


std::vector<Action*> 
ConnectFour::
action_set(int player_order) const {
  return m_state->action_set(player_order);
}


GameState 
ConnectFour::
make_move(const Action& action){
  m_state->act(action, action.player());
  return status(m_state);
}
