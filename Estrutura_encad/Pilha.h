#ifndef PILHA_H
#define PILHA_H

#include "ListaSimplesmenteEncadeada.h"

class Pilha {
private:
    ListaSimplesmenteEncadeada lista;

public:
    // Complexidade: O(1)
    void empilhar(Elemento* elemento) {
        lista.inserirNoInicio(elemento);
    }

    // Complexidade: O(n)
    void desempilhar() {
        if (!estaVazia()) {
            Elemento* topo = lista.buscarPeloId(lista.buscarPeloId(0)->getId());
            lista.removerPeloId(topo->getId());
        }
    }

    // Complexidade: O(n)
    Elemento* topo() {
        return lista.buscarPeloId(lista.buscarPeloId(0)->getId());
    }

    // Complexidade: O(n)
    bool estaVazia() {
        return lista.buscarPeloId(0) == nullptr;
    }

    // Complexidade: O(n)
    void imprimir() {
        lista.imprimirTodos();
    }
};

#endif
