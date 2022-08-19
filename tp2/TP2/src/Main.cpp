#include <iostream>
#include <fstream>
#include <sstream>
#include "Sort.h"
using namespace std;

void Imprime(Base *listaBase, int n);
void leArquivo(Base *listaBase, int numLinhas, char* arquivo);

int main(int argc, char* argv[]) {

	int numLinhas = stoi(argv[2]);
	Base listaBase[numLinhas];
	leArquivo(listaBase, numLinhas, argv[1]);
	
    // Sort::Heapsort(listaBase, numLinhas);
    // Sort::QuickSort_Modificado(listaBase, numLinhas);
    // Sort::Insercao(listaBase, numLinhas);
    // Sort::TreeSort(listaBase, numLinhas); OBS: executar com run.sh
    Sort::QuickSort(listaBase, numLinhas);

    Imprime(listaBase, numLinhas);
}

void Imprime(Base *listaBase, int n)
{
	for(int i = n-1; i >= n-7; i-= 1)
    {
	    cout << listaBase[i].getNome() << " ";
	    cout << listaBase[i].getDist() << endl;
    }
}

void leArquivo(Base *listaBase, int numLinhas, char* arquivo)
{
	ifstream arquivoBase;
    arquivoBase.open(arquivo);
    string novaBase;

    string nomeBase;
    int distBase;

    for(int i = 0; i < numLinhas; i++)
    {
    	getline (arquivoBase, novaBase);
    	stringstream ss(novaBase);

	    ss >> nomeBase >> distBase;
	    listaBase[i].setNome(nomeBase);
	    listaBase[i].setDist(distBase);
    }

    arquivoBase.close();
}
