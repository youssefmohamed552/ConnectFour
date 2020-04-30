#include <iostream>
#include "action.hpp"

Action::
~Action(){
  std::cout << "Action Created!!\n";
}

ConnectFourAction::
ConnectFourAction(int move, int player)
  : m_move(move)
{
  std::cout << "Connect Four Action Created!!\n";
  m_player = player;
}



ConnectFourAction::
~ConnectFourAction(){
  std::cout << "Connect Four Action Destroyed!!\n";
}
