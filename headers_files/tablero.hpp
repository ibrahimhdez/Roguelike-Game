#pragma once

#include <iostream>

using namespace std;

class tablero_t{

private:
	int x_;
	int y_;
	char* espacio_;

public:
	tablero_t(int i, int j);
	~tablero_t(void);
	char& espacio(int i);
	int get_pos(int i, int j);
	int get_x(void);
	int get_y(void);
};
