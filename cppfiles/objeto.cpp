#include "objeto.hpp"
#include <iostream>

objeto_t::objeto_t(int x, int y):
x_(x),
y_(y),
obtenido_(false)
{}

objeto_t::~objeto_t(void){}

bool& objeto_t::get_obtenido(void)
{
	return obtenido_;
}

void objeto_t::crea(tablero_t& t)
{
	t.espacio(t.get_pos(y_,x_)) = '&';
}

int objeto_t::get_x(void)
{
	return x_;
}

int objeto_t::get_y(void)
{
	return y_;
}
