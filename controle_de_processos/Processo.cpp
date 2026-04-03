
#include "Processo.hpp"

// impementando construtor
Processo::Processo(int id, std::string nome, int prioridade) {
    this->_id = id;
    this->_nome = nome;
    this->_prioridade = prioridade;
}

// implementando metodos
int Processo::getID() {
    return this->_id;
}

int Processo::getPrioridade(){
    return this->_prioridade;
}

std::string Processo::getNome(){
    return this->_nome;
}

std::string Processo::processo_str() {

    switch (this->_prioridade)
    {
    case 0: return "BAIXA";
    case 1: return "MEDIA";
    case 2: return "ALTA";
    default: return "Prioridade invalida";
    }
}

double Processo::tempo_reservado_processo() {

    switch (this->_prioridade) {
        case 0: return 0.5;
        case 1: return 1.5;
        case 2: return 3.0;
        default: return -1.0; // valor de erro para prioridade inválida
    }
}



void Processo::imprimir_dados() {
    std::cout << this->_id << "\t" 
                << this->_nome << "\t" 
                << this->processo_str() 
                << std::endl;
}


/*

Processo: 
    Atributos: int _id; int _prioridade; std::string _nome;
    Crie métodos getID(), getPrioridade() e getNome() para retornar os valores armazenados.

    Processo(int id, std::string nome, int prioridade): Método construtor para a inicialização dos atributos. 
    A prioridade poderá ser BAIXA (0), MÉDIA (1) ou ALTA (2).

    double tempo_reservado_processo(): Método que retorna o tempo reservado para execução do processo de acordo com a prioridade. 
    Prioridade: BAIXA (0.5), MÉDIA (1.5), ALTA (3.0).

    void imprimir_dados(): Método que faz a impressão dos atributos do processo no seguinte formato: "id nome prioridade", 
    com uma quebra de linha ao final. Atenção, nesse caso utilize tab (\t) para separar os elementos. 
    Além disso, substitua o código da prioridade por: BAIXA, MEDIA ou ALTA.

    */
