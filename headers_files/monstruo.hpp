#pragma once
#include "tablero.hpp"
#include "mazmorra.hpp"

#include <iostream>

using namespace std;

class monstruo_t{

private:
	int x_;
	int y_;
public:
	monstruo_t(int x, int y, tablero_t& t);
	~monstruo_t(void);
	void movimiento(tablero_t& t);
};
