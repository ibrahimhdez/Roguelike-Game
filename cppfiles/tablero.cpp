#include "tablero.hpp"

#include <iostream>

using namespace std;

tablero_t::tablero_t(int i, int j):
x_(i),
y_(j)
{
	espacio_ = new char[x_*y_];
}

tablero_t::~tablero_t(void)
{
	if(espacio_!=NULL)
	{
		delete[] espacio_;
		espacio_ = NULL;
		x_ = 0;
		y_ = 0;
	}
}

char& tablero_t::espacio(int i)
{
	return espacio_[i];
}

int tablero_t::get_pos(int i, int j)
{
	return (i*x_+j);
}

int tablero_t::get_x(void)
{
	return x_;
}

int tablero_t::get_y(void)
{
	return y_;
}
