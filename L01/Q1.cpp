/*
Nome: Ruan Dias Alves Teixeira
Matrícula: 242014471
Questão: L01Q01
*/
#include <iostream>
#include <string>
#include <vector>
#include <locale>

using namespace std;

class Formula {
    public:
        int tag;

    Formula(int tag) {
        this->tag = tag;
    }
};

class Pessoa {
    public:
        string identificacao;
        string nome;
        int idade;

    Pessoa(string identificacao, string nome, int idade) {
        this->identificacao = identificacao;
        this->nome = nome;
        this->idade = idade;
    }

    void exibirInfo() {
        cout << "Identificacao: " << identificacao << endl;
        cout << "Nome: " << nome << endl;
        cout << "Idade: " << idade << endl;
    }
};

class Divisao {
    public:
        int numero1;
        int numero2;

    Divisao(int numero1, int numero2) {
        this->numero1 = numero1;
        this->numero2 = numero2;
    }

    double dividir(int numero1, int numero2) {
        if (numero2 == 0) {
            return 0;
        }
        return numero1 / numero2;
    }

    void imprimir() {
        if (numero2 == 0) {
            cout << "Divisão por zero não é permitida." << endl;
            return;
        }
        cout << "Resultado: " << dividir(numero1, numero2) << endl;
    }
};

class Produto {
    public: 
        string nome;
        double preco;

    Produto(string nome, double preco) {
        this->nome = nome;
        this->preco = preco;
    }

    void comparar(Produto outro) {
        if (this->preco > outro.preco) {
            cout << this->nome << " é mais caro que " << outro.nome << endl;
        } else if (this->preco < outro.preco) {
            cout << this->nome << " é mais barato que " << outro.nome << endl;
        } else {
            cout << this->nome << " e " << outro.nome << " têm o mesmo preço." << endl;
        }
    }
};

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

    void adicionarNotas(double nota1, double nota2) {
        this->notas.push_back(nota1);
        this->notas.push_back(nota2);
        this->notaFinal = (notas[0] + notas[1]) / 2;
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
};

int main() {
    setlocale(LC_ALL, "Portuguese");
    
    Formula f1 = Formula(0);
    Formula f2 = Formula(1);
    cout << "Tag da fórmula 1: " << f1.tag << endl;
    cout << "Tag da fórmula 2: " << f2.tag << endl;

    Pessoa p1 = Pessoa("123456789", "Ruan", 20);
    Pessoa p2 = Pessoa("987654321", "Maria", 25);
    Pessoa p3 = Pessoa("456789123", "João", 30);
    p1.exibirInfo();
    p2.exibirInfo();
    p3.exibirInfo();

    Divisao d1 = Divisao(4, 2);
    Divisao d2 = Divisao(10, 0);
    d1.imprimir();
    d2.imprimir();

    Produto prod1 = Produto("Produto A", 10.0);
    Produto prod2 = Produto("Produto B", 15.0);
    Produto prod3 = Produto("Produto C", 10.0);
    prod1.comparar(prod2);
    prod2.comparar(prod3);

    Aluno a1 = Aluno("Ruan", "242014471");
    a1.adicionarNotas(7.2, 8.5);
    a1.imprime();

    return 0;
}