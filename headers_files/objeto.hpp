#pragma once

#include "tablero.hpp"

#include <iostream>

using namespace std;

class objeto_t{

private:
	int x_;
	int y_;
	bool obtenido_;
public:
	objeto_t(int x, int y);
	~objeto_t(void);
	bool& get_obtenido(void);
	void crea(tablero_t& t);
	int get_x(void);
	int get_y(void);

};
