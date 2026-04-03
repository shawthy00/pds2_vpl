#ifndef JOGADOR_HPP
#define JOGADOR_HPP

#include <iostream>
#include <string>

class Jogador {

// Atributos
    std::string nome;
    char simbolo; // 'X' ou 'O'

// construtor
public:
    Jogador(std::string nome, char simbolo);

// metodos
std::string getNome();
char getSimbolo();


}


#endif




/*
Representa um jogador da partida, armazenando seu nome e símbolo.

Atributos:
    std::string nome: nome do jogador.
    char simbolo: símbolo utilizado pelo jogador, podendo ser 'X' ou 'O'.

Métodos:
    Jogador(std::string nome, char simbolo): Método construtor que recebe o nome e o símbolo do jogador e os armazena internamente.
    std::string getNome(): Retorna o nome do jogador.
    char getSimbolo(): Retorna o símbolo do jogador ('X' ou 'O').


    */