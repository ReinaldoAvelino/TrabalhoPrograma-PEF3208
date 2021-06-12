#include "Vertice.h"

Vertice::Vertice(char nome) {
	this->nome = nome;
}

Vertice::~Vertice() {
	//dtor
}

char Vertice::getNome() {
    return this->nome;
}

bool Vertice::conecta(Vertice* destino) {
    if (this->quantidade == MAXIMO_ARESTAS || destino->quantidade == MAXIMO_ARESTAS) return false;
    this->adjacentes[this->quantidade++] = destino;
    destino->adjacentes[destino->quantidade++] = this;
    return true;
}

int Vertice::getNumeroDeArestrasDeSaida() {
    return quantidade;
}

