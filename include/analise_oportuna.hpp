#ifndef ANALISE_H
#define ANALISE_H

#include <iostream>
#include <string>
#include "cadastro_usuario.hpp"

class analise_oportuna : public Usuario{
private:
    float preco;
public:
    analise_oportuna(float preco);
    void analise_oportuna();
    ~analise_oportuna();
};
void analise();

#endif

//Era a Historia 5