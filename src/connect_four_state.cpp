#include <iostream>

#include "connect_four_state.hpp"



int
get_max(const std::vector<std::vector<int>>& v){
  int max_num = INT_MIN;
  for(auto l:v){
    int temp_max = *std::max_element(l.begin(), l.end());
    if(temp_max > max_num) max_num = temp_max;
  }
  return max_num;
}


int
get_min(const std::vector<std::vector<int>>& v){
  int min_num = INT_MAX;
  for(auto l:v){
    int temp_min = *std::min_element(l.begin(), l.end());
    if(temp_min > min_num) min_num = temp_min;
  }
  return min_num;
}

int compute_total(const std::vector<std::vector<int>>& v){
  int total_num = 0;
  for(auto l:v){
    for(auto n:l){
      total_num += n;
    }
  }
  return total_num;
}



ConnectFourState::
ConnectFourState(int width, int height, int connect)
  : m_board(std::vector<ConnectFourToken>(width*height, T_EMPTY)), m_col(std::vector<int>(width)), m_width(width), m_height(height), m_connect(connect)
{
  // std::cout << "Connect Four State Created !!\n";
  m_utility = -2;
  m_huristic = INT_MIN;
  m_status = S_NON_TERMINAL;
}


ConnectFourState::
~ConnectFourState(){
  // std::cout << "Connect Four State Destroyed !!\n";
}

void
ConnectFourState::
display() const {
  std::cout << "  ";
  for(int i = 0; i < m_width; i++)
    std::cout << i << " ";
  std::cout << std::endl;

  for(int i = 0; i < m_height; i++){
    std::cout << m_height - i - 1  << " ";
    for(int j = 0; j < m_width; j++){
      if(get(j, i) == T_EMPTY) std::cout << "  ";
      if(get(j, i) == T_RED) std::cout << "R ";
      if(get(j, i) == T_YELLOW) std::cout << "Y ";
    }
    std::cout << m_height - i - 1 << std::endl;
  }

  std::cout << "  ";
  for(int i = 0; i < m_width; i++)
    std::cout << i << " ";
  std::cout << std::endl;
}

bool
ConnectFourState::
act(const Action& a, int p){
  if(a.move() >= m_width || a.move() < 0) return false;
  int h = m_col[a.move()];
  if(h >= m_height ) return false;
  if(a.player() == 1)
    set(a.move(), m_height-h-1, T_RED);
  else
    set(a.move(), m_height-h-1, T_YELLOW);
  m_col[a.move()]++;
  compute_utility(p);
  return true;
}

// StateStatus
void
ConnectFourState::
compute_utility(int player_order) {
  ConnectFourToken player_token = (player_order == 1)? T_RED : T_YELLOW;
  int w = m_width - m_connect;
  int h = m_height - m_connect;



  // check horizontally
  for(int i = 0; i < m_height; i++){
    for(int j = 0; j <= w; j++){
      if(get(j, i) == T_EMPTY) continue;
      ConnectFourToken first_token = get(j, i);
      int k = 1;
      for(; k < m_connect; k++){
        if(get(j+k, i) != first_token) break;
      }
      if(k >= m_connect){
        m_utility =  ((first_token == player_order)? 1 : -1 );
        m_status = S_TERMINAL;
        return;
      }
    }
  }

  // check vertically
  for(int i = 0; i <= h; i++){
    for(int j = 0; j < m_width; j++){
      if(get(j, i) == T_EMPTY) continue;
      ConnectFourToken first_token = get(j, i);
      int k = 1;
      for(; k < m_connect; k++){
        if(get(j, i+k) != first_token) break;
      }
      if(k >= m_connect){
        m_utility =  ((first_token == player_order)? 1 : -1 );
        m_status = S_TERMINAL;
        return;
      }
    }
  }

  // check diagonally top right
  for(int i = 0; i <= h; i++){
    for(int j = 0; j <= w; j++){
      if(get(j, i) == T_EMPTY) continue;
      ConnectFourToken first_token = get(j, i);
      int k = 1;
      for(; k < m_connect; k++){
        if(get(j+k, i+k) != first_token) break;
      }
      if(k >= m_connect){
        m_utility =  ((first_token == player_order)? 1 : -1);
        m_status = S_TERMINAL;
        return;
      }
    }
  }


  // check diagonally bottom right
  for(int i = m_connect-1; i < m_height; i++){
    for(int j = 0; j <= w; j++){
      if(get(j, i) == T_EMPTY) continue;
      ConnectFourToken first_token = get(j, i);
      int k = 1;
      for(; k < m_connect; k++){
        if(get(j+k, i-k) != first_token) break;
      }
      if(k >= m_connect){
        m_utility =  ((first_token == player_order)? 1 : -1);
        m_status = S_TERMINAL;
        return;
      }
    }
  }

  StateStatus status = check_draw();
  if(status == S_TERMINAL){
    m_status = S_TERMINAL;
    m_utility = 0;
    return;
  }

  m_status = S_NON_TERMINAL;
}

StateStatus
ConnectFourState::
check_draw() const{
  for(int i = 0; i < m_width; i++){
    if(m_col[i] < m_height) return S_NON_TERMINAL;
  }
  return S_TERMINAL;
}



std::vector<Action*> 
ConnectFourState::
action_set(int player_order) const{
  std::vector<Action*> act_set;
  for(int i = 0; i < m_width; i++){
    if(m_col[i] >= m_height) continue;
    act_set.push_back(new ConnectFourAction(i,player_order));
  }
  return act_set;
}


State*
ConnectFourState::
copy(){
  ConnectFourState* new_state = new ConnectFourState(m_width, m_height, m_connect);
  *new_state = *this;
  return new_state;
}

