#ifndef COLA_H
#define COLA_H
#include "nodo.h"

class cola
{
public:
    cola();
    virtual ~cola();

    void add(char n);
    char pop();
    char show();

protected:

private:
    nodo* raiz = nullptr;
};

#endif // COLA_H
