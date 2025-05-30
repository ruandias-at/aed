/*
Nome: Ruan Dias Alves Teixeira
Matrícula: 242014471
Questão: L02Q04
*/

// Importação das bibliotecas necessárias
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
        virtual double calcularArea() = 0; // Método virtual puro
        virtual void exibirInfo() = 0; // Método virtual puro
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
            cout << "Retângulo: Base = " << base << ", Altura = " << altura << ", Área = " << calcularArea() << endl;
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
            cout << "Círculo: Raio = " << raio << ", Área = " << calcularArea() << endl;
        }
};


//Defina uma classe abstrata instrumento musical com um método virtual puro tocar(). Derive em classes Violao e Piano mudando a implementação do método tocar(). Instancie uma classe instrumento musical e faça ela tocar().
class InstrumentoMusical {
    public:
        virtual void tocar() = 0;
};

class Violao : public InstrumentoMusical {
    public:
        void tocar() override {
            cout << "Tocando violão" << endl;
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
    //Não é possível instanciar uma classe abstrata, mas sim as classes derivadas

    InstrumentoMusical *violao = new Violao();
    InstrumentoMusical *piano = new Piano();

    violao->tocar();
    piano->tocar();

    cout << "-----------------------------" << endl;


    return 0;
}