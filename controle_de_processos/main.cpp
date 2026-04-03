// NÃO ALTERE ESSA LINHA
#include "avaliacao_basica_controle.hpp"
#include "FilaProcessos.hpp"

int main() {
    FilaProcessos fila;

    char entrada;

    while (std::cin >> entrada) {

        switch (entrada) {

            case 'a': {
                std::string nome;
                int prioridade;
                std::cin >> nome >> prioridade;
                fila.adicionar_processo(nome, prioridade);
                break;
            }

            case 'r': {
                fila.remover_processo_maior_prioridade();
                break;
            }

            case 'i': {
                int id;
                std::cin >> id;
                fila.remover_processo_por_id(id);
                break;
            }

            case 'p': {
                fila.imprimir_fila();
                break;
            }

            case 'e': {
                int id;
                std::cin >> id;
                fila.estimativa_tempo_para_execucao(id);
                break;
            }

            case 'b': {
                avaliacao_basica();
                break;
            }
        }
    }

    return 0;
}
