#include "Grafo.h"

Grafo::Grafo()
{
    //ctor
}

Grafo::~Grafo()
{
    for (int i = 0; i < numeroVertices; i++) {
        delete vertices[i];
    }
}

Vertice* Grafo::adiciona(string nome) {
    vertices[numeroVertices++] = new Vertice(nome);
    return vertices[numeroVertices-1];
}

Vertice* Grafo::get(string nome) {
    for (int i = 0; i < numeroVertices; i++) {
        if (vertices[i]->getNome().compare(nome) == 0) {
            return vertices[i];
        }
    }
    return NULL;
}

int Grafo::getNumeroVertices()
{
    return numeroVertices;
}
