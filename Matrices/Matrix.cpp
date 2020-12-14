#include "Matrix.hpp"
#include <iomanip>



Matrix::Matrix()
{
	data = nullptr;
	width = 0; 
	height = 0;
}
Matrix::Matrix(int w, int h)
{
	data = new double[w * h];
	width = w;
	height = h;
}
Matrix::Matrix(const Matrix &m)
{
	data = new double[m.width * m.height];
	width = m.width;
	height = m.height;
	for (int i = 0; i < width * height; i++)
		data[i] = m.data[i];
}
Matrix::Matrix(Matrix &&m)
{
	data = m.data;
	width = m.width;
	height = m.height;
	m.data = nullptr;
	m.width = 0;
	m.height = 0;
}
Matrix::~Matrix()
{
	delete data;
	data = nullptr;
	width = 0;
	height = 0;
}

void Matrix::Resize(int w, int h)
{
	delete[] data;
	data = new double[w * h];
	width = w;
	height = h;
}

int Matrix::Width() const
{
	return width;
}
int Matrix::Height() const
{
	return height;
}
double Matrix::Get(int x, int y) const
{
	return data[y * width + x];
}
void Matrix::Set(int x, int y, double v) 
{
	data[y * width + x] = v;
}

Matrix &Matrix::operator=(const Matrix &m)
{
	delete[] data;
	data = new double[m.width * m.height];
	width = m.width;
	height = m.height;
	for (int i = 0; i < width * height; i++)
		data[i] = m.data[i];
	return *this;
}
Matrix Matrix::operator*(const Matrix &m) const
{
	Matrix res(m.width, height);

	for (int x = 0; x < m.width; x++)
	{
		for (int y = 0; y < height; y++)
		{
			res.Set(x, y, 0);
			for (int k = 0; k < width; k++)
			{
				res.Set(x, y, res.Get(x, y) + Get(k, y) * m.Get(x, k));
			}
		}
	}

	return res;
}

std::ostream &operator<<(std::ostream &os, const Matrix &m)
{
	for (int y = 0; y < m.height; y++)
	{
		for (int x = 0; x < m.width; x++)
		{
			os << std::left << std::setprecision(2) << std::setw(5) << m.Get(x, y) << " ";
		}
		os << '\n';
	}
	return os;
}
std::istream &operator>>(std::istream &is, Matrix &m)
{
	int w, h;
	if (is >> w && is >> h)
	{
		m.Resize(w, h);

		for (int y = 0; y < m.height; y++)
		{
			for (int x = 0; x < m.width; x++)
			{
				double v;
				is >> v;
				m.Set(x, y, v);
			}
		}
	}

	return is;
}
