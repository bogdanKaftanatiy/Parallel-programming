#pragma warning(disable:4996)

#include <string>

using namespace std;

class Vector {
private:
	int _size;
	int* _data;

public:
	Vector(int size, bool fill);

	~Vector();

	Vector* operator+(Vector &that);

	Vector* sort();

	void setElement(int index, int value);

	void print();

	int operator*(Vector &that);

	int getElement(int index);

	int max();

	string getString();
};

class Matrix {
private:
	int _size;
	int** _data;

public:
	Matrix(int size, bool fill);

	~Matrix();

	Matrix* operator*(Matrix &that);

	Matrix* operator*(int number);

	Vector* operator*(Vector &vector);

	Matrix* sort();

	Matrix* transpose();

	void print();

	int getMaxElement();

	int get(int i, int j);

	int getDimension();

	string getString();
};