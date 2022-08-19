#include <fstream>
#include <sstream>
#include "Codigo.h"
#include <iostream>
using namespace std;

void leArquvo(string linhaCodigo, ArvoreBinaria &arvore);

int main(int argc, char* argv[]) {

	ArvoreBinaria arvore;

	ifstream arquivoCodigos;
    arquivoCodigos.open(argv[1]);
    string linhaCodigo;

	while (getline (arquivoCodigos, linhaCodigo)) 
    {
        leArquvo(linhaCodigo, arvore);
    }
}

void leArquvo(string linhaCodigo, ArvoreBinaria &arvore)
{
	Codigo novoCodigo;

 	if(linhaCodigo[0] == 'A')
    	novoCodigo.resolveA(arvore, linhaCodigo);

    else if(linhaCodigo[0] == 'D')
    	novoCodigo.resolveD(arvore, linhaCodigo);

    else if(linhaCodigo[0] == 'C')
    	novoCodigo.resolveC(arvore, linhaCodigo);
 }