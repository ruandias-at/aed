/*
Nome: Ruan Dias Alves Teixeira
Matr�cula: 242014471
Quest�o: L02Q01
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
        //Constructor da classe Pessoa, que inicializa os atributos com os valores passados como par�metro
        Pessoa(string identificacao, string nome, int idade) {
            this->identificacao = identificacao;
            this->nome = nome;
            this->idade = idade;
        }

        //M�todos setters e getters para cada atributo da classe Pessoa, permitindo a manipula��o dos dados 'privados'
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

        //M�todo que exibe as informa��es da classe pessoa
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
        //Constructor da classe Aluno, que inicializa os atributos com os valores passados como par�metro
        Aluno(string nome, string identificacao, int idade, string tipo) : Pessoa(identificacao, nome, idade), tipo(tipo) {
            this->nome = nome;
            this->identificacao = identificacao;
            this->idade = idade;
            this->tipo = tipo;
            this->notaFinal = 0.0;
        }

        //M�todos setters e getters para cada atributo da classe Aluno, permitindo a manipula��o dos dados 'privados'
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

        //M�todo que adiciona as notas do aluno no vetor de notas e calcula a m�dia final
        void adicionarNotas(double nota1, double nota2) {
            this->notas.push_back(nota1);
            this->notas.push_back(nota2);
            this->notaFinal = (notas[0] + notas[1]) / 2;
        }

        //M�todo que exibe todas as informa��es do aluno
        void imprime() {
            cout << "Nome: " << nome << endl;
            cout << "Identificacao: " << identificacao << endl;
            cout << "Tipo: " << tipo << endl;
            cout << "Nota Final: " << notaFinal << endl;
            //Define a men��o do aluno de acordo com a nota final
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

//Classe FormaGeom�trica que ser� a classe pai das classes Retangulo, C�rculo e Quadrado
class FormaGeometrica {
    protected:
        int base;
        int altura;

        FormaGeometrica()
};

//Definindo a classe Retangulo, que possui os atributos p�blicos base e altura
class Retangulo : FormaGeometrica {
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
class Circulo : FormaGeometrica {
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