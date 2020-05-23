#include <iostream>
#include "render_area.hpp"

RenderArea::
RenderArea(QWidget* parent)
  : QWidget(parent), m_width(640), m_height(480)
{
  // QRect r = parent->rect();
  // std::cout << "Render Area => (x,y,width,height) : (" << r.x() << "," << r.y() << "," << r.height() << "," << r.width() << ")\n";
  setBackgroundRole(QPalette::Base);
  setAutoFillBackground(true);
  setGeometry(0,0,m_width,m_height);
}


void
RenderArea::
paintEvent(QPaintEvent* e){
  std::cout << "called paint Event\n";
  QPainter painter(this);
  // painter.setPen(QPen(Qt::green, 6));
  // painter.drawLine(0, 0, 640,480);
  // painter.fillRect(50,50,width()-100, height()-100, Qt::blue);
  drawBoard(e, painter);
}



void
RenderArea::
drawBoard(QPaintEvent* e,QPainter& painter){
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
      painter.setBrush(QBrush(Qt::red));
      QRect cell_rect(cell_x+(cell_width/6), cell_y+(cell_height/6), (cell_width*2)/3, (cell_height*2)/3);
      painter.drawEllipse(cell_rect);
      cell_x += cell_width;
    }
    cell_y += cell_height;
  }
  
}

