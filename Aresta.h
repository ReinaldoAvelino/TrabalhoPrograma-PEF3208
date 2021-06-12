#ifndef ARESTA_H
#define ARESTA_H

#include "Vertice.h"

class Aresta {
public:
    Aresta(char* nome, float comprimento, float inclinacao);
    virtual ~Aresta();

protected:
    char* nome;
    float comprimento;
    float inclinacao;
};

#endif // ARESTA_H
