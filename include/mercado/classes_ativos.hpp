#ifndef ATIVOS_H
#define ATIVOS_H

#include <iostream>
#include <string>

class Ativo {
private:
    std::string nome;
    double valor;

public:
    Ativo(const std::string& nome, double valor);
    virtual ~Ativo();
    
    virtual void info() const;
};

class CDI : public Ativo {
public:
    CDI(const std::string& nome, double valor, int quantidade);
    virtual ~CDI();
    
    virtual void info() const override;
};

void classes_ativos();

#endif

//Era historia 3