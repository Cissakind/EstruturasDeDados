#include "ArvoreBinaria.h"

class Sort {
	private:
		static void Ordena(int Esq, int Dir, Base *listaBase);
		static void Particao(int Esq, int Dir, int *i, int *j, Base *listaBase);
		static void Refaz(int Esq, int Dir, Base *baseLista);
		static void Constroi(Base *baseLista, int n);
		static void Insercao_Quicksort(int Esq, int Dir, Base *listaBase);
		static void Ordena_Insercao(int Esq, int Dir, Base *listaBase);

	public:
		static void Insercao(Base *listaBase, int n);
		static void QuickSort(Base *listaBase, int n);
		static void QuickSort_Modificado(Base *listaBase, int n);
		static void Heapsort(Base *baseLista, int n);
		static void TreeSort(Base *baseLista, int n);
};

