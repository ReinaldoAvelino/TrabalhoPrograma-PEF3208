#ifndef ARESTA_H
#define ARESTA_H

#include "Vertice.h"

class Aresta {
public:
    Aresta(char nome1, char nome2, double comprimento, int inclinacao);
    virtual ~Aresta();
    char getNome1();
    char getNome2();
    double getComprimento();
    int getInclinacao();
    double getIntensidade();
    int getForma();
    void addDistribuicao(double intensidade, int forma); // adiciona uma carga de forca distribuida

protected:
    char nome1; // Nome vertice 1
    char nome2; // Nome vertice 2
    double comprimento;
    int inclinacao; // habilitado somente para 0 ou 90 graus
    double intensidade = 0; // intensidade da forca distribuida
    int forma; // forma geometrica da forca distribuida
               // 1 para retangulo, 2 para triangulo (crescente), 3 para triangulo (decrescente)
};

#endif // ARESTA_H
