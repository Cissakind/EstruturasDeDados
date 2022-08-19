#include "Relato.h"
#include "Comando.h"
#include <iostream>

template<typename T> class ListaTemplate;

template <typename T> class TipoCelula
{
	public:
		TipoCelula();
		void setItem(T novoItem);
	private:
		T item;
		TipoCelula<T> *prox;

	friend class ListaTemplate<T>;
};
