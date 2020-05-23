#pragma once

#include <QtWidgets>
#include <QtGui>

#include "game/connect_four_game.hpp"

class RenderArea: public QWidget{
  private:
    int m_width;
    int m_height;
    ConnectFour* m_game;
    QRect m_board_rect;
  public:
    RenderArea(QWidget* parent = 0, ConnectFour* game = 0);

  protected:
    void paintEvent(QPaintEvent* e) override;
    void mousePressEvent(QMouseEvent* event) override;

  private:
    void drawBoard(QPaintEvent* e, QPainter& painter);
    int get_column(int x);
};
