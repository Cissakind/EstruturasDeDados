class Mapa {
	private:
	int coluna;
	int linha;
	char **mapa;

	public:
	Mapa();
	~Mapa();
	void setMapa(int l, int c);
	int getColuna();
	int getLinha();
	void Imprime();
	void modificarMapa(int x, int y, char c);
	char getMapaPosicao(int x, int y);
};