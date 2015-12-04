#include "tablero.hpp"
#include "mazmorra.hpp"
#include "pasillo.hpp"
#include "personaje.hpp"
#include "monstruo.hpp"
#include "objeto.hpp"

#include <iostream>
#include <cstdlib>

#define X 25
#define Y 10

using namespace std;

int main(void)
{
	//Mazmorra 1: x_*y_
	//Mazmorra 2: (x_+pasillo)*y_
	//Mazmorra 3: (x_+pasillo)*(y_+pasillo2)

	tablero_t tablero(100,50);
	mazmorra_t mazmorra(X,Y);
	pasillo_t pasillo(35);
	pasillo_t pasillo2(15);
	personaje_t personaje(5,4,4);

	int i = rand() % mazmorra.get_x() -1, j = rand() % mazmorra.get_y()-1, o = rand() % mazmorra.get_x()-1, p = rand() % mazmorra.get_y()-1, q = rand() % mazmorra.get_x()-1, r = rand() % mazmorra.get_y()-1;
	int a = rand() % (mazmorra.get_x()-1) + mazmorra.get_x()+pasillo.get_long()+1, b = rand() % (mazmorra.get_x()-1) + mazmorra.get_x()+pasillo.get_long()+1, c = (rand() % (mazmorra.get_x()-1) + mazmorra.get_x()+pasillo.get_long()+1);
	int d = rand() % mazmorra.get_y() + mazmorra.get_x(), e = rand() % mazmorra.get_y() + mazmorra.get_x(), f = rand() % mazmorra.get_y() + mazmorra.get_x();

	monstruo_t monstruo_1(i,j,tablero);
	monstruo_t monstruo_2(o,p,tablero);
	monstruo_t monstruo_3(q,r,tablero); 
	monstruo_t monstruo_4(a,j,tablero); 
	monstruo_t monstruo_5(b,p,tablero);
	monstruo_t monstruo_6(c,r,tablero);
	monstruo_t monstruo_7(a,d,tablero);
	monstruo_t monstruo_8(b,e,tablero);
	monstruo_t monstruo_9(c,f,tablero);
	objeto_t objeto(a,f);

	objeto.crea(tablero);
	mazmorra.crea(pasillo,pasillo2,tablero,personaje);
	mazmorra.write(cout,tablero,objeto,personaje);

	while((!personaje.get_win())&&(!personaje.game_over()))
	{
		monstruo_1.movimiento(tablero);
		monstruo_2.movimiento(tablero);
		monstruo_3.movimiento(tablero);
		monstruo_4.movimiento(tablero);
		monstruo_5.movimiento(tablero);
		monstruo_6.movimiento(tablero);
		monstruo_7.movimiento(tablero);
		monstruo_8.movimiento(tablero);
		monstruo_9.movimiento(tablero);
		personaje.movimiento(tablero,objeto);
		system("clear");
		mazmorra.write(cout,tablero,objeto,personaje);
	}

	cout << endl;
}
