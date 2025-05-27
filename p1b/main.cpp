/*
    Nome: Ruan Dias Alves Teixeira
    Matr�cula: 242014471
*/

#include <iostream>
#include <string>

#include "ContaPF.h"
#include "ContaPJ.h"
#include "ContaPFEspecial.h"
#include "ContaPJEspecial.h"

using namespace std;

int main() {

//PARTE 1:
//Primeiro ponto:

    //Declarando uma inst�ncia da classe ContaPF como vari�vel, utilizando o constructor com saldo
    ContaPF c1pf("123", 3000, "111.222.333-44", "Ruan Dias");
    //Imprime no console os dados da conta
    cout << c1pf.toString() << endl;
    //Imprime linhazinha no console para melhor visualiza��o
    cout << "-----------------------" << endl;


    //Declarando uma outra ist�ncia da classe ContaPF s� que como ponteiro, e utilizando o constructor sem saldo definido(saldo = 0)
    ContaPF *c2pf = new ContaPF("420", "012.345.678-99", "Valerio");
    //Imprime no console os dados da conta
    cout << c2pf->toString() << endl;
    //Imprime novamente a linha para melhor visualiza��o
    cout << "-----------------------" << endl;


    //Declarando uma inst�ncia da classe ContaPF como vari�vel, utilizando o constructor com saldo
    ContaPJ c1pj("666", 350000, "11.222.333/0001-45", "Ruan Sports Inc.");
    //Imprime no console os dados da conta
    cout << c1pj.toString() << endl;
    //Imprime linhazinha no console para melhor visualiza��o
    cout << "-----------------------" << endl;


    //Declarando uma outra ist�ncia da classe ContaPF s� que como ponteiro, e utilizando o constructor sem saldo definido(saldo = 0)
    ContaPJ *c2pj = new ContaPJ("987", "00.000.000/0001-11", "Valerio Engenharia LTDA");
    //Imprime no console os dados da conta
    cout << c2pj->toString() << endl;
    //Imprime novamente a linha para melhor visualiza��o
    cout << "-----------------------" << endl;


//-------------------------------------------------------------------------------------------------------


//Segundo Ponto:

    //Primeiro Dep�sito com primeira inst�ncia
    c1pf.depositar(2000); //Dep�sito no valor de R$2000,00
    c1pf.toString(); //Confirmar o dep�sito

    c1pf.gastar(7000); //N�o deve ser poss�vel realizar gasto por ser um valor maior que o saldo atual
    c1pf.toString(); // Verificar se n�o foi conclu�do o primeiro gasto

    c1pf.gastar(1000); //Deve atualizar o saldo e gastar os R$1000,00
    cout << c1pf.toString() << endl; //Mostrar o novo saldo para confirmar transa��o
    cout << "-----------------------" << endl;


    //Segunda inst�ncia
    c2pf->depositar(2000); //Dep�sito no valor de R$2000,00
    c2pf->toString();

    c2pf->gastar(3000); //N�o deve ser poss�vel realizar gasto por ser um valor maior que o saldo atual
    c2pf->toString();

    c2pf->gastar(1000); //Deve atualizar o saldo e gastar os R$1000,00
    cout << c2pf->toString() << endl; //Mostrar o novo saldo para confirmar transa��o
    cout << "-----------------------" << endl;


    //Primeiro Dep�sito com primeira inst�ncia
    c1pj.depositar(50000); //Dep�sito no valor de R$2000,00
    c1pj.toString();

    c1pj.gastar(1000000); //N�o deve ser poss�vel realizar gasto(R$ 1.000.000,00) por ser um valor maior que o saldo atual
    c1pj.toString();

    c1pj.gastar(100000); //Deve atualizar o saldo e gastar os R$100.000,00
    cout << c1pj.toString() << endl; //Mostrar o novo saldo para confirmar transa��o
    cout << "-----------------------" << endl;


    //Segunda inst�ncia
    c2pj->depositar(200000); //Dep�sito no valor de R$200.000,00
    c2pj->toString(); //Mostrar o dep�sito conclu�do

    c2pj->gastar(3000); //N�o deve ser poss�vel realizar gasto por ser um valor maior que o saldo atual
    c2pj->toString(); //Verificar se n�o foi gasto

    c2pj->gastar(1000); //Deve atualizar o saldo e gastar os R$1000,00
    cout << c2pj->toString() << endl; //Mostrar o novo saldo para confirmar transa��o
    cout << "-----------------------" << endl;


//------------------------------------------------------------------------------------------------------

//Terceiro Ponto:

    //Testando as entradas erraddas para cada inst�ncia:
    c1pf.depositar(-1000);
    cout << "-----------------------" << endl;
    cout << c1pf.toString() << endl;
    cout << "-----------------------" << endl;
    c1pf.gastar(-200);
    cout << "-----------------------" << endl;
    cout << c1pf.toString() << endl;
    cout << "-----------------------" << endl;

    c2pf->depositar(-12313);
    cout << "-----------------------" << endl;
    cout << c2pf->toString() << endl;
    cout << "-----------------------" << endl;
    c2pf->gastar(-123);
    cout << "-----------------------" << endl;
    cout << c2pf->toString() << endl;
    cout << "-----------------------" << endl;

    c1pj.depositar(-1200);
    cout << "-----------------------" << endl;
    cout << c1pj.toString() << endl;
    cout << "-----------------------" << endl;
    c1pj.gastar(-20);
    cout << "-----------------------" << endl;
    cout << c1pj.toString() << endl;
    cout << "-----------------------" << endl;

    c2pj->depositar(-900);
    cout << "-----------------------" << endl;
    cout << c2pj->toString() << endl;
    cout << "-----------------------" << endl;
    c2pj->gastar(-1000);
    cout << "-----------------------" << endl;
    cout << c2pj->toString() << endl;
    cout << "-----------------------" << endl;


//------------------------------------------------------------------------------------------------------

//Quarto Ponto:

    //Depositando mais uma quantia em cada conta e gastando mais um pouco para cada uma das inst�ncias:
    c1pf.depositar(2000);
    cout << c1pf.toString() << endl << "-----------------------" << endl;

    c1pf.gastar(1900);
    cout << c1pf.toString() << endl << "-----------------------" << endl;


    c2pf->depositar(3000);
    cout << c2pf->toString() << endl << "-----------------------" << endl;

    c2pf->gastar(2600);
    cout << c2pf->toString() << endl << "-----------------------" << endl;


    c1pj.depositar(30000);
    cout << c1pj.toString() << endl << "-----------------------" << endl;

    c1pj.gastar(33000);
    cout << c1pj.toString() << endl << "-----------------------" << endl;


    c2pj->depositar(87000);
    cout << c2pj->toString() << endl << "-----------------------" << endl;

    c2pj->gastar(85000);
    cout << c2pj->toString() << endl << "-----------------------" << endl;


// -------------------------------------------------------------------------------------------------

//PARTE 2:
//Primeiro Ponto:

    ContaPFEspecial cEspecialPF1("4002", 10000, 5000); // Definindo 1� Inst�ncia PF com o saldo definido como R$10.000,00 e limite de R$5.000,00.
    cout << cEspecialPF1.toString() << endl;
    cout << "-----------------------------------" << endl;

    ContaPJEspecial *cEspecialPJ2 = new ContaPJEspecial("007", 50000); //Definindo 2� Inst�ncia PJ com saldo default e ponteiros.
    cout << cEspecialPJ2->toString() << endl;
    cout << "-----------------------------------" << endl;


//---------------------------------------------------------------------------------------------------------

//Segundo Ponto:

    //Testando com valores inv�lidos:
    cEspecialPF1.depositar(-123);
    cout << cEspecialPF1.toString() << endl;
    cout << "-----------------------------------" << endl;


    cEspecialPJ2->depositar(-999);
    cout << cEspecialPF1.toString() << endl;
    cout << "-----------------------------------" << endl;


    cEspecialPF1.gastar(-300);
    cout << cEspecialPF1.toString() << endl;
    cout << "-----------------------------------" << endl;


    cEspecialPJ2->gastar(-400);
    cout << cEspecialPF1.toString() << endl;
    cout << "-----------------------------------" << endl;


    //Testando com valores v�lidos
    cEspecialPF1.depositar(120);
    cout << cEspecialPF1.toString() << endl;
    cout << "-----------------------------------" << endl;


    cEspecialPJ2->depositar(2000);
    cout << cEspecialPF1.toString() << endl;
    cout << "-----------------------------------" << endl;

    //Tentando Gastar mais do que o saldo + limite
    cEspecialPF1.gastar(1000000);
    cout << cEspecialPF1.toString() << endl;
    cout << "-----------------------------------" << endl;

    //Adicionando mais limite e saldo para tornar poss�vel o gasto
    cEspecialPF1.depositar(500000);
    cout << cEspecialPF1.toString() << endl;
    cout << "-----------------------------------" << endl;

    cEspecialPF1.setLimite(500000);
    cout << cEspecialPF1.toString() << endl;
    cout << "-----------------------------------" << endl;

    cEspecialPF1.gastar(1000000);
    cout << cEspecialPF1.toString() << endl;
    cout << "-----------------------------------" << endl;

    return 0;
}