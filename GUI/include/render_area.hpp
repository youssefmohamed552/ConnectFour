#pragma once

#include <QtWidgets>
#include <QtGui>

class RenderArea: public QWidget{
  private:
    int m_width;
    int m_height;
  public:
    RenderArea(QWidget* parent = 0);

  protected:
    void paintEvent(QPaintEvent* e) override;

  private:
    void drawBoard(QPaintEvent* e, QPainter& painter);
};
