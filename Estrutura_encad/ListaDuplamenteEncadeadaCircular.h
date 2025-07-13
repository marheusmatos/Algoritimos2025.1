#ifndef LISTA_CIRCULAR_H
#define LISTA_CIRCULAR_H

#include "Elemento.h"

class ListaDuplamenteEncadeadaCircular {
private:
    class No {
    public:
        Elemento* elemento;
        No* anterior;
        No* proximo;
        No(Elemento* e) : elemento(e), anterior(this), proximo(this) {}
    };

    No* inicio;

public:
    ListaDuplamenteEncadeadaCircular();
    ~ListaDuplamenteEncadeadaCircular();

    void inserirNoInicio(Elemento* e); // O(1)
    void inserirNoFim(Elemento* e);    // O(1)
    Elemento* buscarPeloId(int id);    // O(n)
    void removerPeloId(int id);        // O(n)
    void imprimirTodos();              // O(n)
};

#endif
