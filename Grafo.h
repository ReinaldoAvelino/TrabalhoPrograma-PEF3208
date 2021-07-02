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
	bool existeVertice(char nome);
	bool adicionarAresta(char nome1, char nome2, double comprimento, int inclinacao);
	int getNumeroVertices();
	Vertice** getVertices();
	int getNumeroArestas();
	Aresta** getArestas();
	Vertice* getVertice(char nome);
	Aresta* getAresta(char nome1, char nome2);
    double distanciaHorizontal(Vertice* v1, Vertice* v2);
    double distanciaVertical(Vertice* v1, Vertice* v2);
    bool adicionarBarra(char nome1, char nome2, double comprimento, int inclinacao);
    void equilibrio(double &a, char &a_nome,
                    double &b, char &b_nome, char &b_direcao,
                    double &c, char &c_nome);
protected:
    int numeroVertices = 0;
    Vertice* vertices[MAXIMO_VERTICES];
    int numeroArestas = 0;
    Aresta* arestas[MAXIMO_ARESTAS];
};

#endif // GRAFO_H
