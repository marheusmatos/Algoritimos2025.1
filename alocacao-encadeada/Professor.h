#ifndef PROFESSOR_H
#define PROFESSOR_H

#include "Elemento.h"
#include <string>

class Professor : public Elemento {
private:
    int id;
    string nome;
public:
    Professor(int id, string nome);
    void imprimirInfo() const override;
    int getId() const override;
};

#endif
