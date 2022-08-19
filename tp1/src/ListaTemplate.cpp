#include "ListaTemplate.h"

template class ListaTemplate<Comando>;
template class ListaTemplate<Relato>;

template <class T>
ListaTemplate<T>::ListaTemplate() {
	primeiro = new TipoCelula<T>();
	ultimo = primeiro;
}

template <class T>
ListaTemplate<T>::~ListaTemplate()
{
	Limpa();
	delete primeiro;
}

template <class T>
void ListaTemplate<T>::InsereInicio(T &novoItem)
{
	TipoCelula<T> *nova;
	nova = new TipoCelula<T>();
	nova->item = novoItem;
	nova->prox = primeiro->prox;
	primeiro->prox = nova;
	tamanho++;
	if(nova->prox == NULL)
		ultimo = nova;
}

template <class T>
void ListaTemplate<T>::InsereFinal(T &novoItem)
{
	TipoCelula<T> *nova;
	nova = new TipoCelula<T>();
	nova->item = novoItem;
	ultimo->prox = nova;
	ultimo = nova;
	tamanho++;
}

template <class T>
T ListaTemplate<T>::RemoveInicio() {;
	T aux;
	TipoCelula<T> *p;
	if (tamanho == 0)
		throw "ERRO: Lista está vazia!";
	p = primeiro->prox;
	primeiro->prox = p->prox;
	tamanho--;
	if(primeiro->prox == NULL)
		ultimo = primeiro;
	aux = p->item;
	delete p;
	return aux;
}

template <class T>
void ListaTemplate<T>::Limpa() {
	TipoCelula<T> *p;
	p = primeiro->prox;
	while (p!=NULL) {
		primeiro->prox = p->prox;
		delete p;
		p = primeiro->prox;
	}
	ultimo = primeiro;
	tamanho = 0;
}

template <class T>
void ListaTemplate<T>::Imprime() {
	TipoCelula<T> *p;
	p = primeiro->prox;
	while (p!=NULL) {
		p->item.Imprime();
		p = p->prox;
	}
}

template <class T>
bool ListaTemplate<T>::Vazia()
{
	return(tamanho == 0);
}