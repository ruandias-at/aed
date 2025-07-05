/*
Aluno: Ruan Dias Alves Teixeira
Matrícula: 242014471
Disciplina: Algoritmos e Estruturas de Dados
Lista 03
*/

// Questão 2 - Classes de ordenacao
#ifndef ORDENACAOPORTROCA_H
#define ORDENACAOPORTROCA_H

#include "Ordenacao.h"

class OrdenacaoPorTroca : public Ordenacao {
public:
    OrdenacaoPorTroca(string nome, int qtd, TIPO_CASO caso) : Ordenacao(nome, qtd, caso) {}

    long long BubbleSort() {
        ligaCronometro();
        for (int i = 0; i < quantidade - 1; ++i) {
            for (int j = 0; j < quantidade - i - 1; ++j) {
                if (dados[j] > dados[j + 1])
                    swap(dados[j], dados[j + 1]);
            }
        }
        desligaCronometro();
    }

    long long QuickSort() {
        ligaCronometro();
        quickSort(0, quantidade - 1);
        desligaCronometro();
    }

private:
    void quickSort(int baixo, int alto) {
        if (baixo < alto) {
            int pi = partition(baixo, alto);
            quickSort(baixo, pi - 1);
            quickSort(pi + 1, alto);
        }
    }

    int partition(int baixo, int alto) {
        int pivo = dados[alto];
        int i = baixo - 1;
        for (int j = baixo; j < alto; ++j) {
            if (dados[j] <= pivo) {
                ++i;
                swap(dados[i], dados[j]);
            }
        }
        swap(dados[i + 1], dados[alto]);
        return i + 1;
    }
};

#endif
