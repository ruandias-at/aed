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

class Departamento {
    protected:
        string nome;
        int codigo;

    public:
        Departamento(string nome = "", int codigo = 0) {
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

class Locomotiva {
    private:
        int peso;
        string marca;

    public:
        Locomotiva(int peso = 0, string marca = "") {
            this->peso = peso;
            this->marca = marca;
        }

        void imprime() {
            cout << "  Locomotiva - Peso: " << peso << ", Marca: " << marca << endl;
        }
};

class Vagao {
    private:
        string tipoCarga; 

    public:
        Vagao(string tipoCarga) {
            this->tipoCarga = tipoCarga;
        }

        void imprime() {
            cout << "Vag�o - Tipo de Carga: " << tipoCarga << endl;
        }
};

class Trem {
    private:
        string identificacao;
        Locomotiva locomotiva;
        vector<Vagao> vagoes;

    public:
        Trem(string identificacao, Locomotiva locomotiva) {
            this->identificacao = identificacao;
            this->locomotiva = locomotiva;
        }

        void adicionarVagao(Vagao vagao) {
            vagoes.push_back(vagao);
        }

        void imprime() {
            cout << "Trem: " << identificacao << endl;
            locomotiva.imprime();
            for (Vagao vagao : vagoes) {
                vagao.imprime();
            }
        }
};

int main() {

    setlocale(LC_ALL, "Portuguese");

    Empresa empresa("Ruan Social");

    Departamento dep1("Desenvolvimento", 101);
    Departamento dep2("Marketing", 102);
    Departamento dep3("Recursos Humanos", 103);

    empresa.adicionarDepartamento(dep1);
    empresa.adicionarDepartamento(dep2);
    empresa.adicionarDepartamento(dep3);

    cout << "Empresa: " << empresa.getRazaoSocial() << endl;
    cout << "Departamentos:" << endl;
    for(Departamento dep : empresa.getDepartamentos()) {
        cout << " - " << dep.getNome() << " (C�digo: " << dep.getCodigo() << ")" << endl;
    }

    if (empresa.removerDepartamento(102)) {
        cout << "Departamento 'Marketing' removido com sucesso." << endl;
    } else {
        cout << "Departamento n�o encontrado." << endl;
    }

    cout << "Departamentos ap�s remo��o:" << endl;
    for(Departamento dep : empresa.getDepartamentos()) {
        cout << " - " << dep.getNome() << " (C�digo: " << dep.getCodigo() << ")" << endl;
    }
    
    cout << "-----------------------------" << endl;

    Locomotiva locomotiva(5000, "Locomotiva X");
    Vagao vagao1("Carga Geral");
    Vagao vagao2("Carga Perigosa");
    Vagao vagao3("Carga Fr�gil");

    Trem trem("Trem 001", locomotiva);
    trem.adicionarVagao(vagao1);
    trem.adicionarVagao(vagao2);
    trem.adicionarVagao(vagao3);

    cout << "Informa��es do Trem:" << endl;
    trem.imprime();

    cout << "-----------------------------" << endl;

    return 0;
}
