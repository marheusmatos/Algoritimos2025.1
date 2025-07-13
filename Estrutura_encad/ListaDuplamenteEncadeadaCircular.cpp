#include "ListaDuplamenteEncadeadaCircular.h"
#include <iostream>
using namespace std;

ListaDuplamenteEncadeadaCircular::ListaDuplamenteEncadeadaCircular() : inicio(nullptr) {}

ListaDuplamenteEncadeadaCircular::~ListaDuplamenteEncadeadaCircular() {
    if (!inicio) return;
    No* atual = inicio;
    do {
        No* temp = atual;
        atual = atual->proximo;
        delete temp->elemento;
        delete temp;
    } while (atual != inicio);
    inicio = nullptr;
}

void ListaDuplamenteEncadeadaCircular::inserirNoInicio(Elemento* e) {
    No* novo = new No(e);
    if (!inicio) {
        inicio = novo;
    } else {
        No* fim = inicio->anterior;
        novo->proximo = inicio;
        novo->anterior = fim;
        fim->proximo = novo;
        inicio->anterior = novo;
        inicio = novo;
    }
}

void ListaDuplamenteEncadeadaCircular::inserirNoFim(Elemento* e) {
    No* novo = new No(e);
    if (!inicio) {
        inicio = novo;
    } else {
        No* fim = inicio->anterior;
        fim->proximo = novo;
        novo->anterior = fim;
        novo->proximo = inicio;
        inicio->anterior = novo;
    }
}

Elemento* ListaDuplamenteEncadeadaCircular::buscarPeloId(int id) {
    if (!inicio) return nullptr;
    No* atual = inicio;
    do {
        if (atual->elemento->getId() == id)
            return atual->elemento;
        atual = atual->proximo;
    } while (atual != inicio);
    return nullptr;
}

void ListaDuplamenteEncadeadaCircular::removerPeloId(int id) {
    if (!inicio) return;
    No* atual = inicio;
    do {
        if (atual->elemento->getId() == id) {
            if (atual->proximo == atual) {
                delete atual->elemento;
                delete atual;
                inicio = nullptr;
            } else {
                atual->anterior->proximo = atual->proximo;
                atual->proximo->anterior = atual->anterior;
                if (atual == inicio) inicio = atual->proximo;
                delete atual->elemento;
                delete atual;
            }
            return;
        }
        atual = atual->proximo;
    } while (atual != inicio);
}

void ListaDuplamenteEncadeadaCircular::imprimirTodos() {
    if (!inicio) return;
    No* atual = inicio;
    do {
        atual->elemento->imprimirInfo();
        atual = atual->proximo;
    } while (atual != inicio);
}
