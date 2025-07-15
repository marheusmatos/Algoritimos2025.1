#include "ArvoreBinariaBusca.h"
#include <iostream>

using namespace std;

ArvoreBinariaBusca::ArvoreBinariaBusca() : raiz(nullptr) {}

ArvoreBinariaBusca::~ArvoreBinariaBusca() {
    destruir(raiz);
}

void ArvoreBinariaBusca::destruir(No* raiz) {
    if (raiz) {
        destruir(raiz->esq);
        destruir(raiz->dir);
        delete raiz;
    }
}

ArvoreBinariaBusca::No* ArvoreBinariaBusca::inserir(No* raiz, Elemento* elemento) {
    if (!raiz) {
        return new No(elemento);
    }
    if (elemento->getId() < raiz->elemento->getId()) {
        raiz->esq = inserir(raiz->esq, elemento);
    } else if (elemento->getId() > raiz->elemento->getId()) {
        raiz->dir = inserir(raiz->dir, elemento);
    } else {
        // Id já existe, não insere
        // Você pode lançar exceção ou ignorar
    }
    return raiz;
}

void ArvoreBinariaBusca::inserir(Elemento* elemento) {
    raiz = inserir(raiz, elemento);
}

ArvoreBinariaBusca::No* ArvoreBinariaBusca::buscarPeloId(No* raiz, int id) const {
    if (!raiz) return nullptr;
    if (id == raiz->elemento->getId()) return raiz;
    if (id < raiz->elemento->getId()) return buscarPeloId(raiz->esq, id);
    else return buscarPeloId(raiz->dir, id);
}

Elemento* ArvoreBinariaBusca::buscarPeloId(int id) const {
    No* no = buscarPeloId(raiz, id);
    if (no) return no->elemento;
    return nullptr;
}

ArvoreBinariaBusca::No* ArvoreBinariaBusca::minimo(No* raiz) const {
    while (raiz && raiz->esq)
        raiz = raiz->esq;
    return raiz;
}

ArvoreBinariaBusca::No* ArvoreBinariaBusca::removerPeloId(No* raiz, int id) {
    if (!raiz) return nullptr;
    if (id < raiz->elemento->getId()) {
        raiz->esq = removerPeloId(raiz->esq, id);
    } else if (id > raiz->elemento->getId()) {
        raiz->dir = removerPeloId(raiz->dir, id);
    } else {
        // Nó encontrado
        if (!raiz->esq) {
            No* temp = raiz->dir;
            raiz->dir = nullptr;
            delete raiz;
            return temp;
        } else if (!raiz->dir) {
            No* temp = raiz->esq;
            raiz->esq = nullptr;
            delete raiz;
            return temp;
        } else {
            // Dois filhos: pega o menor da subárvore direita
            No* temp = minimo(raiz->dir);
            // Copia o elemento (substituir o ponteiro antigo)
            Elemento* tempElemento = raiz->elemento;
            raiz->elemento = temp->elemento;
            temp->elemento = tempElemento;

            raiz->dir = removerPeloId(raiz->dir, temp->elemento->getId());
        }
    }
    return raiz;
}

void ArvoreBinariaBusca::removerPeloId(int id) {
    raiz = removerPeloId(raiz, id);
}

void ArvoreBinariaBusca::emOrdem(No* raiz) const {
    if (!raiz) return;
    emOrdem(raiz->esq);
    cout << raiz->elemento->getId() << " ";
    emOrdem(raiz->dir);
}

void ArvoreBinariaBusca::preOrdem(No* raiz) const {
    if (!raiz) return;
    cout << raiz->elemento->getId() << " ";
    preOrdem(raiz->esq);
    preOrdem(raiz->dir);
}

void ArvoreBinariaBusca::posOrdem(No* raiz) const {
    if (!raiz) return;
    posOrdem(raiz->esq);
    posOrdem(raiz->dir);
    cout << raiz->elemento->getId() << " ";
}

void ArvoreBinariaBusca::emOrdem() const {
    emOrdem(raiz);
    cout << "\n";
}

void ArvoreBinariaBusca::preOrdem() const {
    preOrdem(raiz);
    cout << "\n";
}

void ArvoreBinariaBusca::posOrdem() const {
    posOrdem(raiz);
    cout << "\n";
}
