#ifndef PLAYER_HPP
#define PLAYER_HPP


#include <unordered_set>
#include "game.hpp"


class Player{
  protected:
    Game* m_game;
    int m_order;
    // std::unordered_set<Action*> m_actions;
  public:
    static int count;
    virtual ~Player();
    virtual GameState move() = 0;
};

class HumanPlayer : public Player {
  public:
    HumanPlayer(Game* game);
    virtual ~HumanPlayer();
    virtual GameState move();
};

class ComputerPlayer : public Player {
  public:
    virtual ~ComputerPlayer();
    virtual GameState move() = 0;

};

class RandomPlayer : public ComputerPlayer {
  public:
    RandomPlayer(Game* game);
    virtual ~RandomPlayer();
    virtual GameState move();
    int get_random_number(int bound);
};

class MiniMaxPlayer : public ComputerPlayer {
  public:
    MiniMaxPlayer(Game* game);
    virtual ~MiniMaxPlayer();
    virtual GameState move();
    Action* search(State* s, bool is_maximize);
};

class H_MiniMaxPlayer : public ComputerPlayer {
  // TODO
};



#endif /* PLAYER_HPP */
