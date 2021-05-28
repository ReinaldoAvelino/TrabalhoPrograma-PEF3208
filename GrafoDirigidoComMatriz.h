#ifndef GRAFODIRIGIDOCOMMATRIZ_H
#define GRAFODIRIGIDOCOMMATRIZ_H

#include <iostream>
using namespace std;

class GrafoDirigidoComMatriz {
public:
	GrafoDirigidoComMatriz(int v);
	virtual ~GrafoDirigidoComMatriz();
	void conecta(int v1, int v2, int peso);
	void desconecta(int v1, int v2, int peso);
	int getPeso(int v1, int v2);
	int getNumeroDeVertices();
	int getNumeroDeArestras();
	void imprimeBusca(int inicio);
protected:
	int numeroVertices;
	int** Adj;
};

#endif // GRAFODIRIGIDOCOMMATRIZ_H
