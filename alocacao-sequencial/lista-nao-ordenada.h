#pragma once
#include "elemento.h"

class ListaNaoOrdenada {
private:
    Elemento** dados;
    int capacidade;
    int tamanho;

    void redimensionar() {
        capacidade *= 2;
        Elemento** novo = new Elemento*[capacidade];
        for (int i = 0; i < tamanho; ++i) novo[i] = dados[i];
        delete[] dados;
        dados = novo;
    }

public:
    ListaNaoOrdenada(int cap = 10) : capacidade(cap), tamanho(0) {
        dados = new Elemento*[capacidade];
    }
    ~ListaNaoOrdenada() {
        for (int i = 0; i < tamanho; ++i)
            delete dados[i];
        delete[] dados;
    }

    void InserirNoInicio(Elemento* e) {
        if (tamanho == capacidade) redimensionar();
        for (int i = tamanho; i > 0; --i)
            dados[i] = dados[i - 1];
        dados[0] = e;
        tamanho++;
    }

    void InserirNoFinal(Elemento* e) {
        if (tamanho == capacidade) redimensionar();
        dados[tamanho++] = e;
    }

    void RemoverPrimeiro() {
        if (tamanho == 0) return;
        delete dados[0];
        for (int i = 0; i < tamanho - 1; ++i)
            dados[i] = dados[i + 1];
        tamanho--;
    }

    void RemoverUltimo() {
        if (tamanho == 0) return;
        delete dados[--tamanho];
    }

    void RemoverPeloId(long id) {
        for (int i = 0; i < tamanho; ++i) {
            if (dados[i]->getID() == id) {
                delete dados[i];
                for (int j = i; j < tamanho - 1; ++j)
                    dados[j] = dados[j + 1];
                tamanho--;
                return;
            }
        }
    }

    Elemento* BuscarPeloId(long id) const {
        for (int i = 0; i < tamanho; ++i) {
            if (dados[i]->getID() == id)
                return dados[i];
        }
        return nullptr;
    }

    void AlterarPeloId(long id, Elemento* novo) {
        for (int i = 0; i < tamanho; ++i) {
            if (dados[i]->getID() == id) {
                delete dados[i];
                dados[i] = novo;
                return;
            }
        }
    }

    void ImprimirTodos() const {
        for (int i = 0; i < tamanho; ++i)
            dados[i]->imprimirInfo();
    }
};