/*
Nome: Ruan Dias Alves Teixeira
Matrícula: 242014471
Questão: L02Q02
*/

//Importação das bibliotecas necessárias
#include <iostream>
#include <string>
#include <locale>

using namespace std;

class Animal {
    protected:
        int idade;
        string nome;

    public:
        
        Animal(int idade, string nome) {
            this->idade = idade;
            this->nome = nome;
        }

        void setIdade(int idade) {
            this->idade = idade;
        }

        int getIdade() {
            return idade;
        }

        void setNome(string nome) {
            this->nome = nome;
        }

        string getNome() {
            return nome;
        }

        void emitirSom() {
            cout << nome << " está emitindo som" << endl;
        }
};

class Gato : public Animal {

    public:
        Gato(int idade, string nome) : Animal(idade, nome) {}

        void emitirSom() {
            cout << nome << " está miando" << endl;
        }
};

class Cachorro : public Animal {

    public:
        Cachorro(int idade, string nome) : Animal(idade, nome) {}

        void emitirSom() {
            cout << nome << " está latindo" << endl;
        }
};

class Instrumento {

    protected:
        string tipo;

    public:

        Instrumento(string tipo) {
            this->tipo = tipo;
        }

        string getTipo() {
            return tipo;
        }

        void setTipo(string tipo) {
            this->tipo = tipo;
        }

        void tocar(){
            cout << "Tocando instrumento" << endl;
        }
};

class Guitarra : public Instrumento {
    
    protected:
        string marca;

    public:

        Guitarra(string tipo, string marca) : Instrumento(tipo) {
            this->marca = marca;
        }

        string getMarca() {
            return marca;
        }

        void setMarca(string marca) {
            this->marca = marca;
        }

        void tocar() {
            cout << "Tocando guitarra " << marca << endl;
        }
};

class Teclado : public Instrumento {

    protected:
        string marca;

    public:

        Teclado(string tipo, string marca) : Instrumento(tipo) {
            this->marca = marca;
        }

        string getMarca() {
            return marca;
        }

        void setMarca(string marca) {
            this->marca = marca;
        }

        void tocar() {
            cout << "Tocando teclado " << marca << endl;
        }
};

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

        double calcularSalarioTotal() {
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

        double calcularSalarioTotal() {
            return salario + bonus;
        }
}; //End Class

class Vendedor : public Funcionario {
    
    protected:
        double valorVendas;

    public:
        Vendedor(string nome, double salario, double valorVendas) : Funcionario(nome, salario) {
            this->valorVendas = valorVendas;
        }

        void setComissao(double valorVendas) {
            this->valorVendas = valorVendas;
        }

        double getComissao() {
            return valorVendas;
        }

        double calcularSalarioTotal() {
            return salario + (valorVendas * 0.1);
        }
}; //End Class

//Classe livro
class Livro {
    //Atributos privados da classe livro
    private:
        string titulo;
        string autor;
        int numPaginas;

    public:
        //Constructor da classe Livro, que inicializa os atributos com os valores passados como parâmetro
        Livro(string titulo, string autor, int numPaginas) {
            this->titulo = titulo;
            this->autor = autor;
            this->numPaginas = numPaginas;
        }

        //Métodos setters e getters para os atributos privados
        void setTitulo(string titulo) {
            this->titulo = titulo;
        }

        string getTitulo() {
            return titulo;
        }

        void setAutor(string autor) {
            this->autor = autor;
        }

        string getAutor() {
            return autor;
        }

        void setNumPaginas(int numPaginas) {
            this->numPaginas = numPaginas;
        }

        int getNumPaginas() {
            return numPaginas;
        }

        //Método que imprime as informações do objeto
        void exibirInfo() {
            cout << "Titulo: " << titulo << endl;
            cout << "Autor: " << autor << endl;
            cout << "Numero de Paginas: " << numPaginas << endl;
        }
}; //End Class

int main() {

    setlocale(LC_ALL, "Portuguese"); //Definição de local para aceitar caracteres especiais

    //Executando primeiro ponto da questão referente a classe Animal
    Gato gato(4, "Bixano");
    gato.emitirSom();

    Cachorro cachorro(5, "Rex");
    cachorro.emitirSom();

    Animal animal(8, "Brutus");
    animal.emitirSom();
    cout << "----------------------------------------" << endl;

    //Executando segundo ponto da questão referente a classe Instrumento
    Guitarra guitarra("Instrumento de corda", "Tagima");
    guitarra.tocar();

    Teclado teclado("Instrumento eletrônico", "Yamaha");
    teclado.tocar();

    Instrumento instrumento("Instrumento de sopro");
    instrumento.tocar();
    cout << "----------------------------------------" << endl;

    //Executando terceiro ponto da questão referente a classe Funcionario
    Gerente gerente("Carlos", 5000.0, 1000.0);
    cout << "Salario total do gerente " << gerente.getNome() << ": " << gerente.calcularSalarioTotal() << endl;

    Vendedor vendedor("Ana", 1800.0, 2000.0);
    cout << "Salario total do vendedor " << vendedor.getNome() << ": " << vendedor.calcularSalarioTotal() << endl;

    Funcionario funcionario("João", 4000.0);
    cout << "Salario do funcionario " << funcionario.getNome() << ": " << funcionario.calcularSalarioTotal() << endl;
    cout << "----------------------------------------" << endl;

    //Executando quarto ponto da questão referente a classe Livro
    Livro livro("Código Limpo", "autor desconhecido(esqueci o nome)", 1100);
    livro.exibirInfo();

    Livro livro2("Harry Potter", "J.K. Rowling", 500);
    livro2.exibirInfo();
    cout << "----------------------------------------" << endl;
    
    return 0;//Fim do programinha
}