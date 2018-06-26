#include "cola.h"

cola::cola()
{
    //ctor
}

cola::~cola()
{
}

void cola::add(char n)
{
    /*if (raiz == nullptr)
    {
        nodo* temp = new nodo();
        temp -> set_valor(n);
        raiz = temp;
    }
    else
    {
        nodo* temp = new nodo();
        temp -> set_valor(n);
        temp -> set_next(raiz);
        raiz = temp;
    }*/

    nodo* temp = new nodo();
    temp -> set_valor(n);
    temp -> set_next(raiz);
    raiz = temp;
}