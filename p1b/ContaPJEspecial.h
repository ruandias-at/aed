/*
    Nome: Ruan Dias Alves Teixeira
    Matrícula: 242014471
*/

#ifndef CONTAPJESPECIAL_H
#define CONTAPJESPECIAL_H

#include <string>
#include <iostream>

#include "ContaPJ.h"

using namespace std;

class ContaPJEspecial : public ContaPJ{

    protected:
        int limite;

    public:
        ContaPJEspecial(string numero, int saldo, int limite) : ContaPJ(numero, saldo, CNPJ = "CNPJ da Empresa", razaoSocial = "Razao Social da Empresa") {
            this->limite = limite;
        }

        ContaPJEspecial(string numero, int limite) : ContaPJ(numero, saldo = 0, CNPJ = "CNPJ da Empresa", razaoSocial = "Razao Social da Empresa") {
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