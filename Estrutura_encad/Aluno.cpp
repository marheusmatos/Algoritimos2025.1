#include "Aluno.h"
#include <iostream>

Aluno::Aluno(int id, const std::string& nome) : Elemento(id), nome(nome) {}

void Aluno::imprimirInfo() const {
    std::cout << "Aluno - ID: " << getId() << ", Nome: " << nome << std::endl;
}
