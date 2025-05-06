/*
Nome: Ruan Dias Alves Teixeira
Matrícula: 242014471
Questão: L02Q01
*/

#include <iostream>
#include <string>
#include <vector>
#include <locale>

using namespace std; //Facilita o uso de comandos sem precisar colocar o namespace antes de cada um deles

//Classe Pessoa da Lista 1
//Definindo a classe Pessoa, que possui os atributos privados identificacao, nome e idade
class Pessoa {
    protected:
        string identificacao;
        string nome;
        int idade;
    
    public:
        //Constructor da classe Pessoa, que inicializa os atributos com os valores passados como parâmetro
        Pessoa(string identificacao, string nome, int idade) {
            this->identificacao = identificacao;
            this->nome = nome;
            this->idade = idade;
        }

        //Métodos setters e getters para cada atributo da classe Pessoa, permitindo a manipulação dos dados 'privados'
        void setIdentificacao(string identificacao) {
            this->identificacao = identificacao;
        }

        string getIdentificacao() {
            return identificacao;
        }

        void setNome(string nome) {
            this->nome = nome;
        }

        string getNome() {
            return nome;
        }

        void setIdade(int idade) {
            this->idade = idade;
        }

        int getIdade() {
            return idade;
        }

        //Método que exibe as informações da classe pessoa
        void exibirInfo() {
            cout << "Identificacao: " << identificacao << endl;
            cout << "Nome: " << nome << endl;
            cout << "Idade: " << idade << endl;
        }
};//End Class

// Classe Aluno herdando da classe Pessoa
class Aluno : public Pessoa{
    private:
        string tipo;
        double notaFinal;
        vector<double> notas;


    public:
        //Constructor da classe Aluno, que inicializa os atributos com os valores passados como parâmetro
        Aluno(string nome, string identificacao, int idade, string tipo) : Pessoa(identificacao, nome, idade), tipo(tipo) {
            this->nome = nome;
            this->identificacao = identificacao;
            this->idade = idade;
            this->tipo = tipo;
            this->notaFinal = 0.0;
        }

        //Métodos setters e getters para cada atributo da classe Aluno, permitindo a manipulação dos dados 'privados'
        void setNome(string nome) {
            this->nome = nome;
        }

        string getNome() {
            return nome;
        }

        void setIdentificacao(string identificacao) {
            this->identificacao = identificacao;
        }

        string getIdentificacao() {
            return identificacao;
        }

        //Método que adiciona as notas do aluno no vetor de notas e calcula a média final
        void adicionarNotas(double nota1, double nota2) {
            this->notas.push_back(nota1);
            this->notas.push_back(nota2);
            this->notaFinal = (notas[0] + notas[1]) / 2;
        }

        //Método que exibe todas as informações do aluno
        void imprime() {
            cout << "Nome: " << nome << endl;
            cout << "Identificacao: " << identificacao << endl;
            cout << "Tipo: " << tipo << endl;
            cout << "Nota Final: " << notaFinal << endl;
            //Define a menção do aluno de acordo com a nota final
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

//Classe FormaGeométrica que será a classe pai das classes Retangulo, Círculo e Quadrado
class FormaGeometrica {
    protected:
        int base;
        int altura;

        FormaGeometrica()
};

//Definindo a classe Retangulo, que possui os atributos públicos base e altura
class Retangulo : FormaGeometrica {
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
class Circulo : FormaGeometrica {
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

class Quadrado : FormaGeometrica {
    public:
        int lado;

    Quadrado(int lado) {
        this->lado = lado;
    }

    double calcularArea() {}
}

int main() {
    setlocale(LC_ALL, "Portuguese");

    Aluno a1 = Aluno("Ruan", "242014471", 18, "Aluno de Redes");
    a1.adicionarNotas(9.0, 8.0);
    a1.imprime();
    

    return 0;
}