#include "ListaDuplamenteEncadeada.h"
#include <iostream>
using namespace std;

ListaDuplamenteEncadeada::ListaDuplamenteEncadeada() : inicio(nullptr), fim(nullptr) {}

ListaDuplamenteEncadeada::~ListaDuplamenteEncadeada() {
    while (inicio) {
        No* temp = inicio;
        inicio = inicio->proximo;
        delete temp->elemento;
        delete temp;
    }
}

void ListaDuplamenteEncadeada::inserirNoInicio(Elemento* e) {
    No* novo = new No(e);
    novo->proximo = inicio;
    if (inicio) inicio->anterior = novo;
    else fim = novo;
    inicio = novo;
}

void ListaDuplamenteEncadeada::inserirNoFim(Elemento* e) {
    No* novo = new No(e);
    novo->anterior = fim;
    if (fim) fim->proximo = novo;
    else inicio = novo;
    fim = novo;
}

Elemento* ListaDuplamenteEncadeada::buscarPeloId(int id) {
    No* atual = inicio;
    while (atual) {
        if (atual->elemento->getId() == id)
            return atual->elemento;
        atual = atual->proximo;
    }
    return nullptr;
}

void ListaDuplamenteEncadeada::removerPeloId(int id) {
    No* atual = inicio;
    while (atual) {
        if (atual->elemento->getId() == id) {
            if (atual->anterior)
                atual->anterior->proximo = atual->proximo;
            else
                inicio = atual->proximo;

            if (atual->proximo)
                atual->proximo->anterior = atual->anterior;
            else
                fim = atual->anterior;

            delete atual->elemento;
            delete atual;
            return;
        }
        atual = atual->proximo;
    }
}

void ListaDuplamenteEncadeada::imprimirTodos() {
    No* atual = inicio;
    while (atual) {
        atual->elemento->imprimirInfo();
        atual = atual->proximo;
    }
}
