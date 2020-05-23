#include <iostream>
#include "gui/render_area.hpp"
#include "game/connect_four_action.hpp"
#include "game/connect_four_state.hpp"

RenderArea::
RenderArea(QWidget* parent, ConnectFour* game)
  : QWidget(parent), m_width(640), m_height(480), m_game(game)
{
  // QRect r = parent->rect();
  // std::cout << "Render Area => (x,y,width,height) : (" << r.x() << "," << r.y() << "," << r.height() << "," << r.width() << ")\n";
  m_board_rect = QRect(50, 50, width()-100, height()-100);
  setBackgroundRole(QPalette::Base);
  setAutoFillBackground(true);
  setGeometry(0,0,m_width,m_height);
}


void
RenderArea::
paintEvent(QPaintEvent* e){
  // std::cout << "called paint Event\n";
  QPainter painter(this);
  // painter.setPen(QPen(Qt::green, 6));
  // painter.drawLine(0, 0, 640,480);
  // painter.fillRect(50,50,width()-100, height()-100, Qt::blue);
  drawBoard(e, painter);
}



void
RenderArea::
drawBoard(QPaintEvent* e,QPainter& painter){
  std::cout << "draw board\n";
  QRect board_rect(50,50,width()-100, height()-100);
  painter.fillRect(board_rect, Qt::blue);
  int num_of_cells_height = 6;
  int num_of_cells_width = 7;
  int cell_x = board_rect.x();
  int cell_y = board_rect.y();
  int cell_width = board_rect.width() / num_of_cells_width;
  int cell_height = board_rect.height() / num_of_cells_height;
  // painter.setBrush(QBrush(Qt::black));
  // QRect cell_rect(cell_x+(cell_width/6), cell_y+(cell_height/6), (cell_width*2)/3, (cell_height*2)/3);
  // painter.drawEllipse(cell_rect);
  for(int i = 0; i < num_of_cells_height; i++){
    cell_x = board_rect.x();
    for(int j = 0; j < num_of_cells_width; j++){
      ConnectFourToken token = static_cast<ConnectFourState*>(m_game->current_state())->get(j, i);
      switch(token){
        case T_EMPTY:
          painter.setBrush(QBrush(Qt::black));
          break;
        case T_RED:
          painter.setBrush(QBrush(Qt::red));
          break;
        case T_YELLOW:
          painter.setBrush(QBrush(Qt::yellow));
      }
      QRect cell_rect(cell_x+(cell_width/6), cell_y+(cell_height/6), (cell_width*2)/3, (cell_height*2)/3);
      painter.drawEllipse(cell_rect);
      cell_x += cell_width;
    }
    cell_y += cell_height;
  }
  
}

void
RenderArea::
mousePressEvent(QMouseEvent* event){
  std::cout << "Mouse Pressed at (x,y) : (" << event->x() << "," << event->y() << ")\n";
  if(m_game->current_state()->status() == S_TERMINAL) return;
  int move = -1;
  bool valid_move = false;
  int p = m_game->current_player()->order();

  while(!valid_move){
     move = get_column(event->x());
     std::cout << "move is in col : " << move << "\n";
     valid_move = m_game->current_state()->act(ConnectFourAction(move, p), p);
  }
  // update();
  repaint();
  std::cout << "updated the game\n";
  if(m_game->current_state()->status() == S_TERMINAL){
    std::cout << "GAME OVER : Player1 wins\n";
    return;
    // exit(EXIT_SUCCESS);
  }
  m_game->next_player();
  m_game->current_player()->move(m_game->current_state());
  // update();
  repaint();
  if(m_game->current_state()->status() == S_TERMINAL){
    std::cout << "GAME OVER : Player2 wins\n";
    return;
    // exit(EXIT_SUCCESS);
  }
  m_game->next_player();

  
}


int
RenderArea::
get_column(int x){
  if(x < 50 || x > width()-50) return -1;
  ConnectFourState* state = static_cast<ConnectFourState*>(m_game->current_state());
  int cell_width = (width() - 100) / state->width();
  std::cout << "cell width is : " << cell_width << "\n";
  return (x-50) / cell_width;
}



