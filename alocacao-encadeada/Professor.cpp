#include "Professor.h"
#include <iostream>
using namespace std;

Professor::Professor(int id, string nome) : id(id), nome(nome) {}

void Professor::imprimirInfo() const {
    cout << "Professor ID: " << id << ", Nome: " << nome << endl;
}

int Professor::getId() const {
    return id;
}
