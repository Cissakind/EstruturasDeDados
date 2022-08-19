#include "TipoItem.h"

#include <iostream>
using namespace std;

class TipoNo
{
	public:
	TipoNo();
	TipoNo* getDir();
	TipoNo* getEsq();
	TipoItem getItem();


	private:
	TipoItem item;
	TipoNo *esq;
	TipoNo *dir;
	friend class ArvoreBinaria;
};