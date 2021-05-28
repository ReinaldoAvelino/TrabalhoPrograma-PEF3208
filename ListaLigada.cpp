#include "ListaLigada.h"
#include <iostream>
using namespace std;

Elemento::Elemento() {
    this->chave = 0;
    this->proximo = NULL;
}

Elemento::~Elemento() {
    //dtor
}

int Elemento::getChave()
{
    return this->chave;
}

Elemento* Elemento::getProximo()
{
    return this->proximo;
}

void Elemento::setChave(int chave)
{
    this->chave = chave;
}

void Elemento::setProximo(Elemento* proximo)
{
    this->proximo = proximo;
}

ListaLigada::ListaLigada()
{
    //ctor
    this->inicio = NULL;
}

ListaLigada::~ListaLigada()
{
    //dtor
    Elemento* atual = this->inicio;
    Elemento* prox = NULL;
    while (atual != NULL) {
        prox = atual->getProximo();
        delete atual;
        atual = prox;
    }
    cout << "ListaLigada deletada." << endl;
}

void ListaLigada::setInicio(Elemento* inicio)
{
    this->inicio = inicio;
}

Elemento* ListaLigada::getInicio()
{
    return this->inicio;
}


Elemento* ListaLigada::search(int k) {

    Elemento* x = new Elemento();
    x = this->inicio;

    while (x->getChave() != k) {
        x = x->getProximo();
        if (x == NULL) return x;
    }
    if (x->getChave() == k) return x;
    else return x = NULL;
    delete x;
}

void ListaLigada::insert(int k) {
    Elemento* E = new Elemento();
    E->setChave(k);
    E->setProximo(NULL);
    if (this->inicio == NULL) {
        this->inicio = E;
    }
    else {
        Elemento* x = new Elemento();
        x = this->inicio;
        while (x->getProximo() != NULL) {
            x = x->getProximo();
        }
        x->setProximo(E);
    }
    delete E;
}

void ListaLigada::imprimir() {
    Elemento* x = new Elemento;
    x = this->inicio;
    int i = 1;
    while (x != NULL) {
        cout << "Elemento " << i << ": " << x->getChave() << endl;
        i++;
        x = x->getProximo();
    }
    delete x;
}

bool ListaLigada::remove(Elemento* apagar)
{
    if (this->inicio == apagar) {
        this->inicio = apagar->getProximo();
        delete apagar;
        return true;
    }
    Elemento* atual = new Elemento();
    atual->setProximo(this->inicio);
    while (atual->getProximo() != apagar) {
        atual = atual->getProximo();
        if (atual->getProximo() == NULL) return false;
    }
    atual->setProximo(apagar->getProximo());
    delete apagar;
    delete atual;
    return true;

}

