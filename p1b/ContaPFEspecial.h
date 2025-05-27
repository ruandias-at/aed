/*
    Nome: Ruan Dias Alves Teixeira
    Matrícula: 242014471
*/

#ifndef CONTAPFESPECIAL_H
#define CONTAPFESPECIAL_H

#include <string>
#include <iostream>

#include "ContaPF.h"

using namespace std;

class ContaPFEspecial : public ContaPF{

    protected:
        int limite;

    public:
        ContaPFEspecial(string numero, int saldo, int limite) : ContaPF(numero, saldo, CPF = "CPF do Titular", titular = "Nome do Titular") {
            this->limite = limite;
        }

        ContaPFEspecial(string numero, int limite) : ContaPF(numero, saldo = 0, CPF = "CPF do Titular", titular = "Nome do Titular") {
            this->limite = limite;
        }

        int getLimite() {
            return this->limite;
        }

        void setLimite(int limite) {
            this->limite = limite;
        }

        int depositar(int valor);

        bool gastar(int valor);

        string toString();
}; 



#endif