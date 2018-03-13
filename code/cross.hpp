#pragma once

#include "line.hpp"
#include "shape.hpp"

//�����
class Cross : public virtual Shape {
public:
  Cross(const Point &left, const Point &top) {
    Point p1, p2;
    Point p3, p4;

    p1 = left;
    p2 = Point(top.getX() + top.getX() - left.getX(), left.getY());
    p3 = top;
    p4 = Point(top.getX(), left.getY() - top.getY() + left.getY());

    _first = new Line(p1, p2);
    _second = new Line(p3, p4);
  }

  virtual void draw(Screen *screen) const {
    _first->draw(screen);
    _second->draw(screen);
  }

  virtual void move(Point p) {
    _first->move(p);
    _second->move(p);
  }

  Point getLeftTop() const { return _first->getLeftTop(); }

  Point getRightTop() const { return _second->getRightTop(); }

  Point getLeftBottom() const { return _second->getLeftBottom(); }

  Point getRightBottom() const { return _first->getRightBottom(); }

  virtual ~Cross() {
    delete _first;
    delete _second;
  }

protected:
  Line *_first;
  Line *_second;
};
