#pragma once
#include "elemento.h"

class ListaOrdenada {
private:
    Elemento** dados;
    int capacidade;
    int tamanho;

    void redimensionar() {
        capacidade *= 2;
        Elemento** novo = new Elemento*[capacidade];
        for (int i = 0; i < tamanho; ++i)
            novo[i] = dados[i];
        delete[] dados;
        dados = novo;
    }

    int buscaBinaria(long id) const {
        int esq = 0, dir = tamanho - 1;
        while (esq <= dir) {
            int meio = (esq + dir) / 2;
            if (dados[meio]->getID() == id)
                return meio;
            else if (dados[meio]->getID() < id)
                esq = meio + 1;
            else
                dir = meio - 1;
        }
        return -1;
    }

public:
    ListaOrdenada(int cap = 10) : capacidade(cap), tamanho(0) {
        dados = new Elemento*[capacidade];
    }
    ~ListaOrdenada() {
        for (int i = 0; i < tamanho; ++i)
            delete dados[i];
        delete[] dados;
    }

    void InserirOrdenado(Elemento* e) {
        if (tamanho == capacidade) redimensionar();
        int i = tamanho - 1;
        while (i >= 0 && dados[i]->getID() > e->getID()) {
            dados[i + 1] = dados[i];
            --i;
        }
        dados[i + 1] = e;
        ++tamanho;
    }

    void RemoverPeloId(long id) {
        int idx = buscaBinaria(id);
        if (idx != -1) {
            delete dados[idx];
            for (int i = idx; i < tamanho - 1; ++i)
                dados[i] = dados[i + 1];
            --tamanho;
        }
    }

    Elemento* BuscarPeloId(long id) const {
        int idx = buscaBinaria(id);
        return idx != -1 ? dados[idx] : nullptr;
    }

    void AlterarPeloId(long id, Elemento* novo) {
        int idx = buscaBinaria(id);
        if (idx != -1) {
            delete dados[idx];
            dados[idx] = novo;
        }
    }

    void ImprimirTodos() const {
        for (int i = 0; i < tamanho; ++i)
            dados[i]->imprimirInfo();
    }
};