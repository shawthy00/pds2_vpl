
#ifndef PROCESSO_HPP
#define PROCESSO_HPP

#include <string>
#include <iostream>

class Processo {

    // atributos
    int _id;
    int _prioridade;
    std::string _nome;

    public:
    // construtor
    Processo(int id, std::string nome, int prioridade);

    //metodos
    int getID();
    int getPrioridade();
    std::string getNome();

    std::string processo_str();
    
    double tempo_reservado_processo();
    void imprimir_dados();
    
};

#endif