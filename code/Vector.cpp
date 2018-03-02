#include "Vector.h"

Vector::Vector(int l) : Vector(0, l) {}

Vector::Vector(int st, int ed) {
	start = std::make_unique<int>(st);
	end = std::make_unique<int>(ed);
	len = std::make_unique<int>(ed - st);
	arr = std::make_unique<int[]>(*len);
}

int &Vector::operator[](int i) {
	if (i < *start || i >= *end) {
		std::cout << std::endl << "Wrong index of vector: " << i << std::endl;
		system("pause");
		exit(1);
	}

	return arr[i - *start];
}

Vector Vector::operator+(const Vector &rv) {
	if (*len != *rv.len) {
		std::cout << std::endl << "Different length of vectors." << std::endl;
		system("pause");
		exit(1);
	}

	Vector out(*len);
	for (int i = 0; i < *len; i++) {
		out.arr[i] = arr[i] + rv.arr[i];
	}
	return out;
}

bool Vector::operator<(const Vector  &rv) {
	if (*len < *rv.len) {
		return true;
	}

	return false;
}

Vector Vector::operator-(const Vector &rv) {
	if (*len != *rv.len) {
		std::cout << std::endl << "Different length of vectors." << std::endl;
		system("pause");
		exit(1);
	}

	Vector out(*len);
	for (int i = 0; i < *len; i++) {
		out.arr[i] = arr[i] - rv.arr[i];
	}
	return out;
}

Vector Vector::operator*(const int m) {
	Vector out(*len);
	for (int i = 0; i < *len; i++) {
		out.arr[i] = arr[i] * m;
	}
	return out;
}

Vector Vector::operator/(const int m) {
	if (m == 0) {
		std::cout << std::endl << "Division by zero." << std::endl;
		system("pause");
		exit(1);
	}

	Vector out(*len);
	for (int i = 0; i < *len; i++) {
		out.arr[i] = arr[i] / m;
	}
	return out;
}

Vector::Vector(Vector const &obj) {
	start = std::make_unique<int>(*obj.start);
	end = std::make_unique<int>(*obj.end);
	len = std::make_unique<int>(*obj.len);

	arr = std::make_unique<int[]>(*len);

	memcpy(arr.get(), obj.arr.get(), sizeof(int) * *len);
}

int Vector::getLen() { return *len; }

void Vector::print() {
	std::cout << "[";
	for (int i = 0; i < *len; i++) {
		if (i != 0)
			std::cout << ", ";

		std::cout << arr[i];
	}
	std::cout << "]" << std::endl;
}
