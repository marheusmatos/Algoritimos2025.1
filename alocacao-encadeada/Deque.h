#ifndef DEQUE_H
#define DEQUE_H

#include "ListaDuplamenteEncadeadaCircular.h" // Inclui a lista base

class Deque {
private:
    ListaDuplamenteEncadeadaCircular lista; // O Deque utiliza a lista circular

public:
    // Complexidade: O(1) - Delega para o m�todo O(1) da lista
    void inserirNoInicio(Elemento* elemento) {
        lista.inserirNoInicio(elemento);
    }

    // Complexidade: O(1) - Delega para o m�todo O(1) da lista
    void inserirNoFim(Elemento* elemento) {
        lista.inserirNoFim(elemento);
    }

    // Complexidade: O(1) - Delega para o novo m�todo O(1) da lista
    Elemento* removerDoInicio() {
        if (!estaVazia()) {
            return lista.removerDoInicio(); // Retorna o elemento removido
        }
        return nullptr; // Ou lan�a uma exce��o se preferir
    }

    // Complexidade: O(1) - Delega para o novo m�todo O(1) da lista
    Elemento* removerDoFim() {
        if (!estaVazia()) {
            return lista.removerDoFim(); // Retorna o elemento removido
        }
        return nullptr; // Ou lan�a uma exce��o se preferir
    }
    
    // Complexidade: O(1) - Delega para o novo m�todo O(1) da lista
    Elemento* getElementoNoInicio() const {
        return lista.getElementoNoInicio();
    }

    // Complexidade: O(1) - Delega para o novo m�todo O(1) da lista
    Elemento* getElementoNoFim() const {
        return lista.getElementoNoFim();
    }

    // Complexidade: O(1) - Delega para o m�todo O(1) da lista
    bool estaVazia() const { // Adicionado 'const'
        return lista.estaVazia();
    }

    // Complexidade: O(n) - Delega para o m�todo de impress�o da lista
    void imprimir() {
        lista.imprimirTodos();
    }
};

#endif
