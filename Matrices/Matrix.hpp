#pragma once
#include <iostream>



class Matrix
{
private:
	int width, height;
	double *data;

public:
	Matrix();
	Matrix(int w, int h);
	Matrix(const Matrix &m);
	Matrix(Matrix &&m);
	~Matrix();

	void Resize(int w, int h);

	int Width() const;
	int Height() const;
	double Get(int x, int y) const;
	void Set(int x, int y, double v);

	Matrix &operator=(const Matrix &m);
	Matrix operator*(const Matrix &m) const;

	friend std::ostream &operator<<(std::ostream &os, const Matrix &m);
	friend std::istream &operator>>(std::istream &is, Matrix &m);
};
