#include <iostream>

#include "game/connect_four_game.hpp"
#include "game/connect_four_state.hpp"


ConnectFour::
ConnectFour(Player* player1, Player* player2)
  : m_player1(player1), m_player2(player2)
{
  std::cout << "This is Connect Four!! \n";

  std::cout << "Which game would you like to play:\n";
  std::cout << "1. Connect Four 3x3x3\n";
  std::cout << "2. Connect Four 3x5x3\n";
  std::cout << "3. Connect Four 6x7x4\n";
  int choice = 3; 
  // std::cin >> choice;
  while(choice > 3 || choice < 1){
    std::cout << "please choose one of the option above: ";
    std::cin >> choice;
  }

  m_state = nullptr;
  if(choice == 1) m_state = new ConnectFourState(3, 3, 3);
  if(choice == 2) m_state = new ConnectFourState(3, 5, 3);
  if(choice == 3) m_state = new ConnectFourState(7, 6, 4);

  m_current_player = m_player1;
  // m_state->display();

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

void
ConnectFour::
next_player(){
  if(m_current_player == m_player1) m_current_player = m_player2;
  else m_current_player = m_player1;
}


