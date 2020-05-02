#ifndef STATE_HPP
#define STATE_HPP

#include <vector>
#include <unordered_set>
#include "action.hpp"

enum ConnectFourToken{
  T_EMPTY,
  T_RED,
  T_YELLOW
};

enum StateStatus{
  S_TERMINAL,
  S_NON_TERMINAL
};

enum ConnectFourStatus{
  C_NON_TERMINAL,
  C_PLAYER_1_WINS,
  C_PLAYER_2_WINS,
  C_DRAW
};


class State{
  protected:
    int m_utility;
    StateStatus m_status;
  public:
    virtual ~State();
    virtual void display() const = 0;
    virtual bool act(const Action& a, int p) = 0;
    virtual void compute_utility(int player_order) = 0;
    virtual std::vector<Action*> action_set(int player_order) const = 0;
    virtual State* copy() = 0;
    virtual StateStatus check_status() = 0;
    virtual StateStatus check_draw() const = 0;
    virtual StateStatus status() const { return m_status; }
    virtual int utility() const { return m_utility; }

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
    virtual void compute_utility(int player_order);
    virtual std::vector<Action*> action_set(int player_order) const;
    virtual State* copy();
    virtual StateStatus check_status();
    virtual StateStatus check_draw() const;

};

class StateNode{
  private:
    State* m_state;
    int m_player;
    int m_utility;
  public:
    static int count;
    StateNode( State* state, int player);
    StateNode( const StateNode& other );
    ~StateNode();
    State* state() const { return m_state; }
    int utility() const { return m_utility; }
    int player() const { return m_player; }
    bool is_terminal() const { return m_state->status() == S_TERMINAL; }
    bool update(const Action& a, int p);

};

#endif /* STATE_HPP */
