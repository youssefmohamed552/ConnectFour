#include "canvas.hpp"

Canvas::
Canvas(QPaintDevice* device)
  : QPainter(device)
{
}


Canvas::
~Canvas(){
}
