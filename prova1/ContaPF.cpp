/*
    Nome: Ruan Dias Alves Teixeira
    Matr�cula: 242014471
*/

#include <iostream>
#include <string>

#include "ContaPF.h"

using namespace std;

string ContaPF::toString() {
    return "CPF: " + this->CPF + "\nTitular: " + this->titular + "\nSaldo: " + to_string(this->saldo);
}