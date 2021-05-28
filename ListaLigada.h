#ifndef LISTALIGADA_H
#define LISTALIGADA_H

class Elemento {
    public:
        Elemento();
        virtual ~Elemento();
        int getChave();
        Elemento* getProximo();
        void setChave(int chave);
        void setProximo(Elemento* proximo);
    protected:
        int chave;
        Elemento* proximo;
};

class ListaLigada
{
    public:
        ListaLigada();
        virtual ~ListaLigada();
        Elemento* getInicio();
        void setInicio(Elemento* inicio);
        Elemento* search(int k);
        void insert(int k);
        bool remove(Elemento* apagar);
        void imprimir();
    protected:
        Elemento* inicio;
};

#endif // LISTALIGADA_H
