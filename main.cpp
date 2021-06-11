#include <iostream>
#include <string>
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

void interface() {
	cout << "PROGRAMA SOLUCIONADOR DE PROBLEMAS SIMPLES DE MECANICA DAS ESTRUTURAS" << end << endl;
	cout << "Software desenvolvido por Lucas Marques e Reinaldo Avelino durante a disciplina PEF3208." << endl;
	cout << "========================================================================================" << endl;
	
	int opcao = -1;
	while (opcao < 0 or opcao > 3) {
		cout << "Menu de opcoes:" << endl;
		     << "0) Encerrar;" << endl;
		     << "1) Adicionar barra;" << endl;
		     << "2) Adicionar apoio;" << endl;
		     << "3) Adicionar carga;" << endl;
		cout << "Digite o numero da opcao: ";
		cin >> opcao;
	}
	
	
}

int main() {
	teste();
	return 0;
}
