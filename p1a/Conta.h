/*
    Nome: Ruan Dias Alves Teixeira
    Matrícula: 242014471
*/

#ifndef CONTA_H
#define CONTA_H

#include <iostream>
#include <string>

using namespace std;

class Conta {
    protected:
        string numero;
        int saldo;

    public:
        Conta(string numero, int saldo);

        string getNumero() {
            return this->numero;
        }

        void setNumero(string numero) {
            this->numero = numero;
        }

        int getSaldo() {
            return this-> saldo;
        }

        void setSaldo(int saldo) {
            this->saldo = saldo;
        }

        string toString();

        int depositar(int valor);

        bool gastar(int valor);
};

#endif