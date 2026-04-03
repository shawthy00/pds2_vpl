
#ifndef CARRO_HPP
#define CARRO_HPP

#include "Pessoa.hpp"


class Carro {

    // Atributos
    double x;
    double y;
    double th;

    public:
    // construtor
    Carro (double x, double y, double th);

    // Metodos
    double getX();
    double getY();
    double getTH();

    void girar(double w, double t);
    void mover(double v, double t);

    double calcular_angulo_pessoa(Pessoa* pessoa);
    double calcular_distancia_pessoa(Pessoa* pessoa);
    bool movimentacao_permitida(Pessoa** pessoas, int n);
    void navegar(Pessoa** pessoas, int n, double w, double v, double t);

};

#endif