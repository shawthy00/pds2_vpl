#include <iostream>
#include <string>

using namespace std;

void incrementar(int* x) { *x = *x + 1; }

void incrementar_p(int* x) { *x = *(x + 1); }

int main() {

    int v[3] = {10, 20, 30};
    int* x = v;

    cout << v << endl;
    cout << x << endl;
    cout << *x << endl;
    cout << *(x + 1) << endl;
    cout << *v << endl;
    cout << *(v + 1) << endl;
}