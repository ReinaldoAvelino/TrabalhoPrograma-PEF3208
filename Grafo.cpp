#include "Grafo.h"
#include <iostream>

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

bool Grafo::adicionar(char nome) {
    if (numeroVertices == MAXIMO_VERTICES) return false;
    for (int i = 0; i < numeroVertices; i++) {
        if (vertices[i]->getNome() == nome) return false;
    }
    vertices[numeroVertices++] = new Vertice(nome);
    return true;
}

Vertice* Grafo::get(char nome) {
    for (int i = 0; i < numeroVertices; i++) {
        if (vertices[i]->getNome() == nome) {
            return vertices[i];
        }
    }
    return NULL;
}

int Grafo::getNumeroVertices()
{
    return numeroVertices;
}

Vertice** Grafo::getVertices()
{
    return vertices;
}
