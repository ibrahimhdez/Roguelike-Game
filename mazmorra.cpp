#include "mazmorra.hpp"
#include <iostream>
#include <string>

using namespace std;

mazmorra_t::mazmorra_t(int i, int j):
x_(i),
y_(j)
{}

mazmorra_t::~mazmorra_t(void){}

void mazmorra_t::crea(pasillo_t& p, pasillo_t& p2, tablero_t& t, personaje_t& pers)
{
	int pasillo = p.get_long();
	int pasillo2 = p2.get_long();

	t.espacio(pers.get_posicion(t)) = 'X';

	for(int y=0; y<t.get_y(); y++)
		for(int x=0; x<t.get_x(); x++)
		{
			if((y==0)&&(x==0))//Crea primera línea horizontal de la primera mazmorra
				for(int i=0; i<x_; i++)	
					t.espacio(t.get_pos(y,i+x)) = '*';
			if((y==0)&&(x==x_+pasillo)) //Crea primera línea horizontal de la segunda mazmorra
				for(int i=x_+pasillo; i<(x_*2)+pasillo+1; i++)
					t.espacio(t.get_pos(y,i)) = '*';
			else if(t.espacio(t.get_pos(y,x))!= '*')
			if((y>0)&&(y<y_-1)&&(x==0)) //Crea primera línea vertical de la primera mazmorra
				t.espacio(t.get_pos(y,x)) = '*';
			if((x==x_-1)&&(y>0)&&(y<y_-1)) //Crea segunda línea vertical de la primera mazmorra
			{
				if(y==(y_-1)/2) //Crea el caracter + para el pasillo
				{
					t.espacio(t.get_pos(y,x)) = '+';
					t.espacio(t.get_pos(y,x_)) = '#';
				}
				else
					t.espacio(t.get_pos(y,x)) = '*';
			}

			if((y>0)&&(y<y_-1)&&(x==x_+pasillo)) //Crea primera linea vertical segunda mazmorra
			{
				if(y==(y_-1)/2) //Crea el caracter + para el pasillo
				{
					t.espacio(t.get_pos(y,x)) = '+';
					t.espacio(t.get_pos(y,x-1)) = '#';
				}
				else
				t.espacio(t.get_pos(y,x)) = '*';
			}

			if((y>0)&&(y<y_-1)&&(x==x_*2+pasillo)) //Crea segunda linea vertical segunda mazmorra
				t.espacio(t.get_pos(y,x)) = '*';

			if((y==y_-1)&&(x==0)) //Crea la segunda linea horizontal de la primera mazmorra
				for(int i=0; i<x_; i++)
					t.espacio(t.get_pos(y,x+i)) = '*';

			if((y==y_-1)&&(x==x_+pasillo)) //Crea la segunda linea horizontal de la segunda mazmorra
				for(int i=x_+pasillo; i<x_*2+pasillo+1; i++)
				{
					if(i==(x_+pasillo)+(x_)/2) //Crea el caracter + para el pasillo de la segunda mazmorra a la tercera
					{
						t.espacio(t.get_pos(y,i)) = '+';
						t.espacio(t.get_pos(y_,y+pasillo+y+y+y+1)) = '#';
					}
					else
						t.espacio(t.get_pos(y,i)) = '*';
				}

			if((y==(y_+pasillo2-1))&&(x==x_+pasillo)) //Crea la primera linea horizontal de la tercera mazmorra
				for(int i=x_+pasillo; i<(x_*2)+pasillo+1; i++)
				{
					if(i==(x_+pasillo)+(x_)/2) //Crea el caracter + para el pasillo de la tercera mazmorra
					{
						t.espacio(t.get_pos(y,i)) = '+';
						t.espacio(t.get_pos(y-1,i)) = '#';
					}
					else
						t.espacio(t.get_pos(y,i)) = '*';
				
				}

			if((y>y_+pasillo2-1)&&(y<y_+pasillo2+y_)&&(x==x_+pasillo)) //Crea primera fila vertical de la tercera mazmorra
				t.espacio(t.get_pos(y,x)) = '*';

			if((y>y_+pasillo2-1)&&(y<y_+pasillo2+y_)&&(x==x_+pasillo+x_)) //Crea la segunda fila vertical de la tercera mazmmorra
				t.espacio(t.get_pos(y,x)) = '*';

			if((y==(y_+pasillo2+y_))&&(x==x_+pasillo)) //Crea la segunda linea horizontal de la tercera mazmorra
				for(int i=x_+pasillo; i<(x_*2)+pasillo+1; i++)
					t.espacio(t.get_pos(y,i)) = '*';


			if((t.espacio(t.get_pos(y,x))!='*')&&(t.espacio(t.get_pos(y,x))!='+')&&(t.espacio(t.get_pos(y,x))!='#')&&(t.espacio(t.get_pos(y,x))!='X')&&(t.espacio(t.get_pos(y,x))!='O')&&(t.espacio(t.get_pos(y,x))!='&'))
				t.espacio(t.get_pos(y,x)) = ' ';
		}
}

ostream& mazmorra_t::write(ostream& os, tablero_t& t, objeto_t& o, personaje_t& p)
{
	os << endl << endl << endl << endl;

	for(int y=0; y<t.get_y(); y++)
	{
		for(int x=0; x<t.get_x(); x++)
		{
			if(t.espacio(t.get_pos(y,x))!=' ')
			{
				if(t.espacio(t.get_pos(y,x))=='@')
					os << "\033[1;94m@\033[0m";
				else if(t.espacio(t.get_pos(y,x))=='O')
					os << "\033[1;96mO\033[0m";
				else if(t.espacio(t.get_pos(y,x))=='&')
					os << "\033[1;93m&\033[0m";
				else
					os << t.espacio(t.get_pos(y,x));
			}
			else os << " ";
		} 
		os << endl;
	}

	os << "Vidas: ";
	for(int i=0; i<p.get_life(); i++)
		os << "\033[1;91m♥ \033[0m";
	os << "              " << "Amuleto: ";
	if(o.get_obtenido())
		os << "Sí";
	else
		cout << "No";
	for(int i=0 ; i<50; i++)
		os << " ";
} 

int mazmorra_t::get_x(void)
{
	return x_;
}

int mazmorra_t::get_y(void)
{
	return y_;
}
