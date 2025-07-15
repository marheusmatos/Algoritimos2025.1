#pragma once
#include "lista-nao-ordenada.h"

class FilaIngenua {
private:
    ListaNaoOrdenada lista;
public:
    void enfileirar(Elemento* e) {
        lista.InserirNoFinal(e); // O(1)
    }

    void desenfileirar() {
        lista.RemoverPrimeiro(); // O(n)
    }

    bool filaVazia() const {
        return lista.BuscarPeloId(-1) == nullptr;
    }
};
