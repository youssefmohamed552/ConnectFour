#ifndef CONNECT_FOUR_STATE_HPP
#define CONNECT_FOUR_STATE_HPP

#include <vector>
#include <unordered_set>
#include "state.hpp"
#include "game/connect_four_action.hpp"

enum ConnectFourToken{
  T_EMPTY,
  T_RED,
  T_YELLOW
};


enum ConnectFourStatus{
  C_NON_TERMINAL,
  C_PLAYER_1_WINS,
  C_PLAYER_2_WINS,
  C_DRAW
};



class ConnectFourState : public State {
  private:
    std::vector<ConnectFourToken> m_board;
    std::vector<int> m_col;
    int m_width,m_height,m_connect;
  public:
    ConnectFourState(int width, int height, int connect);
    virtual ~ConnectFourState();
    virtual void display() const;
    ConnectFourToken get(int x, int y) const { return m_board[y*m_width + x]; }
    void set(int x, int y, ConnectFourToken val){ m_board[y*m_width + x] = val;}
    virtual bool act(const Action& a, int p);
    virtual bool human_act(int p);
    virtual void compute_utility(int player_order);
    virtual int compute_huristic(int player_order);
    virtual std::vector<Action*> action_set(int player_order) const;
    virtual State* copy();
    virtual StateStatus check_status();
    virtual StateStatus check_draw() const;
    int get_cell_val(int x, int y, int player_order);
    int check_horizontal(int player_order);
    int check_vertical(int player_order);
    int check_diagonal_right(int player_order);
    int check_diagonal_left(int player_order);
    int width() const { return m_width; }
    int height() const { return m_height; }
    int connect() const { return m_connect; }
};


#endif /* CONNECT_FOUR_STATE_HPP */
