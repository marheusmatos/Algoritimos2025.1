#ifndef ELEMENTO_H
#define ELEMENTO_H

class Elemento {
protected:
    int id;

public:
    Elemento(int id);
    virtual ~Elemento() = default;

    virtual int getId() const;
    virtual void imprimirInfo() const = 0;
};

#endif
