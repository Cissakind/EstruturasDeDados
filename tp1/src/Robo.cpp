#include "Robo.h"

void Robo::setId(int id)
{
	this->id = id;
}

int Robo::getId()
{
	return id;
}
void Robo::adComandoLista(Comando &novoComando, Mapa &mapa)
{

	if(novoComando.getPrioridade() == true)
		listaComandosRobo.InsereInicio(novoComando);

	else
		listaComandosRobo.InsereFinal(novoComando);
}

int Robo::getnumLinha()
{
	return numLinha;
}

int Robo::getnumColuna()
{
	return numColuna;
}
void Robo::setPosicao(int linha, int coluna)
{
	numLinha = linha;
	numColuna = coluna;
}

bool Robo::getEstaEmMissao()
{
	return emMissao;
}

void Robo::setEstaEmMissao(bool status)
{
	emMissao = status;
}

void Robo::acrescentaAlien()
{
	numAliens ++;
}

int Robo::getNumAliens()
{
	return numAliens;
}

void Robo::acrescentaRecurso()
{
	numRecursos++;
}

int Robo::getNumRecursos()
{
	return numRecursos;
}

void Robo::resetaRobo()
{
	emMissao = false; //verificar
	numAliens = 0;
	numRecursos = 0;
	numLinha = -1; 
	numColuna = -1; 
	listaComandosRobo.Limpa();
	relatorio.Limpa();
}

void Robo::adNovoRelato(string novoRelato)
{
	Relato novo;
	novo.setNome(novoRelato);
	relatorio.InsereFinal(novo);
}

bool Robo::roboAtivar()
{
	if(emMissao)
		return true;
	else
	{
		setPosicao(0,0);
		setEstaEmMissao(true);
		return false;
	}
}

bool Robo::roboExecutar(Mapa &mapa)
{
	if(!emMissao)
		return false;
	else
	{
		while(!listaComandosRobo.Vazia())
		{
			realizaOrdemDeComando(listaComandosRobo.RemoveInicio(), mapa);
		}
	}
	return true;
}

void Robo::roboRelatorio()
{
	relatorio.Imprime();
}

bool Robo::roboRetornar()
{
	if(emMissao == true)
		return true;
	else
		return false;
}

void Robo::realizaOrdemDeComando(Comando novoComando, Mapa &mapa)
{
	if(emMissao == false)
		return;
	else
	{
		if(novoComando.getNome() == "MOVER")
			roboMover(novoComando, mapa);
		else if(novoComando.getNome() == "COLETAR")
			roboColetar(mapa);
		else if(novoComando.getNome() == "ELIMINAR")
			roboEliminar(mapa); 
	}
}

void Robo::roboMover(Comando novoComando, Mapa &mapa)
{
	if(mapa.getLinha() < novoComando.getnumLinha() || mapa.getColuna() < novoComando.getnumColuna())
		return;

	else if(mapa.getMapaPosicao(novoComando.getnumLinha(),novoComando.getnumColuna()) == 'O')
	{
		string novoRelato = "ROBO " + to_string(id) + ": IMPOSSIVEL MOVER PARA ("+ to_string(novoComando.getnumLinha())
							+ "," + to_string(novoComando.getnumColuna()) + ")";

		adNovoRelato(novoRelato);
	}

	else
	{
		string novoRelato = "ROBO " + to_string(id) + ": MOVEU PARA ("+ to_string(novoComando.getnumLinha())
							+ "," + to_string(novoComando.getnumColuna()) + ")";

		adNovoRelato(novoRelato);
		numLinha = novoComando.getnumLinha();
		numColuna = novoComando.getnumColuna();				
	}
}
void Robo::roboColetar(Mapa &mapa)
{
	if(mapa.getMapaPosicao(numLinha,numColuna) == 'R')
	{
		mapa.modificarMapa(numLinha, numColuna, '.');
		numRecursos++;

		string novoRelato = "ROBO " + to_string(id) + ": RECURSOS COLETADOS EM ("+ to_string(numLinha)
							+ "," + to_string(numColuna) + ")";
		adNovoRelato(novoRelato);						

	}
	else
	{
		string novoRelato = "ROBO " + to_string(id) + ": IMPOSSIVEL COLETAR RECURSOS EM ("+ to_string(numLinha)
					+ "," + to_string(numColuna) + ")";
		adNovoRelato(novoRelato);			
	}
}

void Robo::roboEliminar(Mapa &mapa)
{
	if(mapa.getMapaPosicao(numLinha,numColuna) == 'H')
	{
		mapa.modificarMapa(numLinha, numColuna, '.');
		numAliens++;

		string novoRelato = "ROBO " + to_string(id) + ": ALIEN ELIMINADO EM ("+ to_string(numLinha)
							+ "," + to_string(numColuna) + ")";
		adNovoRelato(novoRelato);						

	}
	else
	{
		string novoRelato = "ROBO " + to_string(id) + ": IMPOSSIVEL ELIMINAR ALIEN EM ("+ to_string(numLinha)
					+ "," + to_string(numColuna) + ")";
		adNovoRelato(novoRelato);			
	}
}