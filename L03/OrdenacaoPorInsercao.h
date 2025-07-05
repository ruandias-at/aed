/*
Aluno: Ruan Dias Alves Teixeira
Matrícula: 242014471
Disciplina: Algoritmos e Estruturas de Dados
Lista 03
*/

// Questão 2 - Classes de ordenacao
#ifndef ORDENACAOPORINSERCAO_H
#define ORDENACAOPORINSERCAO_H

#include "Ordenacao.h"

class OrdenacaoPorInsercao : public Ordenacao {
public:
    OrdenacaoPorInsercao(string nome, int qtd, TIPO_CASO caso) : Ordenacao(nome, qtd, caso) {}

    long long InsertionSort() {
        ligaCronometro();
        for (int i = 1; i < quantidade; ++i) {
            int chave = dados[i];
            int j = i - 1;
            while (j >= 0 && dados[j] > chave) {
                dados[j + 1] = dados[j];
                --j;
            }
            dados[j + 1] = chave;
        }
        desligaCronometro();
    }

    long long ShellSort() {
        ligaCronometro();
        for (int intervalo = quantidade / 2; intervalo > 0; intervalo /= 2) {
            for (int i = intervalo; i < quantidade; ++i) {
                int temp = dados[i];
                int j;
                for (j = i; j >= intervalo && dados[j - intervalo] > temp; j -= intervalo)
                    dados[j] = dados[j - intervalo];
                dados[j] = temp;
            }
        }
        desligaCronometro();
    }
};

#endif
