#include "Comando.h"

Comando::Comando()
{
	prioridade = false;
	numLinha = -1;
	numColuna = -1;
}

void Comando::setPrioridade(bool status) 
{
	prioridade = status;
}

void Comando::setNome(string nomeAcao) 
{
	nome = nomeAcao;
}

string Comando::getNome() 
{
	return nome;
}

void Comando::Imprime() 
{
	cout << nome <<  endl;
}

void Comando::setPosicao(int linha, int coluna)
{ 
	numLinha = linha; numColuna = coluna;
}

int Comando::getnumLinha()
{
	return numLinha;
}
int Comando::getnumColuna() 
{
	return numColuna; 
}

bool Comando::isComandoDireto() 
{
	if(nome == "ATIVAR" || nome == "EXECUTAR" || nome == "RELATORIO" || nome == "RETORNAR") 
		return true;
	return false;
}

bool Comando::getPrioridade() 
{
	return prioridade;
}