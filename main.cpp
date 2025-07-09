#include "pessoa.h"
#include "produto.h"
#include "lista-nao-ordenada.h"
#include "lista-ordenada.h"

int main() {
    ListaNaoOrdenada lista1;
    lista1.InserirNoFinal(new Pessoa(3, "Alice"));
    lista1.InserirNoInicio(new Produto(1, "Teclado"));
    lista1.InserirNoFinal(new Pessoa(2, "Bob"));

    std::cout << "\nLista Não Ordenada:" << std::endl;
    lista1.ImprimirTodos();

    lista1.RemoverPeloId(1);
    std::cout << "\nApós remover ID 1:" << std::endl;
    lista1.ImprimirTodos();

    ListaOrdenada lista2;
    lista2.InserirOrdenado(new Pessoa(5, "Joana"));
    lista2.InserirOrdenado(new Produto(4, "Mouse"));
    lista2.InserirOrdenado(new Pessoa(6, "Carlos"));

    std::cout << "\nLista Ordenada:" << std::endl;
    lista2.ImprimirTodos();

    Elemento* buscado = lista2.BuscarPeloId(6);
    if (buscado) {
        std::cout << "\nEncontrado ID 6: ";
        buscado->imprimirInfo();
    }

    return 0;
}
