#ifndef FILA_H
#define FILA_H

#include "ListaDuplamenteEncadeada.h"

class Fila {
private:
    ListaDuplamenteEncadeada lista;

public:
    // Complexidade: O(1)
    void enfileirar(Elemento* elemento) {
        lista.inserirNoFim(elemento);
    }

    // Complexidade: O(n)
    void desenfileirar() {
        if (!estaVazia()) {
            // Supondo que o primeiro elemento tem o menor ID
            Elemento* frente = lista.buscarPeloId(lista.buscarPeloId(0)->getId());
            lista.removerPeloId(frente->getId());
        }
    }

    // Complexidade: O(n)
    Elemento* frente() {
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
