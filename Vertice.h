#ifndef VERTICE_H
#define VERTICE_H

#include <iostream>
using namespace std;

class Vertice {
public:
	Vertice(char nome);
	virtual ~Vertice();
	char getNome();
	bool addForca(double intensidade, char direcao); // direcao pode ser 'i' ou 'j'
	double getFx();
	double getFy();
	bool setIncognita(int booleana, char direcao); // direcao pode ser 'i', 'j'
	int* getIncognitas();
	void setCoordenadas(double x0, double y0);
	double* getCoordenadas();
protected:
	char nome;
	double Fx = 0;
	double Fy = 0;
	int incognitas[3] = {0, 0, 0}; // {Fx, Fy, Mz} // 1 se tiver incognita, 0 caso contrario
    double coordenadas[2]; // {x0, y0}
};

#endif // VERTICE_H
