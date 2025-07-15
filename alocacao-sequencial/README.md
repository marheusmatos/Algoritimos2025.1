# Algoritmos e Estruturas de Dados - Parte I
**Universidade do Estado do Rio de Janeiro – 2025.1**  

## 🧠 Objetivo
Este trabalho tem como objetivo aplicar os quatro pilares da Programação Orientada a Objetos (POO) – **Abstração, Encapsulamento, Herança e Polimorfismo** – na implementação de estruturas de dados sequenciais em C++, seguindo as melhores práticas de código limpo e modularidade.

---

## 🧱 Estruturas Implementadas

### 📦 Hierarquia de Classes
- **Elemento (abstrata)**  
  - Atributo `id` protegido.  
  - Método `getID()` público.  
  - Método virtual puro `imprimirInfo()`.

- **Pessoa** e **Produto** (herdam de `Elemento`)  
  - Cada uma implementa `imprimirInfo()` com atributos próprios.

### 📋 Estruturas de Dados com Alocação Sequencial

#### 1. Lista Não Ordenada
- `InserirNoInicio`, `InserirNoFinal`
- `RemoverPrimeiro`, `RemoverUltimo`, `RemoverPeloId`
- `BuscarPeloId`, `AlterarPeloId`

#### 2. Lista Ordenada
- Mantém ordem crescente de `id`
- `InserirOrdenado`
- Busca otimizada com **busca binária**

#### 3. Pilha (composição com Lista Não Ordenada)
- `empilhar`, `desempilhar`, `consultarTopo`
- `pilhaVazia`, `pilhaCheia`

#### 4. Fila
- **Versão Ingênua**: baseada na Lista Não Ordenada
- **Versão Otimizada**: com buffer circular

---

## 💡 Decisões de Projeto

- Utilizamos **composição** nas implementações de pilha e fila para maximizar o reuso de código e respeitar o princípio de responsabilidade única.
- A **busca binária** foi aplicada à `ListaOrdenada` para reduzir a complexidade da busca de O(n) para O(log n).
- Optamos por usar `Elemento*` para permitir o uso de polimorfismo com objetos de diferentes classes derivadas.
- A **alocação dinâmica** com vetores foi gerenciada manualmente com redimensionamento para simular `std::vector`.

---

## 📊 Tabela de Complexidade

| Estrutura         | Método              | Complexidade | Observação                        |
|-------------------|---------------------|--------------|-----------------------------------|
| Lista Não Ordenada| InserirNoInicio     | O(n)         | Deslocamento                      |
|                   | InserirNoFinal      | O(1)*        | Amortizado                        |
|                   | RemoverPrimeiro     | O(n)         | Deslocamento                      |
|                   | RemoverUltimo       | O(1)         | Direto                            |
|                   | BuscarPeloId        | O(n)         | Busca linear                      |
|                   | RemoverPeloId       | O(n)         | Busca + deslocamento              |
|                   | AlterarPeloId       | O(n)         | Busca + substituição              |
| Lista Ordenada    | InserirOrdenado     | O(n)         | Inserção com deslocamento         |
|                   | BuscarPeloId        | O(log n)     | Busca binária                     |
|                   | RemoverPeloId       | O(n)         | Busca binária + deslocamento      |
| Pilha             | empilhar/desempilhar| O(1)         | Inserção/rem. no final da lista   |
|                   | consultarTopo       | O(1)         | (caso método seja adicionado)     |
| Fila Ingênua      | enfileirar          | O(1)         | Inserção no final                 |
|                   | desenfileirar       | O(n)         | Remoção e deslocamento            |
| Fila Circular     | enfileirar          | O(1)         | Uso de índice circular            |
|                   | desenfileirar       | O(1)         | Remoção por índice circular       |

\* Inserção no final é O(1) amortizado considerando redimensionamento dinâmico.

---

## 🧪 Demonstração no `main.cpp`
- Armazenamento de objetos `Pessoa` e `Produto` em uma lista comum, demonstrando **polimorfismo**.
- Testes de inserção, remoção e busca por ID em ambas as listas.
- Demonstração das operações de pilha e fila (versão ingênua e circular).

---

## 👥 Integrantes do Grupo
- João Marcelo Pimentel
- Nathalya Viana
- Matheus Matos

---

## ✅ Compilação
Para compilar:

```bash
g++ main.cpp -o programa
./programa
