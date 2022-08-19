#include "TipoNo.h"

class ArvoreBinaria
{
	public:
	ArvoreBinaria();
	~ArvoreBinaria();
	void Insere(Base base);
	void Limpa();

	private:
	void InsereRecursivo(TipoNo* &p, Base base);
	void ApagaRecursivo(TipoNo* p);
	void arvoreEmOrdem(Base *baseLista, TipoNo *&p, int &i);
	
	TipoNo *raiz;	
	friend class Sort;
};