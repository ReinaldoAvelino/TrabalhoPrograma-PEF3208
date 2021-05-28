#include "GrafoDirigidoComMatriz.h"
#include <iostream>
using namespace std;

GrafoDirigidoComMatriz::GrafoDirigidoComMatriz(int v) {
	this->numeroVertices = v;
	Adj = new int*[numeroVertices];
	for (int i = 0; i < numeroVertices; i++) {
		Adj[i] = new int[numeroVertices];
		for(int j = 0; j < numeroVertices; j++) {
			Adj[i][j] = 0;
		}
	}
}

GrafoDirigidoComMatriz::~GrafoDirigidoComMatriz() {
	for (int i = 0; i < numeroVertices; i++) {
		delete[] Adj[i];
	}
	delete[] Adj;
	cout << "GrafoDirigidoComMatriz deletado." << endl;
}

void GrafoDirigidoComMatriz::conecta(int v1, int v2, int peso) {
	this->Adj[v1-1][v2-1] = peso;
}

void GrafoDirigidoComMatriz::desconecta(int v1, int v2, int peso) {
	this->Adj[v1-1][v2-1] = 0;
}

int GrafoDirigidoComMatriz::getPeso(int v1, int v2) {
	return this->Adj[v1-1][v2-1];
}

int GrafoDirigidoComMatriz::getNumeroDeVertices() {
	return this->numeroVertices;
}

int GrafoDirigidoComMatriz::getNumeroDeArestras() {
	int numeroArestras = 0;
	for (int i = 0; i < numeroVertices; i++) {
		for (int j = 0; j < numeroVertices; j++) {
			if (Adj[i][j] != 0) numeroArestras++;
		}
	}
	return numeroArestras;
}
