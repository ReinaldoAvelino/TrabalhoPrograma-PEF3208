#include "Aresta.h"

Aresta::Aresta(char* nome, float comprimento, float inclinacao)
{
    this->nome = nome;
    this->comprimento = comprimento;
    this->inclinacao = inclinacao;
}

Aresta::~Aresta()
{
    //dtor
}

