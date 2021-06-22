#ifndef ARESTA_H
#define ARESTA_H

#include "Vertice.h"

class Aresta {
public:
    Aresta(char* nome, float comprimento, float inclinacao);
    virtual ~Aresta();
    char* getNome();
    void addDistribuicao(double intensidade, int forma); // adiciona uma carga de forca distribuida
                                                         // forma 1 para retangulo e 2 para triangulo

protected:
    char* nome;
    float comprimento;
    float inclinacao; // habilitado somente para 0 ou 90 graus
    double intensidade; // intensidade da forca distribuida
    int forma; // forma geometrica da forca distribuida
};

#endif // ARESTA_H
