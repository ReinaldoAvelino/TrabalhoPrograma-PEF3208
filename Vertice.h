#ifndef VERTICE_H
#define VERTICE_H

using namespace std;

class Vertice {
public:
	Vertice(char nome);
	virtual ~Vertice();
	char getNome();
	int getNumeroDeArestrasDeSaida();
protected:
	char nome;
	Vertice* adjacentes[4];
	int quantidade = 0;
};

#endif // VERTICE_H
