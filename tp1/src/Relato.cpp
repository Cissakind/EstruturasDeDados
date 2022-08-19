#include "Relato.h"

void Relato::setNome(string relato)
{
	nome = relato;
}

string Relato::getNome() 
{
	return nome;
}
void Relato::Imprime() 
{
	cout << nome <<  endl;
}