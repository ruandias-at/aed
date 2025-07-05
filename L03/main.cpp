/*
Aluno: Ruan Dias Alves Teixeira
Matrícula: 242014471
Disciplina: Algoritmos e Estruturas de Dados
Lista 03
*/

// Questão 3 - Main.cpp
#include <iostream>
#include <fstream>
#include <string>
#include "OrdenacaoPorTroca.h"
#include "OrdenacaoPorSelecao.h"
#include "OrdenacaoPorInsercao.h"
#include "OrdenacaoPorMistura.h"

using namespace std;

void exportCSV(const string& nomeArquivo, int quantidade, long long tempo) {
    ofstream file(nomeArquivo, ios::app);
    if (file.is_open()) {
        file << quantidade << ";" << tempo << "\n";
        file.close();
    }
}

int main() {
    const string matricula = "242014471";
    const int casos[] = { MELHOR, PIOR, MEDIO };
    const string nomeCasos[] = { "MELHOR", "PIOR", "MEDIO" };

    for (int c = 0; c < 3; ++c) {
        TIPO_CASO caso = static_cast<TIPO_CASO>(casos[c]);
        string nomeCaso = nomeCasos[c];

        for (int i = 1; i <= 10; ++i) {
            int quantidade = i * 1000;

            // --- Troca ---
            {
                // BubbleSort
                OrdenacaoPorTroca bubble("BubbleSort", quantidade, caso);
                long long tempoBubble = bubble.BubbleSort();
                exportCSV("CSV/BubbleSort__" + nomeCaso + "__" + matricula + ".csv", quantidade, tempoBubble);

                // QuickSort
                OrdenacaoPorTroca quick("QuickSort", quantidade, caso);
                long long tempoQuick = quick.QuickSort();
                exportCSV("CSV/QuickSort__" + nomeCaso + "__" + matricula + ".csv", quantidade, tempoQuick);
            }

            // --- Seleção ---
            {
                // SelectionSort
                OrdenacaoPorSelecao selection("SelectionSort", quantidade, caso);
                long long tempoSelection = selection.SelectionSort();
                exportCSV("CSV/SelectionSort__" + nomeCaso + "__" + matricula + ".csv", quantidade, tempoSelection);

                // Heapsort
                OrdenacaoPorSelecao heap("HeapSort", quantidade, caso);
                long long tempoHeap = heap.Heapsort();
                exportCSV("CSV/HeapSort__" + nomeCaso + "__" + matricula + ".csv", quantidade, tempoHeap);
            }

            // --- Inserção ---
            {
                // InsertionSort
                OrdenacaoPorInsercao insertion("InsertionSort", quantidade, caso);
                long long tempoInsertion = insertion.InsertionSort();
                exportCSV("CSV/InsertionSort__" + nomeCaso + "__" + matricula + ".csv", quantidade, tempoInsertion);

                // ShellSort    
                OrdenacaoPorInsercao shell("ShellSort", quantidade, caso);
                long long tempoShell = shell.ShellSort();
                exportCSV("CSV/ShellSort__" + nomeCaso + "__" + matricula + ".csv", quantidade, tempoShell);
            }

            // --- Mistura ---
            {
                // MergeSort
                OrdenacaoPorMistura merge("MergeSort", quantidade, caso);
                long long tempoMerge = merge.MergeSort();
                exportCSV("CSV/MergeSort__" + nomeCaso + "__" + matricula + ".csv", quantidade, tempoMerge);

                // TimSort
                OrdenacaoPorMistura tim("TimSort", quantidade, caso);
                long long tempoTim = tim.TimSort();
                exportCSV("CSV/TimSort__" + nomeCaso + "__" + matricula + ".csv", quantidade, tempoTim);
            }

            cout << nomeCaso << " CASO: " << quantidade << " CONCLUIDO" << endl;
        }
    }

    cout << "FIM DO PROGRAMA" << endl;
    return 0;
}
