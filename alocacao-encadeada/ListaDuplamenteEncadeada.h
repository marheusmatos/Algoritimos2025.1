#ifndef LISTA_DUPLA_H
#define LISTA_DUPLA_H

#include "Elemento.h"

class ListaDuplamenteEncadeada {
private:
    class No {
    public:
        Elemento* elemento;
        No* anterior;
        No* proximo;
        No(Elemento* e) : elemento(e), anterior(nullptr), proximo(nullptr) {}
    };

    No* inicio;
    No* fim;

public:
    ListaDuplamenteEncadeada();
    ~ListaDuplamenteEncadeada();

    void inserirNoInicio(Elemento* e); // O(1)
    void inserirNoFim(Elemento* e);    // O(1)
    Elemento* buscarPeloId(int id);    // O(n)
    void removerPeloId(int id);        // O(n)
    void imprimirTodos();              // O(n)
};

#endif
