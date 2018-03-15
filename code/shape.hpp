#pragma once

#include "screen.hpp"
#include <string>

class Shape {
public:
  static int idIdx;

  Shape() { id = idIdx++; }

  virtual void draw(Screen *screen) const = 0;

  virtual void move(Point p) = 0;

  virtual Point getLeftTop() const = 0;

  virtual std::string getName() const = 0;

  virtual Point getRightTop() const = 0;

  virtual Point getLeftBottom() const = 0;

  virtual Point getRightBottom() const = 0;

  int getID() const { return id; };

  virtual ~Shape() {}

private:
  int id;
};

int Shape::idIdx = 0;
