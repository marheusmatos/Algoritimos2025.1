#pragma once
#include "elemento.h"
#include <string>

class Pessoa : public Elemento {
private:
    std::string nome;
public:
    Pessoa(long id, std::string nome) : Elemento(id), nome(nome) {}
    void imprimirInfo() const override {
        std::cout << "Pessoa ID: " << id << ", Nome: " << nome << std::endl;
    }
};