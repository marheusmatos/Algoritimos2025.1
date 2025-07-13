#include <iostream>
#include "Aluno.h"
#include "Professor.h"
#include "ListaSimplesmenteEncadeada.h"
#include "ListaDuplamenteEncadeada.h"
#include "ListaDuplamenteEncadeadaCircular.h"
#include "Pilha.h"
#include "Fila.h"
#include "Deque.h"
#include "ArvoreBinariaBusca.h"

// Para usar std::cout, std::endl, etc. diretamente
using namespace std;

int main() {
    cout << "========================================\n";
    cout << "=== Demonstração de Estruturas de Dados ===\n";
    cout << "========================================\n\n";

    // --- Teste das Listas Encadeadas (Demonstração de Polimorfismo) ---
    cout << "=== Teste das Listas Encadeadas ===\n";

    // 1. Lista Simplesmente Encadeada
    cout << "\n--- Lista Simplesmente Encadeada ---\n";
    ListaSimplesmenteEncadeada listaSimples;
    cout << "Inserindo elementos (Aluno e Professor):\n";
    listaSimples.inserirNoInicio(new Aluno(101, "Ana Silva"));
    listaSimples.inserirNoFim(new Professor(201, "Dr. Bruno Costa"));
    listaSimples.inserirNoFim(new Aluno(102, "Carla Santos"));
    listaSimples.inserirNoInicio(new Professor(202, "Dra. Denise Lima"));
    listaSimples.imprimirTodos(); // Deve mostrar Aluno e Professor corretamente

    cout << "\nBuscando ID 102: ";
    Elemento* encontradoSimples = listaSimples.buscarPeloId(102);
    if (encontradoSimples) {
        encontradoSimples->imprimirInfo();
    } else {
        cout << "Elemento nao encontrado.\n";
    }

    cout << "Removendo elemento com ID 201 (Dr. Bruno Costa):\n";
    listaSimples.removerPeloId(201);
    listaSimples.imprimirTodos();

    cout << "Removendo do inicio:\n";
    if (listaSimples.removerDoInicio()) { // Assume que removerDoInicio retorna Elemento* ou bool
        cout << "Removido do inicio.\n";
    }
    listaSimples.imprimirTodos();

    cout << "Removendo do fim:\n";
    if (listaSimples.removerDoFim()) { // Assume que removerDoFim retorna Elemento* ou bool
        cout << "Removido do fim.\n";
    }
    listaSimples.imprimirTodos();

    // 2. Lista Duplamente Encadeada
    cout << "\n--- Lista Duplamente Encadeada ---\n";
    ListaDuplamenteEncadeada listaDupla;
    cout << "Inserindo elementos (Aluno e Professor):\n";
    listaDupla.inserirNoInicio(new Professor(301, "Prof. Fernando Goes"));
    listaDupla.inserirNoFim(new Aluno(103, "Gustavo Almeida"));
    listaDupla.inserirNoFim(new Professor(302, "Profa. Helena Dias"));
    listaDupla.inserirNoInicio(new Aluno(104, "Igor Pereira"));
    listaDupla.imprimirTodos(); 

    cout << "\nBuscando ID 104: ";
    Elemento* encontradoDupla = listaDupla.buscarPeloId(104);
    if (encontradoDupla) {
        encontradoDupla->imprimirInfo();
    } else {
        cout << "Elemento nao encontrado.\n";
    }

    cout << "Removendo elemento com ID 301 (Prof. Fernando Goes):\n";
    listaDupla.removerPeloId(301);
    listaDupla.imprimirTodos();

    cout << "Imprimindo em ordem inversa (se disponivel e implementado):\n";
   
    listaDupla.imprimirTodos();


    // 3. Lista Duplamente Encadeada Circular
    cout << "\n--- Lista Duplamente Encadeada Circular ---\n";
    ListaDuplamenteEncadeadaCircular listaCircular;
    cout << "Inserindo elementos (Aluno e Professor):\n";
    listaCircular.inserirNoInicio(new Aluno(105, "Juliana Campos"));
    listaCircular.inserirNoFim(new Professor(401, "Dr. Lucas Martins"));
    listaCircular.inserirNoFim(new Aluno(106, "Mariana Rocha"));
    listaCircular.inserirNoInicio(new Professor(402, "Dra. Natalia Gomes"));
    listaCircular.imprimirTodos(); // Deve mostrar Aluno e Professor corretamente

    cout << "\nBuscando ID 106: ";
    Elemento* encontradoCircular = listaCircular.buscarPeloId(106);
    if (encontradoCircular) {
        encontradoCircular->imprimirInfo();
    } else {
        cout << "Elemento nao encontrado.\n";
    }

    cout << "Removendo elemento com ID 401 (Dr. Lucas Martins):\n";
    listaCircular.removerPeloId(401);
    listaCircular.imprimirTodos();


    // --- Teste das Estruturas Adaptadoras ---
    cout << "\n=== Teste das Estruturas Adaptadoras ===\n";

    // 1. Pilha 
    cout << "\n--- Pilha (Stack) ---\n";
    Pilha pilha;
    cout << "Empilhando elementos (Aluno e Professor):\n";
    pilha.empilhar(new Aluno(107, "Otavio Nunez"));
    pilha.empilhar(new Professor(501, "Profa. Patricia Reis"));
    pilha.empilhar(new Aluno(108, "Quiteria Souza"));
    cout << "Pilha (topo primeiro):\n";
    pilha.imprimir();

    cout << "Desempilhando:\n";
    if (!pilha.estaVazia()) {
        Elemento* topo = pilha.desempilhar();
        if (topo) {
            cout << "Elemento desempilhado: ";
            topo->imprimirInfo();
        }
    }
    cout << "Pilha apos desempilhar:\n";
    pilha.imprimir();

    cout << "Verificando se a pilha esta vazia: " << (pilha.estaVazia() ? "Sim" : "Nao") << "\n";

    // 2. Fila 
    cout << "\n--- Fila (Queue) ---\n";
    Fila fila;
    cout << "Enfileirando elementos (Aluno e Professor):\n";
    fila.enfileirar(new Professor(601, "Dr. Ricardo Santos"));
    fila.enfileirar(new Aluno(109, "Sofia Teixeira"));
    fila.enfileirar(new Professor(602, "Profa. Tania Vianna"));
    cout << "Fila (frente primeiro):\n";
    fila.imprimir();

    cout << "Desenfileirando:\n";
    if (!fila.estaVazia()) {
        Elemento* frente = fila.desenfileirar();
        if (frente) {
            cout << "Elemento desenfileirado: ";
            frente->imprimirInfo();
        }
    }
    cout << "Fila apos desenfileirar:\n";
    fila.imprimir();

    cout << "Verificando se a fila esta vazia: " << (fila.estaVazia() ? "Sim" : "Nao") << "\n";

    // 3. Deque 
    cout << "\n--- Deque (Double-Ended Queue) ---\n";
    Deque deque;
    cout << "Inserindo no inicio e no fim (Aluno e Professor):\n";
    deque.inserirNoInicio(new Aluno(110, "Ubiratan Xavier"));
    deque.inserirNoFim(new Professor(701, "Dra. Viviane Zerbini"));
    deque.inserirNoInicio(new Aluno(111, "Wesley Castro"));
    deque.inserirNoFim(new Professor(702, "Prof. Yara Drummond"));
    cout << "Deque (todos elementos):\n";
    deque.imprimir();

    cout << "Elemento no inicio: ";
    if (deque.getElementoNoInicio()) {
        deque.getElementoNoInicio()->imprimirInfo();
    } else {
        cout << "Deque vazio.\n";
    }

    cout << "Elemento no fim: ";
    if (deque.getElementoNoFim()) {
        deque.getElementoNoFim()->imprimirInfo();
    } else {
        cout << "Deque vazio.\n";
    }

    cout << "Removendo do inicio:\n";
    if (!deque.estaVazia()) {
        Elemento* removidoInicio = deque.removerDoInicio();
        if (removidoInicio) {
            cout << "Elemento removido do inicio: ";
            removidoInicio->imprimirInfo();
        }
    }
    cout << "Deque apos remocao do inicio:\n";
    deque.imprimir();

    cout << "Removendo do fim:\n";
    if (!deque.estaVazia()) {
        Elemento* removidoFim = deque.removerDoFim();
        if (removidoFim) {
            cout << "Elemento removido do fim: ";
            removidoFim->imprimirInfo();
        }
    }
    cout << "Deque apos remocao do fim:\n";
    deque.imprimir();


    // --- Teste da Árvore Binária de Busca ---
    cout << "\n=== Teste da Árvore Binária de Busca ===\n";

    ArvoreBinariaBusca arvore;
    cout << "Inserindo elementos (Aluno e Professor):\n";
    arvore.inserir(new Aluno(50, "Zeus"));
    arvore.inserir(new Professor(30, "Atena"));
    arvore.inserir(new Aluno(70, "Hera"));
    arvore.inserir(new Professor(20, "Apolo"));
    arvore.inserir(new Aluno(40, "Artemis"));
    arvore.inserir(new Professor(60, "Poseidon"));
    arvore.inserir(new Aluno(80, "Hades"));

    cout << "Percurso Em Ordem (IDs crescentes): ";
    arvore.emOrdem(); // Deve imprimir IDs em ordem crescente
    cout << "Percurso Pre Ordem (raiz, esq, dir): ";
    arvore.preOrdem();
    cout << "Percurso Pos Ordem (esq, dir, raiz): ";
    arvore.posOrdem();

    cout << "\nBuscando ID 40: ";
    Elemento* buscadoArvore = arvore.buscarPeloId(40);
    if (buscadoArvore) {
        buscadoArvore->imprimirInfo();
    } else {
        cout << "Elemento nao encontrado.\n";
    }

    cout << "Buscando ID 99 (inexistente): ";
    buscadoArvore = arvore.buscarPeloId(99);
    if (buscadoArvore) {
        buscadoArvore->imprimirInfo();
    } else {
        cout << "Elemento nao encontrado.\n";
    }

    cout << "\nRemovendo ID 30 (Atena - no com um filho):\n";
    arvore.removerPeloId(30);
    cout << "Percurso Em Ordem apos remocao: ";
    arvore.emOrdem();

    cout << "Removendo ID 50 (Zeus - no com dois filhos):\n";
    arvore.removerPeloId(50);
    cout << "Percurso Em Ordem apos remocao: ";
    arvore.emOrdem();

    cout << "Removendo ID 80 (Hades - no folha):\n";
    arvore.removerPeloId(80);
    cout << "Percurso Em Ordem apos remocao: ";
    arvore.emOrdem();

    cout << "\n========================================\n";
    cout << "=== Fim da Demonstração ===\n";
    cout << "========================================\n";

    // Os objetos Elemento* alocados com 'new' são gerenciados e deletados
    // pelos destrutores das estruturas (listas, pilha, fila, deque, arvore)
    // ou pelos métodos de remoção. Não é necessário 'delete' aqui em main().

    return 0;
}
