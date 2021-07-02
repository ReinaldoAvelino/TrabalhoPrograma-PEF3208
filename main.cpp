#include <iostream>

#include "Grafo.h"

using namespace std;

void addBarra(Grafo* estrutura) {

	int opcao;
	char nome1, nome2;
    double comprimento;

    cout << "Tipos de barra:" << endl
         << "0) Retornar" << endl
         << "1) Horizontal" << endl
         << "2) Vertical" << endl
         << "Digite o numero da opcao: ";
    cin >> opcao;

    cout << "Digite o nome da barra (ex.: AB, CD): ";
    cin >> nome1 >> nome2;
    cout << "Digite o comprimento da barra em metros (utilize ponto): ";
    cin >> comprimento;

    switch (opcao) {

        case 0: break;

        case 1: { // Barra horizontal

            if (estrutura->adicionarBarra(nome1, nome2, comprimento, 0) ) {
                cout << endl << "=> Barra adicionada" << endl;
            }
            else cout << "Erro ao adicionar barra" << endl;
            break;
        }
        case 2: { // Barra vertical

            if (estrutura->adicionarBarra(nome1, nome2, comprimento, 90)) {
                cout << endl << "=> Barra adicionada" << endl;
            }
            else cout << "Erro ao adicionar barra" << endl;
            break;
        }
        default: {cout << "Numero invalido. Tente novamente." << endl; break;}
    }
}

void addApoio(Grafo* estrutura) {

	int opcao;
	char nome;

    cout << "Tipos de apoio:" << endl
         << "0) Retornar" << endl
         << "1) Articulacao Movel" << endl
         << "2) Articulacao Fixa" << endl
         << "3) Engastamento" << endl
         << "Digite o numero da opcao: ";
    cin >> opcao;

    cout << "Digite o nome do vertice: (ex.: A, E): ";
    cin >> nome;

    switch (opcao) {

        case 0: break;

        case 1: {
            if (Vertice* v = estrutura->getVertice(nome)) { // Se o vertice existir
                v->setIncognita(1, 'j');
            }
            cout << endl << "=> Apoio adicionado" << endl;
            break;
        }
        case 2: {
            if (Vertice* v = estrutura->getVertice(nome)) { // Se o vertice existir
                v->setIncognita(1, 'i');
                v->setIncognita(1, 'j');
            }
            cout << endl << "=> Apoio adicionado" << endl;
            break;
        }
        case 3: {
            if (Vertice* v = estrutura->getVertice(nome)) { // Se o vertice existir
                v->setIncognita(1, 'i');
                v->setIncognita(1, 'j');
                v->setIncognita(1, 'k');
            }
            cout << endl << "=> Apoio adicionado" << endl;
            break;
        }
        default: {cout << "Numero invalido. Tente novamente." << endl; break;}
    }
}

void addCarga(Grafo* estrutura) {

    int opcao;
    cout << "Tipos de carga:" << endl
         << "0) Retornar" << endl
         << "1) Forca concentrada" << endl
         << "2) Forca distribuida" << endl
         << "Digite o numero da opcao: ";
    cin >> opcao;

    switch (opcao) {
        case 0: break;

        case 1: {
            char nome;
            double intensidade;
            char direcao;
            cout << "Vertice (ponto) de acao da forca: ";
            cin >> nome;

            if (Vertice* v = estrutura->getVertice(nome)) {
                cout << "Direcao (i ou j): ";
                cin >> direcao;
                cout << "Intensidade (em kN): ";
                cin >> intensidade;
                v->addForca(intensidade, direcao);
            }
            else cout << "Vertice inexistente. Tente novamente." << endl;
            cout << endl << "=> Carga adicionada" << endl;
            break;
        }
        case 2: {
            char nome1, nome2;
            double intensidade;
            int forma;

            cout << "Barra de acao da forca (ex.: AB, CD): ";
            cin >> nome1 >> nome2;
            cout << "Forma geometrica da distribuicao:" << endl
                 << "1) Retangular;" << endl
                 << "2) Triangular;" << endl
                 << "Digite o numero da opcao: ";
            cin >> forma;

            switch (forma) {
                case 1:
                    cout << "Intensidade de distribuicao (em kN/m): ";
                    cin >> intensidade;
                    if (Aresta* a = estrutura->getAresta(nome1, nome2)) { // Caso haja aresta com tal nome
                        a->addDistribuicao(intensidade, forma);
                    }
                    cout << endl << "=> Carga adicionada" << endl;
                    break;
                case 2:
                    int forma2;
                    cout << "Forma geometrica da distribuicao:" << endl
                         << "1) Triangular crescente;" << endl
                         << "2) Triangular decrescente;" << endl
                         << "Digite o numero da opcao: ";
                    cin >> forma2;
                    cout << "Intensidade maxima da distribuicao (em kN/m): ";
                    cin >> intensidade;
                    if (forma2 != 1 || forma2 != 2) {
                        cout << "Numero invalido." << endl;
                        break;
                    }
                    if (Aresta* a = estrutura->getAresta(nome1, nome2)) {
                        a->addDistribuicao(intensidade, forma2+1);
                    }
                    cout << endl << "=> Carga adicionada" << endl;
                    break;
                default:
                    cout << "Numero invalido. Tente novamente." << endl;
            }

            break;
        }
        default: {cout << "Numero invalido. Tente novamente." << endl; break;}
    }
}

void interface() {

	cout << "PROGRAMA SOLUCIONADOR DE PROBLEMAS SIMPLES DE MECANICA DAS ESTRUTURAS" << endl << endl;
	cout << "Software desenvolvido por Lucas Marques e Reinaldo Avelino durante a disciplina PEF3208." << endl;
	cout << "========================================================================================" << endl;

	Grafo* estrutura = new Grafo();

	int opcao = -1;

	// Incognitas do sistema 3x3
	double a = 0; char a_nome = 'o';
	double b = 0; char b_nome = 'o'; char b_direcao = 'o';
	double c = 0; char c_nome = 'o';

	while (opcao != 0) {
        cout << endl;
		cout << "Menu de opcoes:" << endl
		     << "0) Encerrar programa" << endl
		     << "1) Adicionar barra" << endl
		     << "2) Adicionar apoio" << endl
		     << "3) Adicionar carga" << endl
		     << "4) Obter reacoes de apoio" << endl
		     << "Digite o numero da opcao: ";
		cin >> opcao;

		switch (opcao) {
			case 0: {delete estrutura; break;}
			case 1: {addBarra(estrutura); break;}
			case 2: {addApoio(estrutura); break;}
			case 3: {addCarga(estrutura); break;}
			case 4: {
                estrutura->equilibrio(a, a_nome,
                                      b, b_nome, b_direcao,
                                      c, c_nome);
                cout << "Reacoes de apoio: " << endl;

                if (a_nome != 'o')
                    cout << "Horizontal em " << a_nome << " : " << a << " i kN" << endl;

                if (b_nome != 'o') {
                    if (b_direcao == 'j')
                        cout << "Vertical em " << b_nome << " : " << b << " j kN" << endl;

                    else if (b_direcao == 'k')
                        cout << "Momento em " << b_nome << " : " << b << " k kNm" << endl;
                }
                if (c_nome != 'o')
                    cout << "Vertical em " << c_nome << " : " << c << " j kN" << endl;

                break;
			}
			default: cout << "Numero invalido. Tente novamente." << endl;
		}
	}
	cout << endl;
	cout << "Programa encerrado. Agradecemos pelo uso." << endl;
	cout << "============================================" << endl;
}

int main() {
	interface();
	return 0;
}
