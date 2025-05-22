/*
    Nome: Ruan Dias Alves Teixeira
    Matrícula: 242014471
*/

#ifndef CONTAPJ_H
#define CONTAPJ_H

#include <iostream>
#include <string>

#include "Conta.h"

using namespace std;

class ContaPJ : public Conta {
    protected:
        string CNPJ;
        string razaoSocial;

    public:
        ContaPJ(string numero, int saldo, string CNPJ, string razaoSocial) : Conta(numero, saldo) {
            this->CNPJ = CNPJ;
            this->razaoSocial = razaoSocial;
        }

        ContaPJ(string numero, string CNPJ, string razaoSocial) : Conta(numero, saldo = 0) {
            this->CNPJ = CNPJ;
            this->razaoSocial = razaoSocial;
        }

        string getCNPJ() {
            return this->CNPJ;
        }

        void setCNPJ(string CNPJ) {
            this->CNPJ = CNPJ;
        }

        string getrazaoSocial() {
            return this->razaoSocial;
        }

        void setrazaoSocial(string razaoSocial) {
            this->razaoSocial = razaoSocial;
        }

        string toString();

};

#endif