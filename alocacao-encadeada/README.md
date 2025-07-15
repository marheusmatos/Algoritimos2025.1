# Estruturas de Dados com Alocação Encadeada

##  Descrição do Projeto

Este projeto implementa diversas estruturas de dados clássicas em C++ utilizando **alocação dinâmica encadeada**, com foco na aplicação dos quatro pilares da Programação Orientada a Objetos: **Abstração, Encapsulamento, Herança e Polimorfismo**. Todas as estruturas foram construídas com base em uma classe abstrata chamada `Elemento`.

As estruturas implementadas incluem:
- Listas encadeadas (simples, duplamente e circularmente duplamente encadeadas),
- Pilha e Fila usando composição,
- Deque,
- Árvore Binária de Busca.

##  Decisões de Projeto

- **Encapsulamento dos nós**: Cada estrutura define seus próprios nós como **classes privadas**, impossibilitando o acesso externo e garantindo encapsulamento.
- **Composição para Pilha, Fila e Deque**: Essas estruturas utilizam instâncias internas de listas para reaproveitamento de código e manter baixo acoplamento.
- **Polimorfismo via classe `Elemento`**: Todas as estruturas manipulam objetos do tipo `Elemento*`, permitindo o uso de objetos heterogêneos nas listas.
- **Abstração e Herança**: Criamos classes como `Pessoa` e `Produto` herdando de `Elemento`, cada uma com implementações específicas do método `imprimirInfo()`.

##  Estrutura de Testes (`main.cpp`)

O programa `main.cpp` foi desenvolvido para demonstrar:
- Inserções e remoções nas listas encadeadas;
- Uso correto dos métodos das estruturas adaptadoras (Pilha, Fila, Deque);
- Percursos da árvore binária de busca (em ordem, pré-ordem, pós-ordem);
- Correto funcionamento do polimorfismo ao chamar `imprimirInfo()`.

##  Tabela de Complexidade das Operações

| Estrutura                      | Operação             | Complexidade |
|-------------------------------|----------------------|--------------|
| ListaSimplesmenteEncadeada    | Inserir no início    | O(1)         |
|                               | Inserir no fim       | O(n)         |
|                               | Remover pelo ID      | O(n)         |
|                               | Buscar pelo ID       | O(n)         |
| ListaDuplamenteEncadeada      | Inserir no início    | O(1)         |
|                               | Inserir no fim       | O(1)         |
|                               | Remover pelo ID      | O(n)         |
|                               | Buscar pelo ID       | O(n)         |
| ListaDuplamenteEncadeadaCirc. | Inserir no fim       | O(1)         |
|                               | Remover pelo ID      | O(n)         |
| Pilha (com lista encadeada)   | Empilhar             | O(1)         |
|                               | Desempilhar          | O(1)         |
| Fila (com lista encadeada)    | Enfileirar           | O(1)         |
|                               | Desenfileirar        | O(1)         |
| Deque                         | Inserir/remover fim  | O(1)         |
|                               | Inserir/remover início | O(1)       |
| Árvore Binária de Busca       | Inserir              | O(log n)\*   |
|                               | Remover              | O(log n)\*   |
|                               | Buscar               | O(log n)\*   |
|                               | Percursos            | O(n)         |

> \* No pior caso (árvore desbalanceada), a complexidade pode chegar a O(n)

##  Integrantes do Grupo

- Matheus Matos
- João Marcelo Pimentel
- Nathalya Viana - Contribuiu com o desenvolvimento das estruturas de alocação encadeada. Embora não tenha realizado commits diretos no repositório, trabalhou em conjunto com João Marcelo, que integrou seu código ao projeto final.