#pragma once

#include "tablero.hpp"
#include "pasillo.hpp"
#include "personaje.hpp"
#include "objeto.hpp"

#include <iostream>

using namespace std;

class mazmorra_t{

private:
	int x_;
	int y_;
public:
	mazmorra_t(int i, int j);
	~mazmorra_t(void);
	ostream& write(ostream& os, tablero_t& t, objeto_t& o, personaje_t& p);
	void crea(pasillo_t& p, pasillo_t& p2, tablero_t& t, personaje_t& pers);
	int get_x(void);
	int get_y(void);
	int get_inicio(void);
	void game_over(void);
};
