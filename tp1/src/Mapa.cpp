#include "Mapa.h"
#include <iostream>
using namespace std;

Mapa::Mapa() 
{
	coluna = 0;
	linha = 0;
}

Mapa::~Mapa()
{
	if(coluna > 0 && linha > 0)
	{
		for (int i = 0; i < linha; i++)
		delete[] mapa[i];
		delete[] mapa;
	}
}

void Mapa::setMapa(int l, int c)
{ 
	coluna = c; linha = l;
	mapa = new char*[linha];
	for (int i = 0; i < linha; i++)
	    mapa[i] = new char[coluna];
}

int Mapa::getColuna()
{
	return coluna;
}

int Mapa::getLinha()
{
	return linha;
}

void Mapa::Imprime()
{
	for(int i = 0; i < linha; i++)
	{
		for(int j = 0; j < coluna; j++)
		{
			cout << mapa[i][j] << " ";
		}
		cout << endl;
	}
}

void Mapa::modificarMapa(int x, int y, char c)
{
	mapa[x][y] = c;
}

char Mapa::getMapaPosicao(int x, int y)
{
	return mapa[x][y];
}