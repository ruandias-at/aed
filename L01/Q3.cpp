#include <iostream>
#include <string>
#include <vector>
#include <locale>

using namespace std;

class Pessoa {
    private:
        string identificacao;
        string nome;
        int idade;

    public:
        Pessoa(string identificacao, string nome, int idade) {
            this->identificacao = identificacao;
            this->nome = nome;
            this->idade = idade;
        }

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

        void exibirInfo() {
            cout << "Identificacao: " << identificacao << endl;
            cout << "Nome: " << nome << endl;
            cout << "Idade: " << idade << endl;
        }
};//End Class

class Produto {
    private: 
        string nome;
        double preco;
    
    public:
        Produto(string nome, double preco) {
            this->nome = nome;
            this->preco = preco;
        }

        void setNome(string nome) {
            this->nome = nome;
        }

        string getNome() {
            return nome;
        }

        void setPreco(double preco) {
            this->preco = preco;
        }

        double getPreco() {
            return preco;
        }

        void alterarPreco(double novoPreco) {
            setPreco(novoPreco);
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
};//End Class

class Aluno {
    private:
        string nome;
        string identificacao;
        string tipo;
        double notaFinal;
        vector<double> notas;

    public:
        Aluno(string nome, string identificacao) {
            this->nome = nome;
            this->identificacao = identificacao;
            this->tipo = "Aluno UnB";
            this->notaFinal = 0.0;
        }

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
};//End Class


int main() {
    
    //Cria 3 instâncias da classe Pessoa, com identificação, nome e idade em ponteiros
    Pessoa *p1 = new Pessoa("123456789", "Ruan", 20);
    Pessoa *p2 = new Pessoa("987654321", "Maria", 25);
    Pessoa *p3 = new Pessoa("456789123", "João", 30);
    //Exibe as informações de cada instância criada
    p2->exibirInfo();
    p3->exibirInfo();
    p1->exibirInfo();

    //Cria 3 instâncias da classe Produto, com nome e preço em ponteiros
    Produto *prod1 = new Produto("Produto A", 10.0);
    Produto *prod2 = new Produto("Produto B", 15.0);
    Produto *prod3 = new Produto("Produto C", 20.0);
    //Compara os preços dos produtos criados, imprimindo se são mais caros, mais baratos ou iguais
    prod1->comparar(*prod2);
    prod2->comparar(*prod3);
    //Mostra o valor do produto, depois altera o valor, e mostra novamente após a alteração
    cout << "Preço inicial: " << prod1->getPreco() << endl;
    prod1->alterarPreco(222.1);
    cout << "Preço após alteração: " << prod1->getPreco() << endl;

    //Cria uma instância da classe Aluno, com nome e identificação em forma de ponteiro
    Aluno *a1 = new Aluno("Ruan", "242014471");
    //Adiciona as 2 notas do aluno que irão para o vetor notas e em seguida calcular a média
    a1->adicionarNotas(7.2, 8.5);
    //Por fim exibe as informações do aluno, incluindo a menção de acordo com a média
    a1->imprime();

    return 0;
}