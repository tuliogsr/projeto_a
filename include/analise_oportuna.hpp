#ifndef ANALISE_H
#define ANALISE_H

#include <iostream>
#include <string>
#include "cadastro_usuario.hpp"

class analise_oportuna : public Usuario{
private:
    float oportuna;
public:
    analise_oportuna(float oportuna);
    void analise();
    ~analise_oportuna();
};

#endif

//Era a Historia 5