#include "Codigo.h"
#include <stdio.h>

void Codigo::resolveA(ArvoreBinaria &arvore, string linhaCodigo)
{
	int tam = linhaCodigo.length();
    int offset = 3;

    for(int i = offset; i < tam; i++)
    {
    	char nova = linhaCodigo[i];
    	TipoItem novaLetra(nova);
		arvore.Insere(novaLetra);
    }
}

void Codigo::resolveD(ArvoreBinaria &arvore, string linhaCodigo)
{
	int i = 3; //offset
	int tam = linhaCodigo.length();
	string codDecodificado;
	while(i < tam)
	{
		TipoNo *p = arvore.getRaiz();
		i++;
		while(linhaCodigo[i] != 'x' && i < tam)
		{
			if((int)(linhaCodigo[i]-'0') % 2 == 0)
				p = p->getDir();
			else if ((int)(linhaCodigo[i]-'0') % 2 == 1)
				p = p->getEsq();
			i++;
		}

		codDecodificado.push_back(p->getItem().GetChave());
	}

	cout << codDecodificado << endl;
}

void Codigo::resolveC(ArvoreBinaria &arvore, string linhaCodigo)
{
	string codCodificado;
	int tam = linhaCodigo.length();
	int offset = 3;
	for(int i = offset; i < tam; i++)
	{
		codCodificado.push_back('x');
		PesquisaRecursivo(arvore.getRaiz(), linhaCodigo[i], codCodificado);
	}
	cout << codCodificado << endl;
}

void Codigo::PesquisaRecursivo(TipoNo *no, TipoItem item, string &codigo) 
{
	if (no == NULL) {
		return;
	}

	if (item.GetChave() < no->getItem().GetChave())
	{
		int num = (rand() % (4 + 1)) * 2 + 1; 
		char novoNumero = num + '0' ;
		codigo.push_back(novoNumero);
		return PesquisaRecursivo(no->getEsq(), item, codigo);
	}

	else if (item.GetChave() > no->getItem().GetChave())  
	{
		int num = (rand() % (4 + 1)) * 2;
		char novoNumero = num + '0';
		codigo.push_back(novoNumero);
		return PesquisaRecursivo(no->getDir(), item, codigo);
	}

	else
	{
		return;
	}
}