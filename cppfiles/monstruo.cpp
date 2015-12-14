#include "monstruo.hpp"
#include <iostream>

using namespace std;

monstruo_t::monstruo_t(int x, int y, tablero_t& t):
x_(x),
y_(y)
{
	t.espacio(t.get_pos(y_,x_)) = 'O';
}

monstruo_t::~monstruo_t(void){}

void monstruo_t::movimiento(tablero_t& t)
{
	int i = rand() % 8;

	int anterior_x = x_, anterior_y = y_;
	
	switch(i)
	{
		case 0: break;
		case 1: y_--;break;
		case 2: y_--;x_++;break;
		case 3: x_++;break;
		case 4:	x_++;y_++;break;
		case 5: y_++;break;
		case 6: y_++;x_--;break;
		case 7: x_--;break;
		case 8: x_--;y_--;break;
	}

    if((t.espacio(t.get_pos(y_,x_))=='*')||(t.espacio(t.get_pos(y_,x_))=='O')||(t.espacio(t.get_pos(y_,x_))=='&')||(t.espacio(t.get_pos(y_,x_))=='X')||(t.espacio(t.get_pos(y_,x_))=='@')||(t.espacio(t.get_pos(y_,x_))=='+'))
	{
		t.espacio(t.get_pos(anterior_y,anterior_x)) = 'O';
		x_ = anterior_x;
		y_ = anterior_y;
	}
	else
	{
		t.espacio(t.get_pos(y_,x_)) = 'O';
		t.espacio(t.get_pos(anterior_y,anterior_x)) = ' ';
	}
}
