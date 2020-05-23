#pragma once

#include <QtGui>

class Canvas: public QPainter{
  public:
    Canvas(QPaintDevice* device);
    virtual ~Canvas();
}
