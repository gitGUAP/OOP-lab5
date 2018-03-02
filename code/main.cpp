#include <iostream>
#include "Vector.h"

using namespace std;

int main() {
	Vector vecl(2);
	vecl[0] = 1;
	vecl[1] = 2;

	Vector vecr(3, 5);
	vecr[3] = 5;
	vecr[4] = 7;
	// vecr[5] = 5; // out of range

	cout << "vecl: "; vecl.print();
	cout << "vecr: "; vecr.print();
	cout << "vecl len: " << vecl.getLen() << endl;

	Vector sum = vecl + vecr;
	//sum = vecl + vec3; // different length
	cout << "sum: "; sum.print();

	Vector subtraction = vecr - vecl;
	cout << "subtraction: "; subtraction.print();

	Vector multipl = vecr * 4;
	cout << "multipl: "; multipl.print();

	Vector division = multipl / 2;
	cout << "division: "; division.print();

	cout << "vecl < vecr: "; cout << (vecl < vecr) << endl;


	system("pause");
	return 0;
}