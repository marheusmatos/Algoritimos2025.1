#include "ListaSimplesmenteEncadeada.h"
#include <iostream>
using namespace std;

ListaSimplesmenteEncadeada::ListaSimplesmenteEncadeada() : inicio(nullptr) {}

ListaSimplesmenteEncadeada::~ListaSimplesmenteEncadeada() {
    while (inicio) {
        No* temp = inicio;
        inicio = inicio->proximo;
        delete temp->elemento;
        delete temp;
    }
}

void ListaSimplesmenteEncadeada::inserirNoInicio(Elemento* e) {
    No* novo = new No(e);
    novo->proximo = inicio;
    inicio = novo;
}

void ListaSimplesmenteEncadeada::inserirNoFim(Elemento* e) {
    No* novo = new No(e);
    if (!inicio) {
        inicio = novo;
    } else {
        No* temp = inicio;
        while (temp->proximo) temp = temp->proximo;
        temp->proximo = novo;
    }
}

Elemento* ListaSimplesmenteEncadeada::buscarPeloId(int id) {
    No* atual = inicio;
    while (atual) {
        if (atual->elemento->getId() == id)
            return atual->elemento;
        atual = atual->proximo;
    }
    return nullptr;
}

void ListaSimplesmenteEncadeada::removerPeloId(int id) {
    No* atual = inicio;
    No* anterior = nullptr;
    while (atual) {
        if (atual->elemento->getId() == id) {
            if (anterior) anterior->proximo = atual->proximo;
            else inicio = atual->proximo;
            delete atual->elemento;
            delete atual;
            return;
        }
        anterior = atual;
        atual = atual->proximo;
    }
}

void ListaSimplesmenteEncadeada::imprimirTodos() {
    No* atual = inicio;
    while (atual) {
        atual->elemento->imprimirInfo();
        atual = atual->proximo;
    }
}
