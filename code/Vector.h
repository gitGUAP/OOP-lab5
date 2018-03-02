#pragma once

#include <iostream>
#include <memory>

class Vector {
public:
	Vector(int l);
	Vector(int st, int ed);

	int &operator[](int i);
	Vector operator+(const Vector &rv);
	bool operator<(const Vector &rhs);
	Vector operator-(const Vector &rv);
	Vector operator*(int i);
	Vector operator/(const int m);

	Vector(Vector const &);

	int getLen();
	void print();

private:
	std::unique_ptr<int[]> arr;
	std::unique_ptr<int> start, end, len;
};
