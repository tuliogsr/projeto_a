#ifndef CATALOGO_H
#define CATALOGO_H

#include <iostream>
#include <string>
#include <fstream>


class Catalogo 
{
private:
    std::ifstream arquivo;  // Stream de arquivo de entrada
public:
    Catalogo(/* args */);
    ~Catalogo();
};

Catalogo::Catalogo(/* args */)
{
}

Catalogo::~Catalogo()
{
}


void catalogo();

#endif

//Era a historia 1