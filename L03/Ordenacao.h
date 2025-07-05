/*
Aluno: Ruan Dias Alves Teixeira
Matrícula: 242014471
Disciplina: Algoritmos e Estruturas de Dados
Lista 03
*/

// Questão 1 - Ordenacao.h
#ifndef ORDENACAO_H
#define ORDENACAO_H

#include <iostream>
#include <string>
#include <vector>
#include <chrono>
#include <cstdlib>
#include <ctime>

using namespace std;

enum TIPO_CASO {
    PIOR,
    MEDIO,
    MELHOR
};

class Ordenacao {
	protected:
		string nomeAlgoritmo;
		vector<int> dados;
		int quantidade;
		TIPO_CASO caso;
		chrono::high_resolution_clock::time_point inicio;
		chrono::high_resolution_clock::time_point fim;
	
	public:
	
		Ordenacao(string nomeAlgoritmo, int quantidade, TIPO_CASO caso) {
			this->nomeAlgoritmo = nomeAlgoritmo;
			this->quantidade    = quantidade;
			this->caso          = caso;
			srand(static_cast<unsigned int>(time(nullptr)));

			switch (caso) {
				case PIOR:
					for (int i = quantidade; i >= 1; --i)
						dados.push_back(i);
					break;
	
				case MELHOR:
					for (int i = 1; i <= quantidade; ++i)
						dados.push_back(i);
					break;
	
				case MEDIO:
					for (int i = 0; i < quantidade; ++i) {
						int numero = rand() % quantidade + 1;
						dados.push_back(numero);
					}
					break;
			}
		}
	
		void ligaCronometro() {
			this->inicio = chrono::high_resolution_clock::now();
		}

		long long desligaCronometro() {
			this->fim = chrono::high_resolution_clock::now();
			return chrono::duration_cast<chrono::nanoseconds>(fim - inicio).count();
		}

		void imprimeDados() const {
			for (const int& val : dados)
				cout << val << " ";
			cout << "\n";
		}
};

#endif
