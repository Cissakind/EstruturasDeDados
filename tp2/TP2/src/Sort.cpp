#include "Sort.h"

// INSERÇÃO
void Sort::Insercao(Base *listaBase, int n) 
{
	int i,j;
	Base aux;
	for (i = 1; i < n; i++) 
	{
		aux = listaBase[i];
		j = i - 1;

		while (( j >= 0 ) && (aux.getDist() < listaBase[j].getDist())) 
		{
			listaBase[j + 1] = listaBase[j];
			j--;
		}
		listaBase[j + 1] = aux;
	}
}

// QUICKSORT
void Sort::QuickSort(Base *listaBase, int n)
{
	Ordena(0, n-1, listaBase);
}

void Sort::Ordena(int Esq, int Dir, Base *listaBase) 
{
	int i= Esq;
	int j= Dir;

	Particao(Esq, Dir, &i, &j, listaBase);
	if (Esq < j) 
		Ordena(Esq, j, listaBase);
	if (i < Dir) 
		Ordena(i, Dir, listaBase);
}

void Sort::Particao(int Esq, int Dir, int *i, int *j, Base *listaBase) 
{
	Base x, w;
	*i = Esq;
	*j = Dir;

	x = listaBase[(*i + *j)/2]; 
	do
	{
		while (x.getDist() > listaBase[*i].getDist()) 
			(*i)++;

		while (x.getDist() < listaBase[*j].getDist()) 
			(*j)--;

		if (*i <= *j)
		{
			w = listaBase[*i]; 
			listaBase[*i] = listaBase[*j]; 
			listaBase[*j] = w;
			(*i)++; (*j)--;
		}

	} while (*i <= *j);
}

// HEAPSORT
void Sort::Heapsort(Base *baseLista, int n) 
{
	int Esq, Dir;
	Base x;
	Constroi(baseLista, n); 
	Esq = 1; Dir = n;

	while (Dir > 1)
	{ 
		x = baseLista[0];
		baseLista[0] = baseLista[Dir-1];
		baseLista[Dir-1] = x;
		Dir--;
		Refaz(Esq-1, Dir-1, baseLista);
	}
}

void Sort::Constroi(Base *baseLista, int n)
{
	int Esq;
	Esq = n/2 + 1;

	while (Esq > 1) 
	{
		Esq--;
		Refaz(Esq-1, n-1, baseLista);
	}
}

void Sort::Refaz(int Esq, int Dir, Base *baseLista)
{
	int i, j;
	Base x;
	i = Esq;
	j = i * 2;
	x = baseLista[i];

	while (j <= Dir)
	{
		if (j < Dir) 
		{
			if (baseLista[j].getDist() < baseLista[j+1].getDist())
			{
				j++;
			}
		}

		if (x.getDist() >= baseLista[j].getDist())
		{
			break;
		}

		baseLista[i] = baseLista[j];
		i = j;
		j = i *2;
	}

	baseLista[i] = x;
}

// QUICKSORT MODIFICADO
void Sort::QuickSort_Modificado(Base *listaBase, int n)
{
	Ordena_Insercao(0, n-1, listaBase);
}

void Sort::Ordena_Insercao(int Esq, int Dir, Base *listaBase) 
{
	int i= Esq;
	int j= Dir;

	Particao(Esq, Dir, &i, &j, listaBase);
	if (Esq < j) 
	{	
		if(j-Esq <= 10)
		{
			Insercao_Quicksort(Esq, j, listaBase);
		}
		else
		{
			Ordena_Insercao(Esq, j, listaBase);
		}
	}
	if (i < Dir) 
	{
		if(Dir-i <= 10)
		{
			Insercao_Quicksort(i, Dir, listaBase);
		}
		else
		{
			Ordena_Insercao(i, Dir, listaBase);
		}
	}
}

void Sort::Insercao_Quicksort(int Esq, int Dir, Base *listaBase)
{
	int i,j;
	Base aux;
	for (i = Esq+1; i <= Dir; i++) 
	{
		aux = listaBase[i];
		j = i - 1;
		while (( j >= 0 ) && (aux.getDist() < listaBase[j].getDist())) {
			listaBase[j + 1] = listaBase[j];
			j--;
		}
		listaBase[j + 1] = aux;
	}
}

// TREE SORT
void Sort::TreeSort(Base *baseLista, int n) 
{ 

  	ArvoreBinaria arvore;
  	arvore.Insere(baseLista[0]);
   
    for (int i=1; i<n; i++) 
        arvore.Insere(baseLista[i]); 

    int i = 0; 
    arvore.arvoreEmOrdem(baseLista, arvore.raiz, i);
} 