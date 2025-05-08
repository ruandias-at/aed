/*
Nome: Ruan Dias Alves Teixeira
Matr�cula: 242014471
Quest�o: L01Q02
*/

//Importando todas as bibliotecas necess�rias para a quest�o
#include <iostream> //Importa os comandos para entrada e sa�da de dados
#include <string> //Possibilita a Manipula��o de strings
#include <vector> //Possibilita a manipula��o de vetores
#include <locale> //Possibilita definir o local, para poder ter acesso aos caracteres especiais
#include <fstream> //Possibilita a manipula��o e leitura de arquivos

using namespace std; //Facilita o uso de comandos sem precisar colocar o namespace antes de cada um deles

//Definindo a classe Carro, que possui os atributos p�blicos marca, modelo, ano e velocidade
class Carro {
    public:
        string marca;
        string modelo;
        int ano;
        int velocidade;

    //Constructor da classe carro, que inicializa os atributos com os valores passados como par�metro
    Carro(string marca, string modelo, int ano) {
        this->marca = marca;
        this->modelo = modelo;
        this->ano = ano;
        this->velocidade = 0;
    }

    //M�todo da classe carro  que permite aumentar a velocidade do carro, com o valor passado como par�metro
    void acelerar(int incremento) {
        this->velocidade += incremento;
        if (this->velocidade < 0) { //N�o permite que a velocidade seja negativa
            this->velocidade = 0;
        }
    }

    //M�todo que permite frear o carro, zerando a velocidade
    void frear() {
        this->velocidade = 0;
    }

    //M�todo que exibe todas as informa��es do carro
    void exibirInfo() {
        cout << "Marca: " << marca << endl;
        cout << "Modelo: " << modelo << endl;
        cout << "Ano: " << ano << endl;
        cout << "Velocidade: " << velocidade << " km/h." << endl;
    }
}; //End Class

//Definindo a classe Retangulo, que possui os atributos p�blicos base e altura
class Retangulo {
    public:
        int base;
        int altura;

    //Constructor da classe Retangulo, que inicializa os atributos com os valores passados como par�metro
    Retangulo(int base, int altura) {
        this->base = base;
        this->altura = altura;
    }

    //M�todo que retorna a �rea do ret�ngulo, multiplicando a base pela altura
    int calcularArea() {
        return base * altura;
    }
}; //End Class

//Definindo a classe C�rculo, que tamb�m possui os atributos p�blicos base e altura
class Circulo {
    public:
        int base;
        int altura;

    //Constructor da classe Circulo, que inicializa os atributos com o valor do di�metro passado como par�metro
    Circulo(int diametro) {
        this->base = this->altura = diametro;
    }

    //M�todo que retorna a �rea do c�rculo, utilizando a f�rmula pi * (r^2), onde r � o raio (metade do di�metro)
    double calcularArea() {
        double raio = base / 2; 
        return 3.14 * raio * raio;
    }
}; //End Class

//Classe aluno importada da quest�o 1
class Aluno {
    public:
        string nome;
        string identificacao;
        string tipo;
        double notaFinal;
        vector<double> notas;

    Aluno(string nome, string identificacao) {
        this->nome = nome;
        this->identificacao = identificacao;
        this->tipo = "Aluno UnB";
        this->notaFinal = 0.0;
    }

    void adicionarNotas(double nota1, double nota2, double nota3) {
        this->notas.push_back(nota1);
        this->notas.push_back(nota2);
        this->notas.push_back(nota3);
        this->notaFinal = (notas[0] + notas[1] + notas[2]) / 3;
    }

    void imprime() {
        cout << "Nome: " << nome << endl;
        cout << "Identificacao: " << identificacao << endl;
        cout << "Tipo: " << tipo << endl;
        cout << "Nota Final: " << notaFinal << endl;
        if (notaFinal >= 9) {
            cout << "SS" << endl;
        } else if (notaFinal >= 7) {
            cout << "MS" << endl;
        } else if (notaFinal >= 5) {
            cout << "MM" << endl;
        } else if (notaFinal >= 3) {
            cout << "MI" << endl;
        } else if (notaFinal > 0) {
            cout << "II" << endl;
        } else {
            cout << "SR" << endl;
        }
    }
};//End Class

//Fun��o principal do programa
int main() {
    setlocale(LC_ALL, "Portuguese"); //Define o local pra Portugu�s, permitindo o uso de caracteres especiais

    vector<Carro> carros; //Inicializa um vetor de objetos do tipo Carro

    //Cria 4 inst�ncias da classe carro e adiciona ao vetor carros.
    carros.push_back(Carro("Fusca", "Volkswagen", 1970));
    carros.push_back(Carro("Civic", "Honda", 2020));
    carros.push_back(Carro("Etios", "Toyota", 2014));
    carros.push_back(Carro("Mustang", "Ford", 2021));

    //La�o de repeti��o que vai passar por todos os itens do vetor carros
    for (int i = 0; i < carros.size(); i++) {
        carros[i].exibirInfo(); //Chama o m�todo que exibe as informa��es do carro
        cout << "------------------------" << endl;
    }

    //Acelera o carro e depois exibe as informa��es do carro
    carros[1].acelerar(50);
    carros[1].exibirInfo();
    //Freia o carro e depois exibe as informa��es do carro
    carros[1].frear();
    carros[1].exibirInfo();
    //Acelera o carro com um valor negativo, e depois exibe as informa��es do carro
    carros[1].acelerar(-30);
    carros[1].exibirInfo();

    //Cria uma inst�ncia da classe c�rculo e uma da classe ret�ngulo passando os respectivos par�metros
    Circulo c1 = Circulo(10);
    Retangulo r1 = Retangulo(10, 20);
    //Mostra as �reas do c�rculo e do tri�ngulo, chamando os m�todos que calculam as �reas
    cout << "Area do circulo: " << c1.calcularArea() << endl;
    cout << "Area do retangulo: " << r1.calcularArea() << endl;

    fstream arquivo("alunos.csv", ios::out);
    arquivo.open();

    
    return 0; //Fim do programa
}