#pragma once
#include "elemento.h"
#include <string>

class Produto : public Elemento {
private:
    std::string descricao;
public:
    Produto(long id, std::string desc) : Elemento(id), descricao(desc) {}
    void imprimirInfo() const override {
        std::cout << "Produto ID: " << id << ", Desc: " << descricao << std::endl;
    }
};