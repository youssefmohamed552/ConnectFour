#ifndef ACTION_HPP
#define ACTION_HPP

class Action {
  protected:
    int m_player;
  public:
  virtual ~Action();
  int player() const {return m_player;}
  virtual int move() const = 0;
};

class ConnectFourAction : public Action {
  private:
    int m_move;
  public:
    ConnectFourAction(int move, int player);
    ~ConnectFourAction();
    virtual int move() const {return m_move;}
};

#endif /* ACTION_HPP */
