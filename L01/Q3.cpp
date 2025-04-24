/*
Nome: Ruan Dias Alves Teixeira
Matr�cula: 242014471
Quest�o: L01Q02
*/
//Importando todas as bibliotecas necess�rias para a quest�o
#include <iostream> //Importa os comandos para entrada e sa�da de dados
#include <string> //Importa a biblioteca de strings
#include <vector> //Importa a biblioteca de vetores
#include <locale> //Importa a biblioteca de locale, para definir o local e permitir o uso de acentos

using namespace std; //Facilita para que n�o precise escrever std antes de usar comandos

//Definindo a classe Pessoa, que possui os atributos privados identificacao, nome e idade
class Pessoa {
    private:
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

//Definindo a classe Produto, que possui os atributos privados nome e preco
class Produto {
    private: 
        string nome;
        double preco;
    
    public:
        //Constructor da classe Produto, que inicializa os atributos com os valores passados como par�metro
        Produto(string nome, double preco) {
            this->nome = nome;
            this->preco = preco;
        }

        //M�todos setters e getters para cada atributo da classe Produto, permitindo a manipula��o dos dados 'privados'
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

        //Altera o pre�o do produto, com o valor passado como par�metro
        void alterarPreco(double novoPreco) {
            setPreco(novoPreco);
        }

        //Comprara o preco do produto com o preco de outro produto passado como parametro.
        void comparar(Produto outro) {
            if (this->preco > outro.preco) {
                cout << this->nome << " � mais caro que " << outro.nome << endl;
            } else if (this->preco < outro.preco) {
                cout << this->nome << " � mais barato que " << outro.nome << endl;
            } else {
                cout << this->nome << " e " << outro.nome << " t�m o mesmo pre�o." << endl;
            }
        }
};//End Class

//Definindo a classe aluno, que possui os atributos privados nome, identificacao, tipo, notaFinal e notas
class Aluno {
    private:
        string nome;
        string identificacao;
        string tipo;
        double notaFinal;
        vector<double> notas;

    public:
        //Constructor da classe Aluno, que inicializa os atributos com os valores passados como par�metro
        //Define o tipo como "Aluno UnB" e a notaFinal como 0.0 por padr�o
        Aluno(string nome, string identificacao) {
            this->nome = nome;
            this->identificacao = identificacao;
            this->tipo = "Aluno UnB";
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


int main() {
    
    //Cria 3 inst�ncias da classe Pessoa, com identifica��o, nome e idade em ponteiros
    Pessoa *p1 = new Pessoa("123456789", "Ruan", 20);
    Pessoa *p2 = new Pessoa("987654321", "Maria", 25);
    Pessoa *p3 = new Pessoa("456789123", "Jo�o", 30);
    //Exibe as informa��es de cada inst�ncia criada
    p2->exibirInfo();
    p3->exibirInfo();
    p1->exibirInfo();

    //Cria 3 inst�ncias da classe Produto, com nome e pre�o em ponteiros
    Produto *prod1 = new Produto("Produto A", 10.0);
    Produto *prod2 = new Produto("Produto B", 15.0);
    Produto *prod3 = new Produto("Produto C", 20.0);
    //Compara os pre�os dos produtos criados, imprimindo se s�o mais caros, mais baratos ou iguais
    prod1->comparar(*prod2);
    prod2->comparar(*prod3);
    //Mostra o valor do produto, depois altera o valor, e mostra novamente ap�s a altera��o
    cout << "Pre�o inicial: " << prod1->getPreco() << endl;
    prod1->alterarPreco(222.1);
    cout << "Pre�o ap�s altera��o: " << prod1->getPreco() << endl;

    //Cria uma inst�ncia da classe Aluno, com nome e identifica��o em forma de ponteiro
    Aluno *a1 = new Aluno("Ruan", "242014471");
    //Adiciona as 2 notas do aluno que ir�o para o vetor notas e em seguida calcular a m�dia
    a1->adicionarNotas(7.2, 8.5);
    //Por fim exibe as informa��es do aluno, incluindo a men��o de acordo com a m�dia
    a1->imprime();

    return 0; //Fim do programa
}