#include <string>
#include <iostream>

#include "Pai.h"

using namespace std;

Pai::Pai(string nome, int idade) {
    this->nome = nome;
    this->idade = idade;
}

string Pai::toString() {
    return "Pai: " + this->nome;
}

