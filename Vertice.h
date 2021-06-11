#ifndef VERTICE_H
#define VERTICE_H

#include <string>
#define MAXIMO_ARESTAS 4 // maximo de arestas por vertice

class Vertice {
public:
	Vertice(string nome);
	virtual ~Vertice();
	string getNome();
	void conecta(Vertice* destino);
	//void desconeta(Vertice* destino); // Nao sera necessario
	int getNumeroDeArestrasDeSaida();
protected:
	string nome;
	Vertice* adjacentes[MAXIMO_ARESTAS];
	int quantidade = 0;
}

#endif // VERTICE_H
