/*
    Nome: Ruan Dias Alves Teixeira
    Matrícula: 242014471
*/

#include <iostream>
#include <string>

#include "ContaPJ.h"

using namespace std;

string ContaPJ::toString() {
    return "CNPJ: " + this->CNPJ + "\nRazao Social: " + this->razaoSocial + "\nSaldo: " + to_string(this->saldo);
}