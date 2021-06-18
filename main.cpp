#include <iostream>
#include <string>

#include "Grafo.h"
using namespace std;

void addBarra(Grafo* estrutura) {
	int opcao = -1;
	while (opcao != 0) {
        cout << "Tipos de barra:" << endl
             << "0) Retornar;" << endl
             << "1) Horizontal;" << endl
             << "2) Vertical;" << endl
             << "3) Inclinada;" << endl
             << "Digite o numero da opcao: ";
        cin >> opcao;

        char nome[2];
        float comprimento;
        cout << "Digite o nome da barra (Por exemplo: AB, CD): ";
        cin >> nome;
        cout << "Digite o comprimento da barra em metros (Utilize ponto): ";
        cin >> comprimento;
        estrutura->adicionarVertice(nome[0]);
        estrutura->adicionarVertice(nome[1]);

        switch (opcao) {
            case 0: break;

            case 1: {
                estrutura->adicionarAresta(nome, comprimento, 0);
                break;
            }

            case 2: {
                estrutura->adicionarAresta(nome, comprimento, 1);
                break;
            }

            case 3: {
                float inclinacao;
                cout << "Digite o angulo de inclinacao com o eixo x em graus (Utilize ponto): ";
                cin >> inclinacao;
                estrutura->adicionarAresta(nome, comprimento, inclinacao);
                break;
            }

            default: {cout << "Numero invalido. Tente novamente." << endl; break;}
        }
	}
}

void addApoio(Grafo* estrutura) {
	int opcao = -1;
	while (opcao != 0) {
        cout << "Tipos de apoio:" << endl
             << "0) Retornar;" << endl
             << "1) Articulacao Movel;" << endl
             << "2) Articulacao Fixa;" << endl
             << "3) Engastamento;" << endl
             << "Digite o numero da opcao:" << endl;
        cin >> opcao;
        switch (opcao) {
            case 0: break;

            case 1: {
                //
                break;
            }

            case 2: {
                //
                break;
            }

            case 3: {
                //
                break;
            }

            default: {cout << "Numero invalido. Tente novamente." << endl; break;}
        }
	}
}

void addCarga(Grafo* estrutura) {
	int opcao = -1;
	while (opcao != 0) {
        cout << "Tipos de carga:" << endl
             << "0) Retornar;" << endl
             << "1) Forca concentrada;" << endl
             << "2) Forca distribuida;" << endl
             << "Digite o numero da opcao:" << endl;
        cin >> opcao;

        switch (opcao) {
            case 0: break;

            case 1: {
                //
                break;
            }

            case 2: {
                //
                break;
            }

            default: {cout << "Numero invalido. Tente novamente." << endl; break;}
        }
	}
}

void interface() {
	cout << "PROGRAMA SOLUCIONADOR DE PROBLEMAS SIMPLES DE MECANICA DAS ESTRUTURAS" << endl << endl;
	cout << "Software desenvolvido por Lucas Marques e Reinaldo Avelino durante a disciplina PEF3208." << endl;
	cout << "========================================================================================" << endl;

	Grafo* estrutura = new Grafo();
	int opcao = -1;
	while (opcao != 0) {
		cout << "Menu de opcoes:" << endl
		     << "0) Encerrar programa;" << endl
		     << "1) Adicionar barra;" << endl
		     << "2) Adicionar apoio;" << endl
		     << "3) Adicionar carga;" << endl
		     << "Digite o numero da opcao: ";
		cin >> opcao;

		switch (opcao) {
			case 0: {delete estrutura; break;}
			case 1: {addBarra(estrutura); break;}
			case 2: {addApoio(estrutura); break;}
			case 3: {addCarga(estrutura); break;}
			default: cout << "Numero invalido. Tente novamente." << endl;
		}
	}
	cout << endl;
	cout << "Programa encerrado. Agradecemos pelo uso." << endl;
	cout << "============================================" << endl;
}

void teste() {
    //
}

int main() {
	//teste();
	interface();
	return 0;
	int x;
}
