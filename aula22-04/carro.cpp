#include <iostream>
#include <vector>
#include <string>
#include <locale>

using namespace std;

// Declaração da classe Carro
class Carro {
    private:
        string fabricante;
        string marca;
        int ano;
        int velocidade;
        vector<string> acessorio;

    public:
        Carro(string fabricante, string marca, int ano) {
            this->fabricante = fabricante;
            this->marca = marca;
            this->ano = ano;
            this->velocidade = 0;
            this->acessorio.push_back("Macaco");
        }

        //getFabricante
        string getFabricante() {
            return fabricante;
        }

        //setFabricante
        void setFabricante(string fabricante) {
            this->fabricante = fabricante;
        }

        //getMarca
        string getMarca() {
            return marca;
        }

        //setMarca
        void setMarca(string marca) {
            this->marca = marca;
        }

        //getAno
        int getAno() {
            return ano;
        }

        //setAno
        void setAno(int ano) {
            this->ano = ano;
        }

        void mudarVelocidade(int mudanca) {
            this->velocidade += mudanca;
            if (this->velocidade < 0) {
                this->velocidade = 0;
            }
        }

        void adicionarAcessorio(string newAcessorio) {
            this->acessorio.push_back(newAcessorio);
        }

        void exibirInfo() {
            cout << "Fabricante: " << this->fabricante << endl;
            cout << "Marca: " << this->marca << endl;
            cout << "Ano: " << this->ano << endl;
            cout << "Velocidade: " << this->velocidade << endl;
            cout << "Acessorios: " << endl;
            for (int i = 0; i < this->acessorio.size(); i++) {
                cout << this->acessorio[i] << " - ";
            }
            cout << endl << "------------------------" << endl;
        }
};

int main() {
    setlocale(LC_ALL, "Portuguese_Brazil.1252");

    Carro c1 = Carro("Fiat", "Palio", 2000);
    c1.exibirInfo();
    c1.mudarVelocidade(72);
    c1.exibirInfo();
    c1.mudarVelocidade(-32);
    c1.exibirInfo();
    c1.adicionarAcessorio("Roda de liga leve");
    c1.adicionarAcessorio("Ar condicionado");
    c1.adicionarAcessorio("Direção hidráulica");
    c1.exibirInfo();
}