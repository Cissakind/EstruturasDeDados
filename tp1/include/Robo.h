#include "ListaTemplate.h"
#include "Mapa.h"

class Robo {
	private:
		ListaTemplate<Comando> listaComandosRobo;
		ListaTemplate<Relato> relatorio;

		int id;
		int numAliens = 0;
		int numRecursos = 0;
		int numLinha = -1;
		int numColuna = -1;
		bool emMissao = false;

	public:
		void setId(int id);
		int getId();
		void adComandoLista(Comando &novoComando, Mapa &mapa);
		int getnumLinha();
		int getnumColuna();
		void setPosicao(int linha, int coluna);
		bool getEstaEmMissao();
		void setEstaEmMissao(bool status);
		void acrescentaAlien();
		int getNumAliens();
		void acrescentaRecurso();
		int getNumRecursos();
		void resetaRobo();
		void adNovoRelato(string novoRelato);

		bool roboAtivar();
		bool roboExecutar(Mapa &mapa);
		void roboRelatorio();
		bool roboRetornar();

		void realizaOrdemDeComando(Comando novoComando, Mapa &mapa);
		void roboMover(Comando novoComando, Mapa &mapa);
		void roboColetar(Mapa &mapa);
		void roboEliminar(Mapa &mapa);

};