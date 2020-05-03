#ifndef GAME_HPP
#define GAME_HPP

#include <unordered_set>
#include "state.hpp"


enum GameState{
  S_DONE,
  S_GOING,
  S_FAILED
};

class Game{
  protected:
    int m_score;
    int m_round;
    State* m_state;
  public:
    virtual ~Game();
    virtual GameState make_human_move(int player_order) = 0; 
    virtual GameState make_move(const Action& action) = 0;
    virtual std::vector<Action*> action_set(int player_order) const = 0;
    virtual int utility(const State* s) const = 0;
    virtual void display() const { m_state->display(); }
    virtual State* current_state() const { return m_state; }
    virtual void set_current_state( State* s) { m_state = s; }
    virtual GameState status(const State* s) const = 0; 
};


class ConnectFour : public Game{
  bool is_player1 = true;
  public:
    ConnectFour(int width, int height, int connect);
    virtual ~ConnectFour();
    virtual GameState make_human_move(int player_order);
    virtual GameState make_move(const Action& action);
    virtual int utility(const State* s) const;
    virtual std::vector<Action*> action_set(int player_order) const;
    virtual GameState status(const State* s) const; 
};

#endif /* GAME_HPP */
