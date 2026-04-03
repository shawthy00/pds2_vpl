// declaracao de classes, metodos, atributos privados, constutor basico
#ifdef PESSOA_HPP
#define PESSOA_HPP

class Pessoa {

    // atributos - por padrão o que não e definido dentro da clase se torna private
    double x;
    double y;

    public:
    // construtor
    Pessoa(double x, double y);

    // métodos get, não foram criados set(), pois os atributos não sao privados
    double getX();
    double getY();

    void mover(double dx, double dy);

};

#endif