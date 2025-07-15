#ifndef LISTA_SIMPLES_H
#define LISTA_SIMPLES_H

#include "Elemento.h"

class ListaSimplesmenteEncadeada {
private:
    class No {
    public:
        Elemento* elemento;
        No* proximo;
        No(Elemento* e) : elemento(e), proximo(nullptr) {}
    };

    No* inicio;

public:
    ListaSimplesmenteEncadeada();
    ~ListaSimplesmenteEncadeada();

    void inserirNoInicio(Elemento* e); // O(1)
    void inserirNoFim(Elemento* e);    // O(n)
    Elemento* buscarPeloId(int id);    // O(n)
    void removerPeloId(int id);        // O(n)
    void imprimirTodos();              // O(n)
};

#endif
