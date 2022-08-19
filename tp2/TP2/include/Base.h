#include <iostream>
using namespace std;

class Base {
	private:
		string nome;
		int dist;

	public:
		void setNome(string novoNome);
		void setDist(int novaDist);
		string getNome();
		int getDist();
};