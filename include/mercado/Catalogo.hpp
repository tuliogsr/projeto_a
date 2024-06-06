// Catalogo.hpp

#ifndef CATALOGO_H
#define CATALOGO_H

#include <string>
#include <iostream>
#include <fstream>


class Catalogo
{
public:
    virtual ~Catalogo() = default;
    virtual void menu_filtrar() = 0;

protected:
    void abrir_arquivo(const std::string& nomeArquivo);
};

class TipoAcoesVariaveis : public Catalogo
{
public:
    void menu_filtrar() override;
};

class TipoRendaFixa : public Catalogo
{
public:
    void menu_filtrar() override;
};

class TipoMoeda : public Catalogo
{
public:
    void menu_filtrar() override;
};

void menu_major();

#endif // CATALOGO_H;