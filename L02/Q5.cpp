/*
Nome: Ruan Dias Alves Teixeira
Matr�cula: 242014471
Quest�o: L02Q05
*/

//Importa��o das bibliotecas necess�rias
#include <iostream>
#include <string>
#include <vector>
#include <locale>

using namespace std;

class Empresa {
    protected:
    string razaoSocial;
    vector<Departamento> departamentos;
    
    public:
    Empresa(string razaoSocial) {
            this->razaoSocial = razaoSocial;
        }

        string getRazaoSocial() {
            return razaoSocial;
        }

        void setRazaoSocial(string razaoSocial) {
            this->razaoSocial = razaoSocial;
        }

        vector<Departamento> getDepartamentos() {
            return departamentos;
        }

        void setDepartamentos(vector<Departamento> departamentos) {
            this->departamentos = departamentos;
        }

        void adicionarDepartamento(Departamento departamento) {
            departamentos.push_back(departamento);
        }

        bool removerDepartamento(int codigo) {
        for (auto it = departamentos.begin(); it != departamentos.end(); ++it) {
            if (it->getCodigo() == codigo) {
                departamentos.erase(it);
                return true;
            }
        }
        return false;
    }
};

class Departamento : public Empresa {

    protected:
        string nome;
        int codigo;

    public:
        Departamento(string nome, int codigo, string razaoSocial) : Empresa(razaoSocial) {
            this->nome = nome;
            this->codigo = codigo;
        }

        string getNome() {
            return nome;
        }

        void setNome(string nome) {
            this->nome = nome;
        }

        int getCodigo() {
            return codigo;
        }

        void setCodigo(int codigo) {
            this->codigo = codigo;
        }
};

int main() {

    setlocale(LC_ALL, "Portuguese"); //Defini��o de local para aceitar caracteres especiais

    // Cria��o de uma empresa
    Empresa empresa("Tech Solutions");

    // Cria��o de departamentos
    Departamento dep1("Desenvolvimento", 101);
    Departamento dep2("Recursos Humanos", 102);
    Departamento dep3("Marketing", 103);

    // Adicionando departamentos � empresa
    empresa.adicionarDepartamento(dep1);
    empresa.adicionarDepartamento(dep2);
    empresa.adicionarDepartamento(dep3);

    // Removendo um departamento
    empresa.removerDepartamento(102);

    // Exibindo informa��es da empresa
    cout << "Raz�o Social: " << empresa.getRazaoSocial() << endl;
    cout << "Departamentos:" << endl;
    

    cout << "--------------------------" << endl;

    return 0;
}