
#include "FilaProcessos.hpp"
#include <iomanip>

// implementacao do construtor
FilaProcessos::FilaProcessos() {
    this->inicio = nullptr;
    this->fim = nullptr;
    this->id_sequencial = 1;
}   

// implementacao dos metodos
void FilaProcessos::adicionar_processo(std::string nome, int prioridade) {
    Processo* novo_processo = new Processo(this->id_sequencial, nome, prioridade);
    this->id_sequencial++;

    No* novo_no = new No(novo_processo);

    //se fila vazia
    if (this->inicio == nullptr) {
        this->inicio = novo_no;
        this->fim = novo_no;
        return;
    }
    // inserindo no inicio
    if (novo_processo->getPrioridade() > this->inicio->processo->getPrioridade()) {
        novo_no->proximo = this->inicio;
        this->inicio = novo_no;
        return;
    }    
    // insetindo no meio ou fim
    No* atual = this->inicio;

    while (atual->proximo != nullptr 
            && atual->proximo->processo->getPrioridade() >= novo_processo->getPrioridade()) {
        atual = atual->proximo;
    }

    novo_no->proximo = atual->proximo;
    atual->proximo = novo_no;

}

Processo* FilaProcessos::remover_processo_maior_prioridade() {
    if (this->inicio == nullptr) {
        return nullptr; // fila vazia
    }   

    No* no_remover = this->inicio;
    Processo* processo_remover = no_remover->processo;

    this->inicio = this->inicio->proximo; // atualiza o inicio para o proimo

    if (this->inicio == nullptr) {
        this->fim = nullptr; // fila ficou vazia
    }

    return processo_remover;
}

Processo* FilaProcessos::remover_processo_por_id(int id) {
    if (this->inicio == nullptr) {
        return nullptr; // fila vazia
    }

    No* atual = this->inicio;
    No* anterior = nullptr;

    while (atual != nullptr) {
        if (atual->processo->getID() == id) {
            if (anterior == nullptr) { // removendo o primeiro da fila
                this->inicio = atual->proximo;
            } else {
                anterior->proximo = atual->proximo; // pula o nó 
            }

            if (atual == this->fim) { // remove o último
                this->fim = anterior;
            }

            return atual->processo; // retorna processo removido
        }
        anterior = atual;
        atual = atual->proximo;
    }

    return nullptr; // processo com id não encontrado

}

void FilaProcessos::estimativa_tempo_para_execucao(int id) {
    No* atual = this->inicio;
    double tempo_estimado = 0.0;
    Processo* processo_alvo = nullptr;

    while (atual != nullptr) {
        if (atual->processo->getID() == id) {
            processo_alvo = atual->processo;
            break;
        }
        tempo_estimado += atual->processo->tempo_reservado_processo();
        atual = atual->proximo;
    }

    if (processo_alvo != nullptr) {
        std::cout << "Tempo estimado para execução do processo " 
                  << processo_alvo->getNome() 
                  << ", de id= " << processo_alvo->getID() << " é de " 
                  << tempo_estimado 
                  << " segundos." << std::endl;
    } else {
        std::cout << "Processo " << id << " não encontrado!!!" << std::endl;
    }
    
}

void FilaProcessos::imprimir_fila() {
    No* atual = this->inicio;

    while (atual != nullptr) {
        atual->processo->imprimir_dados();
        atual = atual->proximo;
    }
}

