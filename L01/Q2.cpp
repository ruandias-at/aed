/*
Nome: Ruan Dias Alves Teixeira
Matrícula: 242014471
Questão: L01Q02
*/
//Importando todas as bibliotecas necessárias para a questão
#include <iostream> //Importa os comandos para entrada e saída de dados
#include <string> //Possibilita a Manipulação de strings
#include <vector> //Possibilita a manipulação de vetores
#include <locale> //Possibilita definir o local, para poder ter acesso aos caracteres especiais

using namespace std; //Facilita o uso de comandos sem precisar colocar o namespace antes de cada um deles

//Definindo a classe Carro, que possui os atributos públicos marca, modelo, ano e velocidade
class Carro {
    public:
        string marca;
        string modelo;
        int ano;
        int velocidade;

    //Constructor da classe carro, que inicializa os atributos com os valores passados como parâmetro
    Carro(string marca, string modelo, int ano) {
        this->marca = marca;
        this->modelo = modelo;
        this->ano = ano;
        this->velocidade = 0;
    }

    //Método da classe carro  que permite aumentar a velocidade do carro, com o valor passado como parâmetro
    void acelerar(int incremento) {
        this->velocidade += incremento;
        if (this->velocidade < 0) { //Não permite que a velocidade seja negativa
            this->velocidade = 0;
        }
    }

    //Método que permite frear o carro, zerando a velocidade
    void frear() {
        this->velocidade = 0;
    }

    //Método que exibe todas as informações do carro
    void exibirInfo() {
        cout << "Marca: " << marca << endl;
        cout << "Modelo: " << modelo << endl;
        cout << "Ano: " << ano << endl;
        cout << "Velocidade: " << velocidade << " km/h." << endl;
    }
}; //End Class

//Definindo a classe Retangulo, que possui os atributos públicos base e altura
class Retangulo {
    public:
        int base;
        int altura;

    //Constructor da classe Retangulo, que inicializa os atributos com os valores passados como parâmetro
    Retangulo(int base, int altura) {
        this->base = base;
        this->altura = altura;
    }

    //Método que retorna a área do retângulo, multiplicando a base pela altura
    int calcularArea() {
        return base * altura;
    }
}; //End Class

//Definindo a classe Círculo, que também possui os atributos públicos base e altura
class Circulo {
    public:
        int base;
        int altura;

    //Constructor da classe Circulo, que inicializa os atributos com o valor do diâmetro passado como parâmetro
    Circulo(int diametro) {
        this->base = this->altura = diametro;
    }

    //Método que retorna a área do círculo, utilizando a fórmula pi * (r^2), onde r é o raio (metade do diâmetro)
    double calcularArea() {
        double raio = base / 2; 
        return 3.14 * raio * raio;
    }
}; //End Class

//Função principal do programa
int main() {
    setlocale(LC_ALL, "Portuguese"); //Define o local pra Português, permitindo o uso de caracteres especiais

    vector<Carro> carros; //Inicializa um vetor de objetos do tipo Carro

    //Cria 4 instâncias da classe carro e adiciona ao vetor carros.
    carros.push_back(Carro("Fusca", "Volkswagen", 1970));
    carros.push_back(Carro("Civic", "Honda", 2020));
    carros.push_back(Carro("Etios", "Toyota", 2014));
    carros.push_back(Carro("Mustang", "Ford", 2021));

    //Laço de repetição que vai passar por todos os itens do vetor carros
    for (int i = 0; i < carros.size(); i++) {
        carros[i].exibirInfo(); //Chama o método que exibe as informações do carro
        cout << "------------------------" << endl;
    }

    //Acelera o carro e depois exibe as informações do carro
    carros[1].acelerar(50);
    carros[1].exibirInfo();
    //Freia o carro e depois exibe as informações do carro
    carros[1].frear();
    carros[1].exibirInfo();
    //Acelera o carro com um valor negativo, e depois exibe as informações do carro
    carros[1].acelerar(-30);
    carros[1].exibirInfo();

    //Cria uma instância da classe círculo e uma da classe retângulo passando os respectivos parâmetros
    Circulo c1 = Circulo(10);
    Retangulo r1 = Retangulo(10, 20);
    //Mostra as áreas do círculo e do triângulo, chamando os métodos que calculam as áreas
    cout << "Area do circulo: " << c1.calcularArea() << endl;
    cout << "Area do retangulo: " << r1.calcularArea() << endl;

    return 0; //Fim do programa
}