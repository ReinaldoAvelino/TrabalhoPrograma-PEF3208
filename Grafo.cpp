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
    for (int i = 0; i < numeroArestas; i++) {
        delete arestas[i];
    }
}

bool Grafo::adicionarVertice(char nome) {
    if (numeroVertices == MAXIMO_VERTICES) return false;
    for (int i = 0; i < numeroVertices; i++) {
        if (vertices[i]->getNome() == nome) return false;
    }
    vertices[numeroVertices++] = new Vertice(nome);
    return true;
}

bool Grafo::adicionarAresta(char* nome, float comprimento, float inclinacao) {
    if(numeroArestas == MAXIMO_ARESTAS) return false;

    arestas[numeroArestas++] = new Aresta(nome, comprimento, inclinacao);
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

int Grafo::getNumeroArestas()
{
    return numeroArestas;
}
