#include <iostream>
#include <string>
#include <vector>
#include <locale>

using namespace std;

class Carro {
    public:
        string marca;
        string modelo;
        int ano;
        int velocidade;

    Carro(string marca, string modelo, int ano) {
        this->marca = marca;
        this->modelo = modelo;
        this->ano = ano;
        this->velocidade = 0;
    }

    void acelerar(int incremento) {
        this->velocidade += incremento;
        if (this->velocidade < 0) {
            this->velocidade = 0;
        }
    }

    void frear() {
        this->velocidade = 0;
    }

    void exibirInfo() {
        cout << "Marca: " << marca << endl;
        cout << "Modelo: " << modelo << endl;
        cout << "Ano: " << ano << endl;
        cout << "Velocidade: " << velocidade << " km/h." << endl;
    }
}; //End Class

class Retangulo {
    public:
        int base;
        int altura;

    Retangulo(int base, int altura) {
        this->base = base;
        this->altura = altura;
    }

    int calcularArea() {
        return base * altura;
    }
}; //End Class

class Circulo {
    public:
        int base;
        int altura;

    Circulo(int diametro) {
        this->base = this->altura = diametro;
    }

    double calcularArea() {
        double raio = base / 2; 
        return 3.14 * raio * raio;
    }
};

int main() {
    setlocale(LC_ALL, "Portuguese");

    vector<Carro> carros;

    carros.push_back(Carro("Fusca", "Volkswagen", 1970));
    carros.push_back(Carro("Civic", "Honda", 2020));
    carros.push_back(Carro("Etios", "Toyota", 2014));
    carros.push_back(Carro("Mustang", "Ford", 2021));

    for (int i = 0; i < carros.size(); i++) {
        carros[i].exibirInfo();
        cout << "------------------------" << endl;
    }

    carros[1].acelerar(50);
    carros[1].exibirInfo();
    carros[1].frear();
    carros[1].exibirInfo();
    carros[1].acelerar(-30);
    carros[1].exibirInfo();

    Circulo c1 = Circulo(10);
    Retangulo r1 = Retangulo(10, 20);
    cout << "Area do circulo: " << c1.calcularArea() << endl;
    cout << "Area do retangulo: " << r1.calcularArea() << endl;

    return 0;
}