#ifndef ALERTAS_H
#define ALERTAS_H

#include <iostream>
#include <string>
#include "cadastro_usuario.hpp"

class alertas_preco {
private:
    float preco;
    const Usuario& usuario;
public:
    alertas_preco(float preco, const Usuario& usuario);
    void alertas(); 
    ~alertas_preco();
};



#endif

//Era a Historia 4