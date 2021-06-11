#include "Vertice.h"

Vertice::Vertice(string nome) {
	this->nome = nome;
}

Vertice::~Vertice() {
	//dtor
}

string Vertice::getNome() {
    return this->nome;
}

void Vertice::conecta(Vertice* destino) {
    if (quantidade = MAXIMO_ARESTAS) return 0;
    adjacentes[quantidade++] = destino;
    return 1;
}

int Vertice::getNumeroDeArestrasDeSaida() {
    return quantidade;
}
