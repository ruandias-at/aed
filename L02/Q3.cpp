/*
Nome: Ruan Dias Alves Teixeira
Matrícula: 242014471
Questão: L02Q03
*/

// Importação das bibliotecas necessárias
#include <iostream>
#include <string>
#include <locale>
#include <fstream>

using namespace std;

/*
Resposta do primeiro ponto da questão referente a sobrecarga e sobreposição, considerando o aspecto estático e dinâmico:

"A sobrecarga de métodos é um conceito relacionado ao aspecto estático, pois é a definição do método com mesmo nome, só que com parâmetros diferentes, o que é resolvido em tempo de compilação.

Já a sobreposição é basicamente o conceito de uma classe filha redefinir um método herdado da classe pai, e é resolvido em tempo de execução(relacionado ao aspecto dinâmico), por que, pelo que eu pesquisei, o compilador não sabe qual método é o certo a ser chamado, aí ele verifica o tipo do objeto em tempo de execução e chama o método correto."
*/

class Complexo {

};

class Matriz2x2 {

};

//Classe livro copiada da questão anterior com alguns ajustes
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

        //Método que imprime as informações do objeto no console
        void imprime() {
            cout << "Título: " << titulo << endl;
            cout << "Autor: " << autor << endl;
            cout << "Número de páginas: " << numPaginas << endl;
        }

        //Sobrecarga do método imprime para imprimir em um arquivo csv
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

    setlocale(LC_ALL, "Portuguese"); //Definição de local para aceitar caracteres especiais




    
    return 0;//Fim do programa
}