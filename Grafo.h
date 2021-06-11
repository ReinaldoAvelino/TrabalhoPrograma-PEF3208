#ifndef GRAFO_H
#define GRAFO_H

#include <string>
#define MAXIMO_VERTICES

#include "Vertice.h"

class Grafo {
public:
	Grafo();
	virtual ~Grafo();
	Vertice* adiciona(string nome);
	Vertice* get(string nome);
	int getNumeroVertices();
protected:
    int numeroVertices = 0;
    Vertice* vertices[MAXIMO_VERTICES];
};

#endif // GRAFO_H
