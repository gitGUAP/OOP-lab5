#pragma once

#include "shape.hpp"

class Circle : public Shape {
public:
	Circle(uint32_t x, uint32_t y, uint32_t radius) : _x(x), _y(y), _r(radius) {}

	void draw(Screen *screen) const {
		int x = 0;
		int y = _r;
		int delta = 1 - 2 * _r;
		int error = 0;
		while (y >= 0) {
			screen->putPoint(_x + x, _y + y);
			screen->putPoint(_x + x, _y - y);
			screen->putPoint(_x - x, _y + y);
			screen->putPoint(_x - x, _y - y);

			error = 2 * (delta + y) - 1;
			if (delta < 0 && error <= 0) {
				++x;
				delta += 2 * x + 1;
				continue;
			}
			error = 2 * (delta - x) - 1;
			if (delta > 0 && error > 0) {
				--y;
				delta += 1 - 2 * y;
				continue;
			}
			++x;
			delta += 2 * (x - y);
			--y;
		}
	}

	void move(Point p) {
		_x = _x + p.getX();
		_y = _y + p.getY();
	}

	Point getLeftTop() const { return Point(_x - _r, _y - _r); }

	Point getRightTop() const { return Point(_x + _r, _y - _r); }

	Point getLeftBottom() const { return Point(_x - _r, _y + _r); }

	Point getRightBottom() const { return Point(_x + _r, _y + _r); }

	~Circle() {}

protected:
	uint32_t _x, _y, _r;
};
