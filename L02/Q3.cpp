/*
Nome: Ruan Dias Alves Teixeira
Matr�cula: 242014471
Quest�o: L02Q03
*/

// Importa��o das bibliotecas necess�rias
#include <iostream>
#include <string>
#include <locale>
#include <fstream>
#include <vector>

using namespace std;

/*
Resposta do primeiro ponto da quest�o referente a sobrecarga e sobreposi��o, considerando o aspecto est�tico e din�mico:

"A sobrecarga de m�todos � um conceito relacionado ao aspecto est�tico, pois � a defini��o do m�todo com mesmo nome, s� que com par�metros diferentes, o que � resolvido em tempo de compila��o.

J� a sobreposi��o � basicamente o conceito de uma classe filha redefinir um m�todo herdado da classe pai, e � resolvido em tempo de execu��o(relacionado ao aspecto din�mico), por que, pelo que eu pesquisei, o compilador n�o sabe qual m�todo � o certo a ser chamado, a� ele verifica o tipo do objeto em tempo de execu��o e chama o m�todo correto."
*/

class Complexo {
    private:
        double real, imag;

    public:
        Complexo(double real, double imag) {
            this->real = real;
            this->imag = imag;
        }

        // Operador soma
        Complexo operator+(Complexo c) {
            return Complexo(real + c.real, imag + c.imag);
        }

        // Operador subtra��o
        Complexo operator-(Complexo c) {
            return Complexo(real - c.real, imag - c.imag);
        }

        // Operador multiplica��o
        Complexo operator*(Complexo c) {
            double r = real * c.real - imag * c.imag;
            double i = real * c.imag + imag * c.real;
            return Complexo(r, i);
        }

        void imprimir() const {
            cout << real << (imag >= 0 ? "+" : "") << imag << "i";
        }
};

// Classe Matriz2x2
class Matriz2x2 {
    private:
        int mat[2][2];

    public:
        Matriz2x2(int p1x1, int p1x2, int p2x1, int p2x2) {
            mat[0][0] = p1x1; mat[0][1] = p1x2;
            mat[1][0] = p2x1; mat[1][1] = p2x2;
        }

        // Operador multiplica��o
        Matriz2x2 operator*(Matriz2x2 m) {
            return Matriz2x2(
                mat[0][0]*m.mat[0][0] + mat[0][1]*m.mat[1][0],
                mat[0][0]*m.mat[0][1] + mat[0][1]*m.mat[1][1],
                mat[1][0]*m.mat[0][0] + mat[1][1]*m.mat[1][0],
                mat[1][0]*m.mat[0][1] + mat[1][1]*m.mat[1][1]
            );
        }

        void imprimir() {
            cout << "[" << mat[0][0] << " " << mat[0][1] << "]\n"
                << "[" << mat[1][0] << " " << mat[1][1] << "]\n";
        }
};


//Classe livro copiada da quest�o anterior com alguns ajustes
class Livro {
    //Atributos privados da classe livro
    private:
        string titulo;
        string autor;
        int numPaginas;

    public:
        //Constructor da classe Livro, que inicializa os atributos com os valores passados como par�metro
        Livro(string titulo, string autor, int numPaginas) {
            this->titulo = titulo;
            this->autor = autor;
            this->numPaginas = numPaginas;
        }

        //M�todos setters e getters para os atributos privados
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

        //M�todo que imprime as informa��es do objeto no console
        string imprime() {
            return "T�tulo: " + titulo + "\nAutor: " + autor + "\nN�mero de p�ginas: " + to_string(numPaginas) + "\n---------------------------";
        }

        //Sobrecarga do m�todo imprime para imprimir em um arquivo csv
        string imprime(string form) {
            return titulo + ";" + autor + ";" + to_string(numPaginas) + "\n";
        }
}; //End Class

class Circulo {

    private:
        double raio;

    public:
        Circulo(double raio) {
            this->raio = raio;
        }

        Circulo(int diametro) {
            this->raio = diametro / 2;
        }

        double getRaio() {
            return raio;
        }

        void setRaio(double raio) {
            this->raio = raio;
        }

        double calcularArea() {
            return 3.14 * (raio * raio);
        }

};

int main() {

    setlocale(LC_ALL, "Portuguese"); //Defini��o de local para aceitar caracteres especiais

    // Criando inst�ncias de Complexo
    Complexo c1(3, 4);
    Complexo c2(1, 2);

    // Realizando opera��es
    Complexo soma = c1 + c2;
    Complexo subtracao = c1 - c2;
    Complexo multiplicacao = c1 * c2;

    // Imprimindo resultados
    cout << "Soma: ";
    soma.imprimir();
    cout << "\nSubtra��o: ";
    subtracao.imprimir();
    cout << "\nMultiplica��o: ";
    multiplicacao.imprimir();

    cout << endl << "-----------------------------" << endl;

    // Criando inst�ncias de Matriz2x2
    Matriz2x2 m1(1, 2, 3, 4);
    Matriz2x2 m2(5, 6, 7, 8);

    // Realizando multiplica��o de matrizes
    Matriz2x2 resultado = m1 * m2;

    // Imprimindo resultado da multiplica��o de matrizes
    cout << "Resultado da multiplica��o de matrizes:\n";
    resultado.imprimir();

    cout << "-----------------------------" << endl;

    // Abrindo o arquivo livros.csv para escrita
    ofstream saida("./L02/livros.csv");

    // Verifica se o arquivo foi aberto corretamente
    if (!saida.is_open()) {
        cerr << "Erro ao abrir o arquivo livros.csv para escrita" << endl;
        return 1;
    }

    // Escreve o cabe�alho
    saida << "T�tulo;Autor;N�m. de P�ginas;" << endl;

    // Cria inst�ncias de Livro e escreve no arquivo
    Livro livro1("Harry Potter", "J.K. Rowling", 223);
    Livro livro2("C�digo Limpo", "Robert C. Martin", 464);
    Livro livro3("Os miser�veis", "Victor Hugo", 1234);

    saida << livro1.imprime("csv") << livro2.imprime("csv") << livro3.imprime("csv");

    //Imprime os livros no console
    cout << livro1.imprime() << endl;
    cout << livro2.imprime() << endl;
    cout << livro3.imprime() << endl;

    //Fecha o arquivo
    saida.close();
    
    // Cria��o de inst�ncias da classe Circulo uma com par�metro raio e outra di�metro
    Circulo circulo1(4.1);
    Circulo circulo2(10);

    // Exibindo a �rea dos c�rculos
    cout << "�rea do c�rculo 1: " << circulo1.calcularArea() << endl;
    cout << "�rea do c�rculo 2: " << circulo2.calcularArea() << endl;
    cout << "-----------------------------" << endl;

    return 0;//Fim do programa
}