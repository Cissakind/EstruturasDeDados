#include "TipoNo.h"

class ArvoreBinaria
{
	public:
	ArvoreBinaria();
	~ArvoreBinaria();
	void Insere(TipoItem item);
	void Limpa();
	TipoNo* getRaiz();

	private:
	void InsereRecursivo(TipoNo* &p, TipoItem item);
	void ApagaRecursivo(TipoNo* p);
	TipoNo *raiz;

};