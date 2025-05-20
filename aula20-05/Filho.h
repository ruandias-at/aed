#ifndef FILHO_H
#define FILHO_H

#include <iostream>
#include <string>

#include "Pai.h"
using namespace std;

class Filho : public Pai {
    protected:
        string mae;

    public:
        Filho(string nome, int idade, string mae) : Pai(nome, idade) {
            this->mae = mae;
        }

        Filho(string nome, string mae) : Pai(nome, 0) {
            this->mae = mae;
        }

        string getMae() {
            return this->mae;
        }

        void setMae(string mae) {
            this->mae = mae;
        }

        string toString();
};

#endif