#include <iostream>
#include "game/connect_four_action.hpp"


ConnectFourAction::
ConnectFourAction(int move, int player)
  : m_move(move)
{
  m_player = player;
}



ConnectFourAction::
~ConnectFourAction(){
}
