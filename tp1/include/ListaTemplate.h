#include "TipoCelula.h"
#include <iostream>
using namespace std;

template<typename T> class TipoCelula; 

template <typename T> class ListaTemplate {
	public:
		ListaTemplate();
		~ListaTemplate();

		void InsereInicio(T &NovoItem);
		void InsereFinal(T &NovoItem);
		T RemoveInicio();
		void Imprime();
		void Limpa();
		bool Vazia();

	private:
		TipoCelula<T>* primeiro;
		TipoCelula<T>* ultimo;
		int tamanho = 0;
};
