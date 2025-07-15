#ifndef ARVORE_BINARIA_BUSCA_H
#define ARVORE_BINARIA_BUSCA_H

#include <iostream>
#include "Elemento.h"

class ArvoreBinariaBusca {
private:
    class No {
    public:
        Elemento* elemento;
        No* esq;
        No* dir;

        No(Elemento* e) : elemento(e), esq(nullptr), dir(nullptr) {}
        ~No() { delete elemento; }
    };

    No* raiz;

    // Funções auxiliares privadas
    No* inserir(No* raiz, Elemento* elemento);
    No* buscarPeloId(No* raiz, int id) const;
    No* removerPeloId(No* raiz, int id);
    No* minimo(No* raiz) const;

    void emOrdem(No* raiz) const;
    void preOrdem(No* raiz) const;
    void posOrdem(No* raiz) const;

    void destruir(No* raiz);

public:
    ArvoreBinariaBusca();
    ~ArvoreBinariaBusca();

    // Complexidade média O(log n), pior caso O(n)
    void inserir(Elemento* elemento);

    // Complexidade média O(log n), pior caso O(n)
    Elemento* buscarPeloId(int id) const;

    // Complexidade média O(log n), pior caso O(n)
    void removerPeloId(int id);

    // Percursos que imprimem o id
    void emOrdem() const;
    void preOrdem() const;
    void posOrdem() const;
};

#endif
