#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <set>

using namespace std;

int main() {

    ifstream arquivo("palavras.txt");

    int n;
    arquivo >> n;

    vector<string> palavras(n);

    for (int i = 0; i < n; i++) {
        arquivo >> palavras[i];
    }

    int escolha;
    cin >> escolha;

    string chave = palavras[escolha - 1];

    set<char> erros;  // letras que não estão na palavra

    for (int tentativa = 0; tentativa < 5; tentativa++) {

        string palpite;
        cin >> palpite;

        string resultado = "";

        for (int i = 0; i < 5; i++) {

            if (palpite[i] == chave[i]) {
                resultado += palpite[i];
            }

            else if (chave.find(palpite[i]) != string::npos) {
                resultado += tolower(palpite[i]);
            }

            else {
                resultado += '*';
                erros.insert(palpite[i]);
            }
        }

        cout << resultado << " (";

        for (char c : erros) {
            cout << c;
        }

        cout << ")" << endl;

        if (palpite == chave) {
            cout << "GANHOU!" << endl;
            return 0;
        }
    }

    cout << "PERDEU! " << chave << endl;

    return 0;
}