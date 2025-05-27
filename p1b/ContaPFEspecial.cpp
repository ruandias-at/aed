/*
    Nome: Ruan Dias Alves Teixeira
    Matrícula: 242014471
*/

#include <iostream>
#include <string>

#include "ContaPFEspecial.h"

using namespace std;

string ContaPFEspecial::toString() {
    return "Numero da conta PF: " + this->numero + "\nSaldo da conta: " + to_string(this->saldo) + "\nLimite da conta: " + to_string(this->limite);
}

int ContaPFEspecial::depositar(int valor) {
    if (valor < 0) {
        cout << "Valor Invalido" << endl;
        return 0;
    } else {
        saldo += valor;
        cout << "Deposito no valor de R$" << valor << ",00 realizado com sucesso." << endl;
        return saldo;
    }
}

bool ContaPFEspecial::gastar(int valor) {
    if (valor < 0) {
        cout << "Valor Invalido" << endl;
        return false;
    } else if (valor > this->saldo + this->limite) {
        cout << "Saque nao permitido" << endl;
        return false;
    } else {
        saldo -= valor;
        limite += saldo;
        saldo = 0;
        cout << "Saque no valor de R$" << valor << ",00 realizado com sucesso" << endl;
        return true;
    }
}