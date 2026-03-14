#include <iostream>
#include <string>

//using namespace std;

int main() {
    std::string curto = "Hello mundão";
    std::string longo = "Hello mundão, como vai você?";

    std::cout << "Curto: " << curto << std::endl;
    std::cout << "Longo: " << longo << std::endl;

    std::cout << longo.length() << std::endl;

    return 0;
}