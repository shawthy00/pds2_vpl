
#ifndef FILAPROCESSOS_HPP
#define FILAPROCESSOS_HPP

#include "Processo.hpp"

class FilaProcessos {

    // struct para criar a fila, já que não pode ser usado LIST e afins
    struct No {
        Processo* processo;
        No* proximo;

        // construtor
        No(Processo* processo) {
            this->processo = processo;
            this->proximo = nullptr; // caso a fila esteja vazia inicia nulo.
        }
    };
    
    // atributos
    No* inicio;
    No* fim;
    int id_sequencial;

    public:
    // construtor   
    FilaProcessos();

    // metodos
    void adicionar_processo(std::string nome, int prioridade);
    Processo* remover_processo_maior_prioridade();
    Processo* remover_processo_por_id(int id);
    void estimativa_tempo_para_execucao(int id);
    void imprimir_fila();

};

#endif