#include "Base.h"

void Base::setNome(string novoNome)
{
	nome = novoNome;
}

void Base::setDist(int novaDist)
{
	dist = novaDist;
}

string Base::getNome()
{
	return nome;
}

int Base::getDist()
{
	return dist;
}