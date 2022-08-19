#include "TipoCelula.h"

template class TipoCelula<Comando>;
template class TipoCelula<Relato>;

template <class T>
TipoCelula<T>::TipoCelula()
{
	prox = NULL;
}

template <class T>
void TipoCelula<T>::setItem(T novoItem)
{
	this->item = novoItem;
}