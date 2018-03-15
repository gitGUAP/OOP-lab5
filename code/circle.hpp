#pragma once

#include "shape.hpp"

class Circle : public virtual Shape {
public:
  Circle(uint32_t x, uint32_t y, uint32_t radius) : _x(x), _y(y), _r(radius) {}

  virtual void draw(Screen *screen) const {
    int y = 0;
    int x = _r;
    int delta = 1 - 2 * _r;
    int error = 0;
    while (x >= 0) {

      try {
        screen->putPoint(_y + y, _x + x);
      } catch (...) {
        std::cerr << Shape::getID() << ": Out of Range screen in " << getName()
                  << '\n';
      }
      try {
        screen->putPoint(_y + y, _x - x);
      } catch (...) {
        std::cerr << Shape::getID() << ": Out of Range screen in " << getName()
                  << '\n';
      }
      try {
        screen->putPoint(_y - y, _x + x);
      } catch (...) {
        std::cerr << Shape::getID() << ": Out of Range screen in " << getName()
                  << '\n';
      }
      try {
        screen->putPoint(_y - y, _x - x);
      } catch (...) {
        std::cerr << Shape::getID() << ": Out of Range screen in " << getName()
                  << '\n';
      }

      error = 2 * (delta + x) - 1;
      if (delta < 0 && error <= 0) {
        ++y;
        delta += 2 * y + 1;
        continue;
      }
      error = 2 * (delta - y) - 1;
      if (delta > 0 && error > 0) {
        --x;
        delta += 1 - 2 * x;
        continue;
      }
      ++y;
      delta += 2 * (y - x);
      --x;
    }
  }

  virtual void move(Point p) {
    _x = _x + p.getX();
    _y = _y + p.getY();
  }

  std::string getName() const { return "Circle"; }

  Point getLeftTop() const { return Point(_x - _r, _y - _r); }

  Point getRightTop() const { return Point(_x + _r, _y - _r); }

  Point getLeftBottom() const { return Point(_x - _r, _y + _r); }

  Point getRightBottom() const { return Point(_x + _r, _y + _r); }

  virtual ~Circle() {}

protected:
  uint32_t _x, _y, _r;
};
