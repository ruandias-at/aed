/*
    Nome: Ruan Dias Alves Teixeira
    Matrícula: 242014471
*/

#ifndef CONTAPF_H
#define CONTAPF_H

#include <iostream>
#include <string>

#include "Conta.h"

using namespace std;

class ContaPF : public Conta {
    protected:
        string CPF;
        string titular;

    public:
        ContaPF(string numero, int saldo, string CPF, string titular) : Conta(numero, saldo) {
            this->CPF = CPF;
            this->titular = titular;
        }

        ContaPF(string numero, string CPF, string titular) : Conta(numero, saldo = 0) {
            this->CPF = CPF;
            this->titular = titular;
        }

        string getCPF() {
            return this->CPF;
        }

        void setCPF(string CPF) {
            this->CPF = CPF;
        }

        string getTitular() {
            return this->titular;
        }

        void setTitular(string titular) {
            this->titular = titular;
        }

        string toString();

};

#endif