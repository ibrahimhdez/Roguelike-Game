#pragma once

#include "tablero.hpp"

#include <iostream>

class pasillo_t{

private:
	int long_;
public:
	pasillo_t(int i);
	~pasillo_t(void);
	void crea(tablero_t&, int i, int j);
	int get_long(void);
};

