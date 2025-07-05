//Aluno Ruan Dias Alves Teixeira
//Matrícula 242014471
//Algoritmo e Estrutura de Dados
#include <iostream>
#include <string>
#include <vector>
#include <cmath>

using namespace std;


class Carro {
    public:
    string fabricante;
    string modelo;
    int ano;
    string placa;


    Carro(string fabricante, string modelo, int ano, string placa) {
        this->fabricante = fabricante;
        this->modelo = modelo;
        this->ano = ano;
        this->placa = placa;
    };

    void set_fabricante(string f) {
        this->fabricante = f;
    }
};
int main() {

    return 0;
}