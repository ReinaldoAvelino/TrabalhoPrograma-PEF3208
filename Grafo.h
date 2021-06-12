#ifndef GRAFO_H
#define GRAFO_H

#define MAXIMO_VERTICES 20
#define MAXIMO_ARESTAS 20

#include "Vertice.h"
#include "Aresta.h"

class Grafo {
public:
	Grafo();
	virtual ~Grafo();
	bool adicionarVertice(char nome);
	bool adicionarAresta(char* nome, float comprimento, float inclinacao);
	Vertice* get(char nome);
	int getNumeroVertices();
	Vertice** getVertices();
	int getNumeroArestas();
	Aresta** getArestas();
protected:
    int numeroVertices = 0;
    Vertice* vertices[MAXIMO_VERTICES];
    int numeroArestas = 0;
    Aresta* arestas[MAXIMO_ARESTAS];
};

#endif // GRAFO_H
