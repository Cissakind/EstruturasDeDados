#include "Robo.h"

class Base {
	public:
	Base();
	~Base();
	void adNovoComando(int robo, Comando &novoComando, Mapa &mapa);
	void realizaComandoDireto(Comando novoComando, Mapa &mapa, Robo &robo);

	private:
	Robo listaRobos[50];
	int numTotalAliens;
	int numTotalRecursos;
	int numLinha;
	int numColuna;
};