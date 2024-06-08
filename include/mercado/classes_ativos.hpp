#ifndef CLASSES_ATIVOS_HPP
#define CLASSES_ATIVOS_HPP

#include <iostream>

// Classe base Ativo com encapsulamento aprimorado
class Ativo {
protected:
    std::string nome;
    double valor;

public:
    Ativo(const std::string& nome, double valor);
    virtual ~Ativo();

    std::string getNome() const;
    double getValor() const;
    void setNome(const std::string& nome);
    void setValor(double valor);

    virtual void info() const;
};

// Classe derivada CDI com encapsulamento aprimorado
class CDI : public Ativo {
private:
    int quantidade;

public:
    CDI(const std::string& nome, double valor, int quantidade);
    virtual ~CDI();

    int getQuantidade() const;
    void setQuantidade(int quantidade);

    virtual void info() const override;
};

#endif // CLASSES_ATIVOS_HPP
