#include <iostream>
#include <vector>

using namespace std;

int main() {
    // Declaração das variáveis, primeira é um vetor de inteiros e a segunda é um inteiro.
    vector<int> myvector;
    int myint;

    // Pede para o usuário para digitar números inteiros e armazena no vetor.
    do {
        cout << "Please enter some integers (0 to end):" << endl;
        cin >> myint;
        myvector.push_back(myint);
        cout << "myvector stores " << int(myvector.size()) << " numbers." << endl;
    } while (myint != 0);

    return 0;
}