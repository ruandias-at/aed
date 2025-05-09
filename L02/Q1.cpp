/*
Nome: Ruan Dias Alves Teixeira
Matr�cula: 242014471
Quest�o: L02Q01
*/

//Importa��o das bibliotecas necess�rias
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

    public:

        FormaGeometrica(int base, int altura) {
            this-> base = base;
            this->altura = altura;
        }

        int calcularArea() {
            return base * altura;
        }
};

//Definindo a classe Retangulo, que possui os atributos p�blicos base e altura
class Retangulo : public FormaGeometrica {

    public:
        //Constructor da classe Retangulo, que inicializa os atributos com os valores passados como par�metro
        Retangulo(int base, int altura) : FormaGeometrica(base, altura){
    }

}; //End Class


class Quadrado : public FormaGeometrica {

    public:
    Quadrado(int lado) : FormaGeometrica(lado, lado){
    }
    
    int calcularArea() {
        return base * base;
    }
};

//Definindo a classe C�rculo, que tamb�m possui os atributos p�blicos base e altura
class Circulo : public FormaGeometrica {
    protected:
        int raio;

    public:
        //Constructor da classe Circulo, que inicializa os atributos com o valor do di�metro passado como par�metro
        Circulo(int diametro) : FormaGeometrica (base, altura) {
            this->raio = diametro / 2;
        }

        //M�todo que retorna a �rea do c�rculo, utilizando a f�rmula pi * (r^2), onde r � o raio (metade do di�metro)
        double calcularArea() {
            return 3.14 * raio * raio;
        }
}; //End Class

class Funcionario {

    protected:
        string nome;
        double salario;

    public:
        Funcionario(string nome, double salario) {
            this->nome = nome;
            this->salario = salario;
        }

        void setNome(string nome) {
            this->nome = nome;
        }

        string getNome() {
            return nome;
        }

        void setSalario(double salario) {
            this->salario = salario;
        }

        double getSalario() {
            return salario;
        }
}; //End Class

class Gerente : public Funcionario {
    
    protected:
        double bonus;

    public:
        Gerente(string nome, double salario, double bonus) : Funcionario(nome, salario) {
            this->bonus = bonus;
        }

        void setBonus(double bonus) {
            this->bonus = bonus;
        }

        double getBonus() {
            return bonus;
        }
}; //End Class


int main() {
    
    setlocale(LC_ALL, "Portuguese"); //Defini��o de local para aceitar caracteres especiais

    //Instanciando um objeto da classe Pessoa e exibindo suas informa��es
    Aluno a1 = Aluno("Ruan", "242014471", 18, "Aluno de Redes");
    a1.adicionarNotas(9.0, 8.0);
    a1.imprime();

    cout << "----------------------------------------" << endl;

    //Instanciando um objeto de cada classe herdade pela classe FormaGeometrica
    Quadrado q1 = Quadrado(5);
    cout << "Area do quadrado: " << q1.calcularArea() << endl;
    Retangulo r1 = Retangulo(5, 10);
    cout << "Area do retangulo: " << r1.calcularArea() << endl;
    Circulo c1 = Circulo(10);
    cout << "Area do circulo: " << c1.calcularArea() << endl;
    
    cout << "----------------------------------------" << endl;

    //Instanciando um objeto da classe Funcionario e um da classe Gerente
    Funcionario f1 = Funcionario("Ruan", 1000);
    Gerente g1 = Gerente("Marcelo", 2000, 500);

    //Exibindo as informa��es do funcion�rio e do gerente
    cout << "Funcionario: " << f1.getNome() << ", Salario: " << f1.getSalario() << endl;
    cout << "Gerente: " << g1.getNome() << ", Salario: " << g1.getSalario() << ", Bonus: " << g1.getBonus() << endl;

    return 0;
}