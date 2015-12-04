#pragma once
#include <iostream>
#include "tablero.hpp"
#include "objeto.hpp"

using namespace std;

class personaje_t {
private:
	int life_;
	int x_;
	int y_;
	int inicio_x_;
	int inicio_y_;
	bool indicador_;
	bool pasillo_;
	int win_;
public:
	personaje_t(int n , int x, int y); //Donde n es igual al numero de vidas y X e Y son las coordenadas de inicio
	~personaje_t(void);
	void movimiento(tablero_t& t, objeto_t& o);
	ostream& write(ostream& os);
	int get_posicion(tablero_t& t);
	bool game_over(void);
	int get_life(void);
	bool get_win(void);
};
