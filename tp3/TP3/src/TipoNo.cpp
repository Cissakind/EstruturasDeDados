#include "TipoNo.h"
#include <iostream>

TipoNo::TipoNo()
{
	item.SetChave('.');
	esq = NULL;
	dir = NULL;
}

TipoNo* TipoNo::getDir()
{
	return dir;
}

TipoNo* TipoNo::getEsq()
{
	return esq;
}


TipoItem TipoNo::getItem()
{
	return item;
}