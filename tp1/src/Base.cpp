#include "Base.h"

Base::Base()
{
	numTotalAliens = 0;
	numTotalRecursos = 0;
	numLinha = 0;
	numColuna = 0;
	for(int i = 0; i < 50; i++)
	{
		this->listaRobos[i].setId(i);
	}

}

Base::~Base()
{
	cout << "BASE: TOTAL DE ALIENS " << numTotalAliens << " RECURSOS " << numTotalRecursos << endl;
}

void Base::adNovoComando(int robo, Comando &novoComando, Mapa &mapa)
{
	if(novoComando.isComandoDireto())
		realizaComandoDireto(novoComando, mapa, this->listaRobos[robo]);
	else
		this->listaRobos[robo].adComandoLista(novoComando, mapa);
}

void Base::realizaComandoDireto(Comando novoComando, Mapa &mapa, Robo &robo)
{

	if(novoComando.getNome() == "ATIVAR")
	{
		bool roboAtivado = robo.roboAtivar();
		if(roboAtivado)
			cout << "BASE: ROBO " << robo.getId() << " JA ESTA EM MISSAO" << endl;
		else
			cout << "BASE: ROBO " << robo.getId() << " SAIU EM MISSAO" << endl;
	}

	else if(novoComando.getNome() == "EXECUTAR")
	{
		bool executarRobo = robo.roboExecutar(mapa);
		if(!executarRobo)
			cout << "BASE: ROBO " << robo.getId() << " NAO ESTA EM MISSAO" << endl;
	}


	else if(novoComando.getNome() == "RELATORIO")
		robo.roboRelatorio();


	else if(novoComando.getNome() == "RETORNAR")
	{
		bool roboRetornar = robo.roboRetornar();
		if(roboRetornar == false)
			cout << "BASE: ROBO " << robo.getId() << " NAO ESTA EM MISSAO" << endl;
		else
		{
			cout << "BASE: ROBO " << robo.getId() << " RETORNOU ALIENS " << robo.getNumAliens() 
				 << " RECURSOS " << robo.getNumRecursos() << endl;

			numTotalAliens += robo.getNumAliens();
			numTotalRecursos += robo.getNumRecursos();
			robo.resetaRobo();
		}
	}
}