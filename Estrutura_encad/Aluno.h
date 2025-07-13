#ifndef ALUNO_H
#define ALUNO_H

#include "Elemento.h"
#include <string>

class Aluno : public Elemento {
private:
    std::string nome;

public:
    Aluno(int id, const std::string& nome);
    void imprimirInfo() const override;
};

#endif
