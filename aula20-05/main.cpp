#include <iostream>
#include <string>

using namespace std;

#include "Pai.h"
#include "Filho.h"

int main() {
    Pai pai1("Ruan", 19);
    cout << pai1.toString() << endl;

    Filho filho1("Marcos", "Ana");
    cout << filho1.toString() << endl;

    return 0;
}