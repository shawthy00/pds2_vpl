#include <iostream>
#include <string>
#include <fstream>
#include <random>

using namespace std;

// funcoes

int num_palavras(string arq)
{
    ifstream arquivo(arq, fstream::in);

    string topo_string;
    int topo;

    getline(arquivo, topo_string);
    topo = stoi(topo_string);   // transformando em a variavel em int;

    arquivo.close();

    return topo;
}

/* funcao desativada pq nao é o caso, o usuário da entrada no numero da palavra
int numero_aleatorio(int max) {

    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(0, max);
    return dis(gen);
}
*/

int escolhe_numero(int max) {

    int num;

    cout << "Escolha um numero entre 1 e " << max << ": ";
    cin >> num;

    while (num < 1 || num > max) {
        cout << "Numero invalido. Digite novamente: ";
        cin >> num;
    }

    return num;
}

string palavra_lista(string arq, int num_escolhido) {

    ifstream arquivo(arq, fstream::in);
    string palavra;

    getline(arquivo, palavra); // pula a primeira linha (numero)

    // for vai iterar até achar a palvra escolhida
    for( int i = 1; i <= num_escolhido; i++) {
        getline(arquivo, palavra);
    } 
    
    return palavra;
}

string to_upper(string palavra) {
    for (int i = 0; i < palavra.length(); i++) {
        palavra[i] = toupper(palavra[i]);
    }
    return palavra;
}

string coleta_usuario() {
    string palavra_user;
    cout << "Digite uma palavra de 5 letras: ";
    cin >> palavra_user;

    while (palavra_user.length() != 5) {
        cout << "Palavra deve conter 5 letras. Digite novamente: ";
        cin >> palavra_user;
    }

    return to_upper(palavra_user);
}

void laco_tentativas(string chave) {

    int tentativas = 1;
    string erros = "";

    while (tentativas <= 5) {

        string palavra_user = coleta_usuario();
        string saida = "";

        for (int i = 0; i < palavra_user.length(); i++) {

            if (palavra_user[i] == chave[i]) {
                saida += palavra_user[i];
            }
            else if (chave.find(palavra_user[i]) != string::npos) {
                saida += tolower(palavra_user[i]);
            }
            else {
                saida += '*';

                if (erros.find(palavra_user[i]) == string::npos) {
                    erros += palavra_user[i];
                }
            }
        }

        cout << saida << " (" << erros << ")" << endl;

        if (palavra_user == chave) {
            cout << "GANHOU!" << endl;
            return;
        }

        tentativas++;
    }

    cout << "PERDEU! " << chave << endl;
}

// mantendo a funcao mais limpa possivel, 
//por isso tudo mais foi colocado em funcoes. 
//Evoluindo usaria POO.
int main() {

    string file = "palavras.txt";

    int linhas = num_palavras(file);

    int num_escolhido = escolhe_numero(linhas);

    string chave = palavra_lista(file, num_escolhido);

    laco_tentativas(chave);

    return 0;
}