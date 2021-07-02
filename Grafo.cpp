 #include "Grafo.h"
#include <iostream>

Grafo::Grafo()
{
    //ctor
}

Grafo::~Grafo()
{
    for (int i = 0; i < numeroArestas; i++) {
        delete arestas[i];
    }
    for (int i = 0; i < numeroVertices; i++) {
        delete vertices[i];
    }
}

bool Grafo::adicionarVertice(char nome) {
    if (numeroVertices == MAXIMO_VERTICES) return false;
    for (int i = 0; i < numeroVertices; i++) {
        if (vertices[i]->getNome() == nome) return false;
    }
    vertices[numeroVertices++] = new Vertice(nome);
    return true;
}

bool Grafo::existeVertice(char nome) {
    for (int i = 0; i < numeroVertices; i++) {
        if (vertices[i]->getNome() == nome) return true;
    }
    return false;
}

bool Grafo::adicionarAresta(char nome1, char nome2, double comprimento, int inclinacao) {
    if (numeroArestas == MAXIMO_ARESTAS) return false;
    arestas[numeroArestas++] = new Aresta(nome1, nome2, comprimento, inclinacao);
    return true;
}

int Grafo::getNumeroVertices() {
    return numeroVertices;
}

Vertice** Grafo::getVertices() {
    return vertices;
}

int Grafo::getNumeroArestas() {
    return numeroArestas;
}

Aresta** Grafo::getArestas() {
    return arestas;
}

Vertice* Grafo::getVertice(char nome) {
    for (int i = 0; i < numeroVertices; i++) {
        if (vertices[i]->getNome() == nome) return vertices[i];
    }
    return NULL;
}

Aresta* Grafo::getAresta(char nome1, char nome2) {
    for (int i = 0; i < numeroArestas; i++) {
        if (arestas[i]->getNome1() == nome1 && arestas[i]->getNome2() == nome2)
            return arestas[i];
    }
    return NULL;
}

double Grafo::distanciaHorizontal(Vertice* v1, Vertice* v2) {
    double x1 = v1->getCoordenadas()[0];
    double x2 = v2->getCoordenadas()[0];
    return (x2 - x1);
}

double Grafo::distanciaVertical(Vertice* v1, Vertice* v2) {
    double y1 = v1->getCoordenadas()[1];
    double y2 = v2->getCoordenadas()[1];
    return (y2 - y1);
}

bool Grafo::adicionarBarra(char nome1, char nome2, double comprimento, int inclinacao) {
    if (numeroVertices == 0) { // Caso seja a primeira barra
        adicionarVertice(nome1);
        getVertice(nome1)->setCoordenadas(0, 0); // Vertice de origem
    }

    double x0, y0;

    if (inclinacao == 0) {
        if (existeVertice(nome1) && !existeVertice(nome2)) { // Barra para a direita
            adicionarVertice(nome2);
            x0 = getVertice(nome1)->getCoordenadas()[0];
            y0 = getVertice(nome1)->getCoordenadas()[1];
            getVertice(nome2)->setCoordenadas(x0+comprimento, y0);
            adicionarAresta(nome1, nome2, comprimento, 0);
            return true;
        }
        else if (!existeVertice(nome1) && existeVertice(nome2)) { // Barra para a esquerda
            adicionarVertice(nome1);
            x0 = getVertice(nome2)->getCoordenadas()[0];
            y0 = getVertice(nome2)->getCoordenadas()[1];
            getVertice(nome1)->setCoordenadas(x0-comprimento, y0);
            adicionarAresta(nome1, nome2, comprimento, 0);
            return true;
        }
        else {
            // Barra isolada
            return false;
        }
    }
    else if (inclinacao == 90) {
        if (existeVertice(nome1) && !existeVertice(nome2)) { // Barra esta para cima
            adicionarVertice(nome2);
            x0 = getVertice(nome1)->getCoordenadas()[0];
            y0 = getVertice(nome1)->getCoordenadas()[1];
            getVertice(nome2)->setCoordenadas(x0, y0+comprimento);
            adicionarAresta(nome1, nome2, comprimento, 90);
            return true;
        }
        else if (!existeVertice(nome1) && existeVertice(nome2)) { // Barra esta para baixo
            adicionarVertice(nome1);
            x0 = getVertice(nome2)->getCoordenadas()[0];
            y0 = getVertice(nome2)->getCoordenadas()[1];
            getVertice(nome1)->setCoordenadas(x0, y0-comprimento);
            adicionarAresta(nome1, nome2, comprimento, 90);
            return true;
        }
        else {
            // Barra isolada
            return false;
        }
    }
    else {
        // Inclinacao errada
        return false;
    }
}

