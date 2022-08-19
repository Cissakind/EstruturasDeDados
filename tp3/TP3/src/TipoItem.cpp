#include "string.h"
#include "TipoItem.h"
#include <iostream>
using namespace std;

TipoItem::TipoItem()
{
	chave = '.';
}

TipoItem::TipoItem(char c)
{
	chave = c;
}

void TipoItem::SetChave(char c)
{
	chave = c;
}

char TipoItem::GetChave()
{
	return chave;
}

void TipoItem::Imprime()
{
	cout << chave;
}