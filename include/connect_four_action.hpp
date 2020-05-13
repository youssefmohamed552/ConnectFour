#ifndef CONNECT_FOUR_ACTION_HPP
#define CONNECT_FOUR_ACTION_HPP

#include "action.hpp"

class ConnectFourAction : public Action {
  private:
    int m_move;
  public:
    ConnectFourAction(int move, int player);
    ~ConnectFourAction();
    virtual int move() const {return m_move;}
};

#endif /* CONNECT_FOUR_ACTION_HPP */
