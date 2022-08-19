#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include "Base.h"

using namespace std;
void adListaComando(string linhaComando, Base &novaBase, Mapa &mapa);
void criaMapa(char* arquivo, Mapa &mapa);

int main(int argc, char *argv[])
{
    Mapa mapa;
    Base novaBase;
    criaMapa(argv[1], mapa);

    ifstream arquivoComandos;
    arquivoComandos.open(argv[2]);
    string comando;

    while (getline (arquivoComandos, comando)) 
    {
        adListaComando(comando, novaBase, mapa);
    }

    arquivoComandos.close();
}

void adListaComando(string linhaComando, Base &novaBase, Mapa &mapa)
{
    Comando novoComando;
    stringstream ss(linhaComando);

    int numRobo;
    string nomeComando;
    string posicao;

    ss >> nomeComando >> numRobo >> posicao;
    if(nomeComando[0] == '*')
    {
        novoComando.setPrioridade(true);
        nomeComando.erase(0,1);
    }

    if(!posicao.empty())
    {
        istringstream ss(posicao);
        int row, col;
        char delimiter;
        ss >> delimiter >> row >> delimiter >> col >> delimiter;
        novoComando.setPosicao(row, col);
    }

    novoComando.setNome(nomeComando);
    novaBase.adNovoComando(numRobo, novoComando, mapa);
}

void criaMapa(char* arquivo, Mapa &mapa)
{
    ifstream arquivoMapa;
    arquivoMapa.open(arquivo);

    string linhaMapa;
    getline (arquivoMapa, linhaMapa);
    stringstream ss(linhaMapa);

    getline(ss, linhaMapa, ' ');
    int linha = stoi(linhaMapa);
    getline(ss, linhaMapa, ' ');
    int coluna = stoi(linhaMapa);

    mapa.setMapa(linha,coluna);
    for(int i = 0; i < linha; i++)
    {
        getline (arquivoMapa, linhaMapa);
        stringstream ss(linhaMapa);
        for(int j = 0; j < coluna; j++)
        {
            getline(ss, linhaMapa, ' ');
            mapa.modificarMapa(i,j,(char)linhaMapa[0]);
        }
    }
    arquivoMapa.close();
}