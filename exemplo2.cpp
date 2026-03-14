#include <iostream>
#include <string>

using namespace std;

int main() {

    string nome = "João";
    string sobrenome = "Silva";
    string cpf = "12345678900";

    for (int i = 0; i < cpf.length(); i++) {
        if (i >= 3 && i <= 5) {
            cout << "*";
        } else {
        cout << cpf[i];
        }
    }

    return 0;
}