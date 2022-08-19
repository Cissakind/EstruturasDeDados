#include "Base.h"

class TipoNo
{
	public:
		TipoNo();
	private:

	Base base;
	TipoNo *esq;
	TipoNo *dir;
	friend class ArvoreBinaria;
};