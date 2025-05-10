/*
Nome: Ruan Dias Alves Teixeira
Matrícula: 242014471
Questão: L02Q05
*/

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
    Departamento(const string& nome, int codigo) : nome(nome), codigo(codigo) {}

    virtual ~Departamento() = default;

    const string& getNome() const {
        return nome;
    }

    void setNome(const string& nome) {
        this->nome = nome;
    }

    int getCodigo() const {
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
    Empresa(const string& razaoSocial) : razaoSocial(razaoSocial) {}

    virtual ~Empresa() = default;

    const string& getRazaoSocial() const {
        return razaoSocial;
    }

    void setRazaoSocial(const string& razaoSocial) {
        this->razaoSocial = razaoSocial;
    }

    const vector<Departamento>& getDepartamentos() const {
        return departamentos;
    }

    void setDepartamentos(const vector<Departamento>& departamentos) {
        this->departamentos = departamentos;
    }

    void adicionarDepartamento(const Departamento& departamento) {
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

int main() {
    setlocale(LC_ALL, "Portuguese");

    Empresa empresa("Tech Solutions");

    Departamento dep1("Desenvolvimento", 101);
    Departamento dep2("Recursos Humanos", 102);
    Departamento dep3("Marketing", 103);

    empresa.adicionarDepartamento(dep1);
    empresa.adicionarDepartamento(dep2);
    empresa.adicionarDepartamento(dep3);

    if (!empresa.removerDepartamento(102)) {
        cout << "Departamento não encontrado!" << endl;
    }

    cout << "Razão Social: " << empresa.getRazaoSocial() << endl;
    cout << "Departamentos:" << endl;
    for (const auto& dep : empresa.getDepartamentos()) {
        cout << "Nome: " << dep.getNome() << ", Código: " << dep.getCodigo() << endl;
    }

    cout << "--------------------------" << endl;

    return 0;
}