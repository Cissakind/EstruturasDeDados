 // TipoChave é um inteiro
#include <iostream>
using namespace std;

class TipoItem
{
	public:
	TipoItem();
	TipoItem(char c);
	void SetChave(char c);
	char GetChave();
	void Imprime();
	
	private:
	char chave;
};