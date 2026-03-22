#include <iostream>

int main() {

    int i = 10;
    int &j = i;

    j = 20;

    std::cout << i << std::endl;

    return 0;
}