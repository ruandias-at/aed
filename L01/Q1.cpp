/*
Nome: Ruan Dias Alves Teixeira
Matrícula: 242014471
Questão: L01Q01
*/

//Importa todas as bibliotecas necessárias para resolver a questão
#include <iostream> //Biblioteca padrão para entrada e saída de dados 
#include <string> //Biblioteca padrão para manipulação de strings
#include <vector> //Biblioteca padrão para manipulação de vetores
#include <locale> //Biblioteca usada para definir o idioma dos 'caracteres' e poder usar caracteres especiais

using namespace std; //Para evitar escrever std:: antes de cada comando

//Primeira Classe Fórmula, com o atributo público e inteiro 'tag'
class Formula {
    public:
        int tag;
    //Constructor da classe, recebe o parâmetro 'tag' e o atribui ao atributo da classe
    Formula(int tag) {
        this->tag = tag;
    }
}; //End Class

//Classe Pessoa, com atributos públicos 'identificacao', 'nome' e 'idade'
//Possui um constructor que inicializa esses atributos e um método para exibir as informações
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
};//End Class

/*Classe Divisão, com atributos públicos 'numero1' e 'numero2'
Possui um constructor que inicializa esses atributos e um método para realizar a divisão
Caso o divisor seja zero, retorna 0 e imprime uma mensagem de erro
Caso contrário, imprime o resultado da divisão*/
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
};//End Class

/*Classe Produto, com atributos públicos 'nome' e 'preco'
Possui um constructor que inicializa esses atributos e um método para comparar preços de dois produtos*/
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
};//End Class

/*Classe Aluno, que contém os atributos públicos: 'nome', 'identificacao', 'tipo', 'notaFinal' e um vector<double> 'notas'
Possui um constructor que inicializa os atributos 'nome' e 'identificacao'
O constructor tbm define o tipo como "Aluno UnB" e a nota final como 0.0
Possui um método para adicionar notas, que calcula a média e armazena no atributo 'notaFinal'
Por fim  método 'imprime' que mostra todas as informações do objeto e também a menção do aluno
de acordo com a nota final dele.*/
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
};//End Class

int main() {
    //Define o local como Português, para que sejam exibidos e aceitos caracteres especiais
    setlocale(LC_ALL, "Portuguese");

    //Cria 2 instâncias da clase fórmula, com tags 0 e 1
    Formula f1 = Formula(0);
    Formula f2 = Formula(1);
    //Imprime as tags das fórmulas criadas
    cout << "Tag da fórmula 1: " << f1.tag << endl;
    cout << "Tag da fórmula 2: " << f2.tag << endl;

    //Cria 3 instâncias da classe Pessoa, com identificações, nomes e idades diferentes
    Pessoa p1 = Pessoa("123456789", "Ruan", 20);
    Pessoa p2 = Pessoa("987654321", "Maria", 25);
    Pessoa p3 = Pessoa("456789123", "João", 30);
    //Exibe as informações de cada instância criada
    p1.exibirInfo();
    p2.exibirInfo();
    p3.exibirInfo();

    //Cria 2 instâncias da classe Divisão, com números diferentes, a segunda com divisor 0
    Divisao d1 = Divisao(4, 2);
    Divisao d2 = Divisao(10, 0);
    /*Imprime o resultado da divisão de cada instância
    A primeira divisão imprime o resultado, a segunda imprime uma mensagem de erro pois não
    é possível dividir por zero*/
    d1.imprimir();
    d2.imprimir();

    //Cria 3 instâncias da classe Produto, com nomes e preços diferentes
    Produto prod1 = Produto("Produto A", 10.0);
    Produto prod2 = Produto("Produto B", 15.0);
    Produto prod3 = Produto("Produto C", 20.0);
    //Compara os preços dos produtos criados, imprimindo se são mais caros, mais baratos ou iguais
    prod1.comparar(prod2);
    prod2.comparar(prod3);

    //Cria uma instância da classe Aluno, com nome e identificação
    Aluno a1 = Aluno("Ruan", "242014471");
    //Adiciona as 2 notas do aluno que irão para o vetor notas e em seguida calcular a média
    a1.adicionarNotas(7.2, 8.5);
    //Por fim exibe as informações do aluno, incluindo a menção de acordo com a média
    a1.imprime();

    return 0; //Fim do programa
}