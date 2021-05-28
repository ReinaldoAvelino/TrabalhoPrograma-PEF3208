#include <iostream>
#include "GrafoDirigidoComMatriz.h"
#include "ListaLigada.h"
using namespace std;

void teste() {
    /*
	GrafoDirigidoComMatriz* G = new GrafoDirigidoComMatriz(5);
	G->conecta(1, 5, 2);
	G->conecta(2, 1, 4);
	G->conecta(2, 3, 3);
	G->conecta(2, 4, 4);
	G->conecta(3, 1, 2);
	G->conecta(4, 3, 2);
	G->conecta(4, 5, 5);

	cout << G->getPeso(4, 5) << endl;
	cout << G->getPeso(3, 1) << endl;
	cout << G->getNumeroDeArestras() << endl;
	cout << G->getNumeroDeVertices() << endl;
	delete G;
	*/

	Elemento* x = new Elemento();
	x->setChave(10);
	Elemento* y = new Elemento();
	y->setChave(20);
	Elemento* z = new Elemento();
	z->setChave(30);
	x->setProximo(y);
	y->setProximo(z);
	ListaLigada* L = new ListaLigada();
    L->setInicio(x);
    L->imprimir();
    delete L;
}

int main() {
	teste();
	return 0;
}
