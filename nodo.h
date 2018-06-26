#ifndef NODO_H
#define NODO_H


class nodo
{
public:
    nodo() {}
    virtual ~nodo() {}

    void set_valor(char v) {valor = v;}
    char get_valor() {return valor;}

    void set_next(nodo *n) {next = n;}
    nodo* get_next() {return next;}

protected:

private:
    char valor;
    nodo* next;
};

#endif // NODO_H
