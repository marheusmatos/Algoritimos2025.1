#pragma once
#include <iostream>

class Elemento {
protected:
    long id;
public:
    Elemento(long _id) : id(_id) {}
    virtual ~Elemento() {}
    long getID() const { return id; }
    virtual void imprimirInfo() const = 0;
};