#include <string>
#include <iostream>
using namespace std;

class Comando {

	private:
		string nome;
		bool prioridade;
		int numLinha;
		int numColuna;

	public:
		Comando();
		void setOrdem();
		void setPrioridade(bool status);
		void setNome(string nomeAcao);
		string getNome();
		void Imprime();
		void setPosicao(int linha, int coluna);
		int getnumLinha();
		int getnumColuna();
		bool isComandoDireto();
		bool getPrioridade();

};