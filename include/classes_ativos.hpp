#ifndef ATIVOS_H
#define ATIVOS_H

#include <iostream>
#include <string>

class Ativo {
protected:
    std::string nome;
    double valor;

public:
    Ativo(const std::string& nome, double valor);
    virtual ~Ativo();
    
    virtual void info() const;
};

class Acao : public Ativo {
private:
    int quantidade;

public:
    Acao(const std::string& nome, double valor, int quantidade);
    virtual ~Acao();
    
    virtual void info() const override;
};

class Moeda : public Ativo {
private:
    std::string simbolo;

public:
    Moeda(const std::string& nome, double valor, const std::string& simbolo);
    virtual ~Moeda();
    
    virtual void info() const override;
};

void classes_ativos();

#endif

//Era historia 3