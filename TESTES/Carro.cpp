
#include "Carro.hpp"
#include <cmath>
#include <iostream>

// construtor implementacao
Carro::Carro (double x, double y, double th) {
    this->x = x;
    this->y = y;
    this->th = th;
}

// Metodos
double Carro::getX() {
    return this->x;
}

double Carro::getY() {
    return this->y;
}

double Carro::getTH(){
    return this->th;
}


void Carro::girar(double w, double t) {
    this->th += w * t;
}

void Carro::mover(double v, double t) {
    this->x += v * cos(this->th) * t;
    this->y += v * sin(this->th) * t;
}

double Carro::calcular_angulo_pessoa(Pessoa* pessoa) {
    double dx = pessoa->getX() - this->x;
    double dy = pessoa->getY() - this->y;
    double angulo = atan2(dy, dx) - this->th; // em radianos

    return angulo * 180.0 / M_PI;   // retorno em graus

}

double Carro::calcular_distancia_pessoa(Pessoa* pessoa) {
    double dx = pessoa->getX() - this->x;
    double dy = pessoa->getY() - this->y;
    return sqrt(dx*dx + dy*dy);
}

bool Carro::movimentacao_permitida(Pessoa** pessoa, int n) {
    bool permitido = true; // se colocasse return true ou false o loop nao funcionaria

    for (int i = 0; i < n; i++) {
        double angulo = calcular_angulo_pessoa(pessoa[i]);
        double distancia = calcular_distancia_pessoa(pessoa[i]);

        if (angulo >= -45 && angulo <= 45 && distancia < 5) {
            permitido = false;
            std::cout << "Alerta! " << i << "\t" << angulo << "\t" << distancia << std::endl;
        }
    }

    return permitido;

}


void Carro::navegar(Pessoa** pessoas, int n, double w, double v, double t) {
    //...
}




/*
void navegar(Pessoa** pessoas, int n, double w, double v, double t): 
Método responsável por fazer toda a navegação do veículo seguindo a seguinte lógica:
(i) Primeiro verifica a presença de pedestres (Item 7), se a movimentação não for permitida não faz nada, caso contrário, 
(ii) primeiro realiza o giro (Item 3) de acordo com 'w' passado, em seguida 
(iii) move-se para frente (Item 4) de acordo com o 'v' passado.
*/