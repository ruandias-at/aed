/*
Aluno: Ruan Dias Alves Teixeira
Matrícula: 242014471
Disciplina: Algoritmos e Estruturas de Dados
Lista 03
*/

// Questão 2 - Classes de ordenacao
#ifndef ORDENACAOPORMISTURA_H
#define ORDENACAOPORMISTURA_H

#include "Ordenacao.h"

class OrdenacaoPorMistura : public Ordenacao {
public:
    OrdenacaoPorMistura(string nome, int qtd, TIPO_CASO caso) : Ordenacao(nome, qtd, caso) {}

    long long MergeSort() {
        ligaCronometro();
        mergeSort(0, quantidade - 1);
        desligaCronometro();
    }

    long long TimSort() {
        ligaCronometro();
        const int a = 32;

        for (int i = 0; i < quantidade; i += a)
            insertionSort(i, min((i + a - 1), (quantidade - 1)));

        for (int max = a; max < quantidade; max *= 2) {
            for (int esquerda = 0; esquerda < quantidade; esquerda += 2 * max) {
                int meio = min(esquerda + max - 1, quantidade - 1);
                int direita = min((esquerda + 2 * max - 1), (quantidade - 1));
                if (meio < direita)
                    merge(esquerda, meio, direita);
            }
        }
        desligaCronometro();
    }

private:
    void insertionSort(int esquerda, int direita) {
        for (int i = esquerda + 1; i <= direita; ++i) {
            int temp = dados[i];
            int j = i - 1;
            while (j >= esquerda && dados[j] > temp) {
                dados[j + 1] = dados[j];
                --j;
            }
            dados[j + 1] = temp;
        }
    }

    void merge(int l, int m, int r) {
        int len1 = m - l + 1;
        int len2 = r - m;

        vector<int> esquerda(len1), direita(len2);

        for (int i = 0; i < len1; ++i)
            esquerda[i] = dados[l + i];
        for (int i = 0; i < len2; ++i)
            direita[i] = dados[m + 1 + i];

        int i = 0, j = 0, k = l;

        while (i < len1 && j < len2) {
            if (esquerda[i] <= direita[j])
                dados[k++] = esquerda[i++];
            else
                dados[k++] = direita[j++];
        }

        while (i < len1)
            dados[k++] = esquerda[i++];
        while (j < len2)
            dados[k++] = direita[j++];
    }

    void mergeSort(int esquerda, int direita) {
        if (esquerda < direita) {
            int meio = esquerda + (direita - esquerda) / 2;
            mergeSort(esquerda, meio);
            mergeSort(meio + 1, direita);
            merge(esquerda, meio, direita);
        }
    }
};

#endif
