/*
Aluno: Ruan Dias Alves Teixeira
Matrícula: 242014471
Disciplina: Algoritmos e Estruturas de Dados
Lista 03
*/

// Questão 2 - Classes de ordenacao
#ifndef ORDENACAOPORSELECAO_H
#define ORDENACAOPORSELECAO_H

#include "Ordenacao.h"

class OrdenacaoPorSelecao : public Ordenacao {
public:
    OrdenacaoPorSelecao(string nome, int qtd, TIPO_CASO caso) : Ordenacao(nome, qtd, caso) {}

    long long SelectionSort() {
        ligaCronometro();
        for (int i = 0; i < quantidade - 1; ++i) {
            int primeiro = i;
            for (int j = i + 1; j < quantidade; ++j)
                if (dados[j] < dados[primeiro])
                    primeiro = j;
            swap(dados[i], dados[primeiro]);
        }
        desligaCronometro();
    }

    long long Heapsort() {
        ligaCronometro();
        for (int i = quantidade / 2 - 1; i >= 0; --i)
            heapify(quantidade, i);
        for (int i = quantidade - 1; i > 0; --i) {
            swap(dados[0], dados[i]);
            heapify(i, 0);
        }
        desligaCronometro();
    }

private:
    void heapify(int n, int i) {
        int maior = i;
        int esq = 2 * i + 1;
        int dir = 2 * i + 2;

        if (esq < n && dados[esq] > dados[maior])
            maior = esq;
        if (dir < n && dados[dir] > dados[maior])
            maior = dir;
        if (maior != i) {
            swap(dados[i], dados[maior]);
            heapify(n, maior);
        }
    }
};

#endif