StateStatus
ConnectFourState::
check_status(){
  // TODO
  return S_TERMINAL;
}



int
StateNode::
count = 0;

StateNode::
StateNode( State* state, int player)
  : m_state(state), m_player(player), m_utility(-2), player_move(player)
{
  // std::cout << "State Node Destroyed !!\n";
  count++;
}

StateNode::
StateNode( const StateNode& other){
  // std::cout << "State Node Copied !!\n";
  m_state = other.state()->copy();
  m_player = other.player();
  m_utility = other.utility();
  player_move = other.player_move;
  count++;
  // if(count % 100000 == 0) std::cout << count << "states searched so far\n";
}

StateNode::
~StateNode(){
  // std::cout << "State Node Created !!\n";
}

bool
StateNode::
update(const Action& a, int p){
  bool res = m_state->act(a, p);
  m_utility = m_state->utility();
  player_move = p;
  return res;
}


int 
ConnectFourState::
compute_huristic(int player_order){
  int h = check_horizontal(player_order);
  int w = check_vertical(player_order);
  int dr = check_diagonal_right(player_order);
  int dl = check_diagonal_left(player_order);
  return  h + w + dr + dl;
}

int
ConnectFourState::
check_horizontal(int player_order){
  std::vector<std::vector<int>> temp(m_height, std::vector<int>(m_width,0));
  for(int i = 0; i < temp.size(); i++){
    temp[i][0] = get_cell_val(0, i, player_order);
  }
  for(int i = 0; i < temp.size(); i++){
    for(int j = 1; j < temp[i].size(); j++){
      if(get(j, i) == T_EMPTY) {
        temp[i][j] = 0;
        continue;
      }
      if(get(j, i) == get(j-1, i)){
        int val = get_cell_val(j, i, player_order);
        temp[i][j] = temp[i][j-1] + val;
        continue;
      }
      temp[i][j] = get_cell_val(j, i, player_order);
    }
  }
  // for(auto l: temp){
    // for(auto v: l){
      // std::cout << v << " ";
    // }
    // std::cout << std::endl;
  // }
  return compute_total(temp);
}

int
ConnectFourState::
check_vertical(int player_order){
  std::vector<std::vector<int>> temp(m_height, std::vector<int>(m_width,0));
  for(int i = 0; i < temp.size(); i++){
    temp[0][i] = get_cell_val(i, 0, player_order);
  }
  for(int i = 1; i < temp.size(); i++){
    for(int j = 0; j < temp[i].size(); j++){
      if(get(j, i) == T_EMPTY) {
        temp[i][j] = 0;
        continue;
      }
      if(get(j, i) == get(j, i-1)){
        int val = get_cell_val(j, i, player_order);
        temp[i][j] = temp[i-1][j] + val;
        continue;
      }
      temp[i][j] = get_cell_val(j, i, player_order);
    }
  }
  // for(auto l: temp){
    // for(auto v: l){
      // std::cout << v << " ";
    // }
    // std::cout << std::endl;
  // }
  return compute_total(temp);
}

int
ConnectFourState::
check_diagonal_right(int player_order){
  std::vector<std::vector<int>> temp(m_height, std::vector<int>(m_width,0));
  for(int i = 0; i < m_width; i++){
    temp[0][i] = get_cell_val(i, 0, player_order);
  }
  for(int i = 0; i < m_height; i++){
    temp[i][0] = get_cell_val(0, i, player_order);
  }
  for(int i = 1; i < temp.size(); i++){
    for(int j = 1; j < temp[i].size(); j++){
      if(get(j, i) == T_EMPTY) {
        temp[i][j] = 0;
        continue;
      }
      if(get(j, i) == get(j-1, i-1)){
        int val = get_cell_val(j, i, player_order);
        temp[i][j] = temp[i-1][j-1] + val;
        continue;
      }
      temp[i][j] = get_cell_val(j, i, player_order);
    }
  }
  // for(auto l: temp){
    // for(auto v: l){
      // std::cout << v << " ";
    // }
    // std::cout << std::endl;
  // }
  return compute_total(temp);
}


int
ConnectFourState::
check_diagonal_left(int player_order){
  std::vector<std::vector<int>> temp(m_height, std::vector<int>(m_width,0));
  for(int i = 0; i < m_width; i++){
    temp[0][i] = get_cell_val(i, 0, player_order);
  }
  for(int i = 0; i < m_height; i++){
    temp[i][m_width-1] = get_cell_val(m_width-1, i, player_order);
  }
  for(int i = 1; i < temp.size(); i++){
    for(int j = 0; j < temp[i].size()-1; j++){
      if(get(j, i) == T_EMPTY) {
        temp[i][j] = 0;
        continue;
      }
      if(get(j, i) == get(j+1, i-1)){
        int val = get_cell_val(j, i, player_order);
        temp[i][j] = temp[i-1][j+1] + val;
        continue;
      }
      temp[i][j] = get_cell_val(j, i, player_order);
    }
  }
  // for(auto l: temp){
    // for(auto v: l){
      // std::cout << v << " ";
    // }
    // std::cout << std::endl;
  // }
  return compute_total(temp);
}


int
ConnectFourState::
get_cell_val(int x, int y, int player_order){
  ConnectFourToken t = get(x, y);
  ConnectFourToken p = (player_order == 1)? T_RED : T_YELLOW;
  switch(t){
    case T_RED:
      if(p == T_RED) return 1;
      else return -1;
    case T_YELLOW:
      if(p == T_YELLOW) return 1;
      else return -1;
    case T_EMPTY:
      return 0;
  }
}