void Grafo::equilibrio (double &a, char &a_nome,
                        double &b, char &b_nome, char &b_direcao,
                        double &c, char &c_nome)
    {
    Aresta* aresta;

    // Caso onde tem forcas distribuidas
    for (int i = 0; i < numeroArestas; i++) {
        aresta = arestas[i];
        if (aresta->getIntensidade() != 0) { // Se tem forca distribuida
            double x0 = getVertice(aresta->getNome1())->getCoordenadas()[0];
            double y0 = getVertice(aresta->getNome1())->getCoordenadas()[1];
            adicionarVertice('o');
            double xBaricentro;
            if (aresta->getForma() == 1) { // Retangulo
                xBaricentro = x0 + (1.0/2.0)*(aresta->getComprimento());

            }
            else if (aresta->getForma() == 2) { // Triangulo (crescente)
                xBaricentro = x0 + (2.0/3.0)*(aresta->getComprimento());

            }
            else if (aresta->getForma() == 3) { // Triangulo (decrescente)
                xBaricentro = x0 + (1.0/3.0)*(aresta->getComprimento());
            }
            getVertice('o')->setCoordenadas(xBaricentro, y0);
            double area = (aresta->getComprimento())*(aresta->getIntensidade());
            getVertice('o')->addForca(area, 'j');
            break; // Habilitado para somente 1 distribuicao
        }
    }
    Vertice* v;

    // Fx = 0
    double sumFx = 0;
    for (int i = 0; i < numeroVertices; i++) {
        sumFx += vertices[i]->getFx();
    }
    for (int i = 0; i < numeroVertices; i++) {
        v = vertices[i];
        if (v->getIncognitas()[0] == 1) { // Se tiver incognita em x
            a = (-1)*sumFx; // a + sumFx = 0
            a_nome = v->getNome();
            v->addForca(a, 'i'); // Adicionando o valor da incognita como forca
            v->setIncognita(0, 'i'); // Tirando a incognita
            break;
        }
    }

    // Mz = 0
    Vertice* u;
    double sumMz = 0;
    double braco;

    for (int i = 0; i < numeroVertices; i++) {
        v = vertices[i];
        if (v->getIncognitas()[1] == 1) { // Se tiver incognita em y
            c_nome = v->getNome();
            break; // v sera o referencial do momento
        }
    }

    for (int i = 0; i < numeroVertices; i++) {
        u = vertices[i];
        if (u->getFx() != 0) { // Se tiver forca em x
            braco = distanciaVertical(v, u);
            sumMz +=  (-1) * braco * u->getFx(); // Convencao de Grinter
        }
        if (u->getFy() != 0) { // Se tiver forca em y
            braco = distanciaHorizontal(v, u);
            sumMz += braco * u->getFy(); // Convencao de Grinter
        }
    }

    if (v->getIncognitas()[2] == 1) { // Se tiver incognita em z (Mz)
        // v se trata de um engastamento
        b = -sumMz; // sumMz + b = 0
        b_nome = v->getNome();
        b_direcao = 'k';
        v->setIncognita(0, 'k'); // Tirando a incognita
    }
    else {
        for (int i = 0; i < numeroVertices; i++) {
            u = vertices[i];
            if (u->getIncognitas()[1] == 1 && u->getNome() != v->getNome()) { // Se tiver incognita em y
                // u sera o vertice no qual descobriremos a incognita
                braco = distanciaHorizontal(v, u);
                b = -sumMz/braco; // sumMz + braco*b = 0
                b_nome = u->getNome();
                b_direcao = 'j';
                u->addForca(b, 'j'); // Adicionando o valor da incognita como forca
                u->setIncognita(0, 'j'); // Tirando a incognita
                break;
            }
        }
    }

    // Fy = 0
    double sumFy = 0;
    // Descobriremos a incognita em y de v, nosso referencial do momento
    for (int i = 0; i < numeroVertices; i++) {
        sumFy += vertices[i]->getFy();
    }
    c = -sumFy; // c + sumFy = 0

}
