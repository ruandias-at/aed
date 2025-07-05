// Aluno: Ruan Dias Alves Teixeira - 242014471
// Algoritmo e Estrutura de Dados
/* Código que implementa uma função que encontra se um valor digitado estará
presente em uma lista pré-definida, e apresenta ao usuário, a posição que o valor se encontra.
A posição -1 aparecerá caso o valor não esteja incluido na lista. */
#include <iostream>// Inclui biblioteca para entrada e saída de dados

using namespace std;// Faz com que não precisa escrever std antes das funções de cin, cout e outras

//Função para buscar valor dentro de lista pré-definida
int achar(int n) { //Parâmetro inteiro 'n' que será o valor a ser encontrado na lista pré-definida
    //Atribuindo valores ao array lista
    int lista[10] = {1, 7, 9, 12, 15, 17, 22, 44, 77};
    //Loop de repetição para todos os itens do array
    for (int i = 0; i < 10; i++){
        //Verifica se o valor está incluido na lista
        if (lista[i] == n) {
            //Retorna a posição do item encontrado no array
            return i;
        } //End If
    } //End For
    //Retorna -1 se o valor não estiver na lista
    return -1;
} //End function int

//Função Main
int main() {
    //Declarando variável n
    int n;
    //Mostra mensagem no terminal para que o usuário insira um valor em seguida
    cout << "Digite um numero para saber se ele esta na lista: " << endl;
    //Recebe o valor de n pelo teclado e atribui a variável
    cin >> n;
    // Mostra para o usuário a posição do valor na lista
    cout << "O valor " << n << " esta na posicao " << achar(n) << endl;

    //Finaliza o código
    return 0;
}//End Main