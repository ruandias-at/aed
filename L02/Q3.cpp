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

using namespace std;

/*
Resposta do primeiro ponto da quest�o referente a sobrecarga e sobreposi��o, considerando o aspecto est�tico e din�mico:

"A sobrecarga de m�todos � um conceito relacionado ao aspecto est�tico, pois � a defini��o do m�todo com mesmo nome, s� que com par�metros diferentes, o que � resolvido em tempo de compila��o.

J� a sobreposi��o � basicamente o conceito de uma classe filha redefinir um m�todo herdado da classe pai, e � resolvido em tempo de execu��o(relacionado ao aspecto din�mico), por que, pelo que eu pesquisei, o compilador n�o sabe qual m�todo � o certo a ser chamado, a� ele verifica o tipo do objeto em tempo de execu��o e chama o m�todo correto."
*/

class Complexo {

};

class Matriz2x2 {

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
        void imprime() {
            cout << "T�tulo: " << titulo << endl;
            cout << "Autor: " << autor << endl;
            cout << "N�mero de p�ginas: " << numPaginas << endl;
        }

        //Sobrecarga do m�todo imprime para imprimir em um arquivo csv
        void imprime(string form) {
            cout << titulo << ";" << autor << ";" << numPaginas << endl;
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




    
    return 0;//Fim do programa
}