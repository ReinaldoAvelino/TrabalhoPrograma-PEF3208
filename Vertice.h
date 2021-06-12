#ifndef VERTICE_H
#define VERTICE_H

using namespace std;

#define MAXIMO_ARESTAS 4 // maximo de arestas por vertice

class Vertice {
public:
	Vertice(char nome);
	virtual ~Vertice();
	char getNome();
	bool conecta(Vertice* destino);
	//void desconeta(Vertice* destino); // Nao sera necessario
	int getNumeroDeArestrasDeSaida();
protected:
	char nome;
	Vertice* adjacentes[MAXIMO_ARESTAS];
	int quantidade = 0;
};

#endif // VERTICE_H
