#pragma once
#include "elemento.h"

class FilaCircular {
private:
    Elemento** dados;
    int capacidade;
    int inicio, fim, tamanho;

public:
    FilaCircular(int cap = 10) : capacidade(cap), inicio(0), fim(0), tamanho(0) {
        dados = new Elemento*[capacidade];
    }

    ~FilaCircular() {
        for (int i = 0; i < tamanho; ++i)
            delete dados[(inicio + i) % capacidade];
        delete[] dados;
    }

    void enfileirar(Elemento* e) {
        if (tamanho == capacidade) return; // cheia
        dados[fim] = e;
        fim = (fim + 1) % capacidade;
        ++tamanho;
    }

    void desenfileirar() {
        if (tamanho == 0) return; // vazia
        delete dados[inicio];
        inicio = (inicio + 1) % capacidade;
        --tamanho;
    }

    bool filaVazia() const {
        return tamanho == 0;
    }
};
