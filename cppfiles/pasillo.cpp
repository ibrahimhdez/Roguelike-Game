#include "pasillo.hpp"

#include <iostream>

using namespace std;

pasillo_t::pasillo_t(int i):
long_(i)
{}

pasillo_t::~pasillo_t(void)
{}

void pasillo_t::crea(tablero_t& t, int i, int j)
{

}

int pasillo_t::get_long(void)
{
	return long_;
}
