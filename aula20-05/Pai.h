#ifndef PAI_H
#define PAI_H

#include <string>
#include <iostream>

using namespace std;

class Pai {
    protected:
        string nome;
        int idade;
    
    public:
        Pai(string nome, int idade);

        string getNome() {
            return this-> nome;
        }

        void setNome(string nome) {
            this->nome = nome;
        }

        int getIdade() {
            return this->idade;
        }

        void setIdade(int idade) {
            this->idade = idade;
        }

        string toString();
};

#endif