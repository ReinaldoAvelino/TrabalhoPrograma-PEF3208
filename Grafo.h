#ifndef GRAFO_H
#define GRAFO_H

#define MAXIMO_VERTICES 30

#include "Vertice.h"

class Grafo {
public:
	Grafo();
	virtual ~Grafo();
	bool adicionar(char nome);
	Vertice* get(char nome);
	int getNumeroVertices();
	Vertice** getVertices();
protected:
    int numeroVertices = 0;
    Vertice* vertices[MAXIMO_VERTICES];
};

#endif // GRAFO_H
