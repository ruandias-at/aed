/*
Nome: Ruan Dias Alves Teixeira
Matr�cula: 242014471
Quest�o: L02Q04
*/

// Importa��o das bibliotecas necess�rias
#include <iostream>
#include <string>
#include <locale>

using namespace std;

//Reimplementando a classe FormaGeometrica para ser virtual pura
class FormaGeometrica {
    protected:
        int base;
        int altura;

    public:
        virtual double calcularArea() = 0; // M�todo virtual puro
        virtual void exibirInfo() = 0; // M�todo virtual puro
};

// Classe Retangulo que herda de FormaGeometrica
class Retangulo : public FormaGeometrica {
    public:
        Retangulo(int base, int altura) {
            this->base = base;
            this->altura = altura;
        }

        double calcularArea() override {
            return base * altura;
        }

        void exibirInfo() override {
            cout << "Ret�ngulo: Base = " << base << ", Altura = " << altura << ", �rea = " << calcularArea() << endl;
        }
};

// Classe Circulo que herda de FormaGeometrica
class Circulo : public FormaGeometrica {
    private:
        double raio;

    public:
        Circulo(double raio) {
            this->raio = raio;
        }

        double calcularArea() override {
            return 3.14 * (raio * raio);
        }

        void exibirInfo() override {
            cout << "C�rculo: Raio = " << raio << ", �rea = " << calcularArea() << endl;
        }
};


//Defina uma classe abstrata instrumento musical com um m�todo virtual puro tocar(). Derive em classes Violao e Piano mudando a implementa��o do m�todo tocar(). Instancie uma classe instrumento musical e fa�a ela tocar().
class InstrumentoMusical {
    public:
        virtual void tocar() = 0;
};

class Violao : public InstrumentoMusical {
    public:
        void tocar() override {
            cout << "Tocando viol�o" << endl;
        }
};

class Piano : public InstrumentoMusical {
    public:
        void tocar() override {
            cout << "Tocando piano" << endl;
        }
};

int main() {

    class FormaGeometrica *forma1 = new Retangulo(5, 10);
    class FormaGeometrica *forma2 = new Circulo(7.5);

    forma1->exibirInfo();
    forma2->exibirInfo();

    cout << "-----------------------------" << endl;

    //Instanciando classe InstrumentoMusical
    // InstrumentoMusical *inst1 = new InstrumentoMusical();
    // inst1.tocar();
    //N�o � poss�vel instanciar uma classe abstrata, mas sim as classes derivadas

    InstrumentoMusical *violao = new Violao();
    InstrumentoMusical *piano = new Piano();

    violao->tocar();
    piano->tocar();

    cout << "-----------------------------" << endl;


    return 0;
}