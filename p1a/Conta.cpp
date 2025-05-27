/*
    Nome: Ruan Dias Alves Teixeira
    Matrícula: 242014471
*/

#include <iostream>
#include <string>

#include "Conta.h"

using namespace std;

Conta::Conta(string numero, int saldo) {
    this->numero = numero;
    this->saldo = saldo;
}

string Conta::toString() {
    return "Saldo atual: " + this->saldo;
}

int Conta::depositar(int valor) {
    if (valor >= 0) {
        this->saldo += valor;
        cout << "Deposito no valor de R$" + to_string(valor) + ",00 concluido." << endl << "--------------------" << endl;
        return this->saldo;
    } else {
        cout << "Valor do deposito invalido" << endl;
        return 0;
    }
}

bool Conta::gastar(int valor) {
    if (valor <= this->saldo and valor >= 0) {
        this-> saldo -= valor;
        cout << "Saque realizado no valor de R$" + to_string(valor) + ",00 concluido." << endl << "-------------------" << endl;
        return true;
    } else if (valor < 0) {
        cout << "Valor invalido." << endl;
        return false;
    } else {
        cout << "Saldo insuficiente." << endl;
        return false;
    }
}