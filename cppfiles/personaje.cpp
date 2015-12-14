#include "personaje.hpp"

#include <iostream>
#include <cstdio>

using namespace std;

personaje_t::personaje_t(int n, int x, int y):
life_(n),
x_(x),
y_(y),
inicio_x_(x),
inicio_y_(y),
win_(1),
pasillo_(false),
indicador_(false)
{}

personaje_t::~personaje_t(void){}

void personaje_t::movimiento(tablero_t& t, objeto_t& o)
{
  	system("stty raw"); 
  	
  	char input = getchar(); 
	int anterior_x=0, anterior_y=0;

	anterior_x = x_;
	anterior_y = y_;

	switch(input)
	{
		case 'i': y_--;break;
		case 'k': y_++;break;
		case 'j': x_--;break;
		case 'l': x_++;break;
		case 'q': exit(0);break;
 	}

 	system("stty cooked"); 

 	if(o.get_obtenido()) //Cuando tienes el amuleto el punto de reencarnación cambia a donde antiguamenete estaba el amuleto
 	{
 		inicio_x_ = o.get_x();
 		inicio_y_ = o.get_y();
 		t.espacio(t.get_pos(inicio_y_,inicio_x_)) = 'X';
 	}

 	if(t.espacio(t.get_pos(y_,x_))=='*') //Impide que el personaje atraviese las paredes de las mazmorras
 	{
 		t.espacio(t.get_pos(anterior_y,anterior_x)) = '@';
 		y_ = anterior_y;
 		x_ = anterior_x;
 	}

 	else if(t.espacio(t.get_pos(y_,x_))=='+') //Permite que el personaje camine por los pasillos
 	{
 		if(indicador_==false) //Condicion para que se impriman los pasillos si están fuera de las mazmorras y para que no si están dentro
 			pasillo_= false;
 		else
 			pasillo_ = true;

 		t.espacio(t.get_pos(y_,x_))='@';
 		if((t.espacio(t.get_pos(anterior_y,anterior_x-1))=='#')||(t.espacio(t.get_pos(anterior_y-1,anterior_x))=='#')||(t.espacio(t.get_pos(anterior_y,anterior_x+1))=='#')||(t.espacio(t.get_pos(anterior_y+1,anterior_x))=='#'))
 			t.espacio(t.get_pos(anterior_y,anterior_x))= '#'; //Para cuando salga del pasillo el último elemnento se imprima
 		else
 			t.espacio(t.get_pos(anterior_y,anterior_x))= ' ';
 		indicador_ = true;
 	}

 	else if(t.espacio(t.get_pos(y_,x_))=='#') //Código para permitir caminar por los pasillos
 	{
 		pasillo_ = true;
 		if(indicador_==true)
 		{
 			t.espacio(t.get_pos(y_,x_)) = '@';
 			t.espacio(t.get_pos(anterior_y,anterior_x))= '+';
 			indicador_ = false;
 		}
 		else
 		{
 			t.espacio(t.get_pos(y_,x_)) = '@';
 			t.espacio(t.get_pos(anterior_y,anterior_x))= '#';
 		}
 		if((t.espacio(t.get_pos(y_,x_))==' ')&&(pasillo_==true))
 		{
 			t.espacio(t.get_pos(anterior_y,anterior_x))= '@';
 		}

 	}

 	else if((t.espacio(t.get_pos(y_,x_))==' ')&&(indicador_==true))
 	{
 		t.espacio(t.get_pos(anterior_y,anterior_x))= '+';
 		t.espacio(t.get_pos(y_,x_)) = '@';
 		indicador_ = false;
 	}

 	else if((t.espacio(t.get_pos(y_,x_))==' ')&&(pasillo_==true))
 	{
 		t.espacio(t.get_pos(anterior_y,anterior_x))= '#';
 		t.espacio(t.get_pos(y_,x_)) = '@';

 	}

 	else if(t.espacio(t.get_pos(y_,x_))=='O')
 	{
 		life_--;
 		x_ = inicio_x_;
 		y_ = inicio_y_;
 		t.espacio(t.get_pos(anterior_y,anterior_x))= ' ';
 		if(life_>0)
 			cout << "Has perdido una vida";
 		else
 			cout << "HAS PERDIDO";
 	}

 	else if(t.espacio(t.get_pos(y_,x_))=='&')
 	{
 		t.espacio(t.get_pos(y_,x_)) = '@';
 		o.get_obtenido() = true;
 		t.espacio(t.get_pos(anterior_y,anterior_x)) = ' ';
 	}

 	else if((t.espacio(t.get_pos(y_,x_))=='X')&&(o.get_obtenido() = true))
 	{
 		cout << "HAS GANADO";
 		win_ = 0;
 	}

 	else
 	{
		t.espacio(t.get_pos(y_,x_)) = '@';
		if(t.espacio(t.get_pos(anterior_y,anterior_x))!='X')
			t.espacio(t.get_pos(anterior_y,anterior_x)) = ' ';
	}
}

int personaje_t::get_posicion(tablero_t& t)
{
	return(t.get_pos(x_,y_));
}

bool personaje_t::game_over(void)
{
	return life_==0;
}

int personaje_t::get_life(void)
{
	return life_;
}

bool personaje_t::get_win(void)
{
	return win_==0;
}
