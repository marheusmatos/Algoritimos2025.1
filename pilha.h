#pragma once
#include "lista-nao-ordenada.h"

class Pilha {
private:
    ListaNaoOrdenada lista;
public:
    void empilhar(Elemento* e) {
        lista.InserirNoFinal(e); // O(1)
    }

    void desempilhar() {
        lista.RemoverUltimo(); // O(1)
    }

    Elemento* consultarTopo() const {
        return lista.BuscarPeloId(lista.BuscarPeloId(-1)->getID()); // ou implementar método Topo()
    }

    bool pilhaVazia() const {
        return lista.BuscarPeloId(-1) == nullptr;
    }
};
