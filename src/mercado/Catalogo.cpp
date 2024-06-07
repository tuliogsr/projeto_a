// Catalogo.cpp

#include <iostream>
#include <string>
#include <fstream>
#include "Catalogo.hpp"

void Catalogo::abrir_arquivo(const std::string &nomeArquivo)
{
    std::fstream arquivo(nomeArquivo, std::fstream::in);
    if (arquivo.is_open())
    {
        std::string linha;
        while (getline(arquivo, linha))
        {
            std::cout << linha << std::endl;
        }
        arquivo.close();
    }
    else
    {
        std::cerr << "Não foi possível abrir o arquivo: " << nomeArquivo << std::endl;
    }
}

void menu_major()
{
    int escolha = 0;
    std::cout << "Qual Catalogo quer acessar: \n" << std::endl;
    std::cout << "1 - Catalogo de investimentos em Acoes Variaveis:" << std::endl;
    std::cout << "2 - Catalogo de investimentos em Renda Fixa:" << std::endl;
    std::cout << "3 - Cotacao de moedas:" << std::endl;
    std::cout << "0 - Voltar\n";

    Catalogo *catalogo = nullptr;

    std::cout << "Escolha: ";
    std::cin >> escolha;
    std::cout << "\n";

    switch (escolha)
    {
    case 1:
        catalogo = new TipoAcoesVariaveis();
        break;
    case 2:
        catalogo = new TipoRendaFixa();
        break;
    case 3:
        catalogo = new TipoMoeda();
        break;
    case 0:
        std::cout << "Voltando...\n";

    default:
        std::cout << "Opção invalida\n" << std::endl;
        return;
    }

    if (catalogo)
    {
        catalogo->menu_filtrar();
        delete catalogo;
    }
}

void TipoAcoesVariaveis::menu_filtrar()
{

    int escolha = 0;
    std::cout << "Filtrar por:\n" << std::endl;
    std::cout << "1- Todos:" << std::endl;
    std::cout << "2- Variacao:" << std::endl;
    std::cout << "3- Rentabilidade:" << std::endl;
    std::cout << "4- Recomendados:" << std::endl;
    std::cout << "0- Voltar\n";

    std::cout << "Escolha: ";
    std::cin >> escolha;
    std::cout << "\n";

    switch (escolha)
    {
    case 1:
        std::cout << "Todos:" << std::endl;  
        abrir_arquivo("TodosAcoesVaria.txt");
        std::cout << "\n";

        break;
    case 2:
        std::cout << "Variacao:" << std::endl;
        abrir_arquivo("VariacAcaoVarialvel.txt");
        std::cout << "\n";

        break;

    case 3:
        std::cout << "Rentabilidade:" << std::endl;
        abrir_arquivo("RentabAcoeVaria.txt");
        std::cout << "\n";

        break;

    case 4:
        std::cout << "Recomendados:\n" << std::endl;
        abrir_arquivo("RecomendaAcoVar.txt");
        std::cout << "\n";

        break;
    case 0:
        std::cout << "Voltando" << std::endl;
        menu_major();

        break;

    default:
        std::cout << "Opcao invalida" << std::endl;

        return;
    }
}

void TipoRendaFixa::menu_filtrar()
{
    int escolha = 0;
    std::cout << "Filtrar por:\n" << std::endl;
    std::cout << "1- Todos:" << std::endl;
    std::cout << "2- Imposto:" << std::endl;
    std::cout << "3- Recomendados:" << std::endl;
    std::cout << "0- Voltar\n";

    std::cout << "Escolha: ";
    std::cin >> escolha;
    std::cout << "\n";

    switch (escolha)
    {
    case 1:
        std::cout << "Todos:" << std::endl;
        abrir_arquivo("TodosRendaFix.txt");
        std::cout << "\n";

        break;
    case 2:
        std::cout << "Imposto:" << std::endl;
        abrir_arquivo("ImpostoRendaFix.txt");
        std::cout << "\n";

        break;

    case 3:
        std::cout << "Recomendado:" << std::endl;
        abrir_arquivo("RecomendaRenFix.txt");
        std::cout << "\n";


        break;

    case 0:
        std::cout << "Voltando\n" << std::endl;
        menu_major();
        std::cout << "\n";

        break;
    default:
        std::cout << "Opcao invalidade" << std::endl;

        return;
    }
}

void TipoMoeda::menu_filtrar()
{
    int escolha = 0;
    std::cout << "Filtrar por:\n" << std::endl;
    std::cout << "1- Todos:" << std::endl;
    std::cout << "2- Tendencia de cair:" << std::endl;
    std::cout << "0- Voltar\n";

    std::cout << "Escolha: ";
    std::cin >> escolha;
    std::cout << "\n";

    switch (escolha)
    {
    case 1:
        std::cout << "Todos:" << std::endl;
        abrir_arquivo("TodosMoedas.txt");
        break;
    case 2:
        std::cout << "Tendencia de cair:" << std::endl;
        abrir_arquivo("TendencCairMoedas.txt");
        break;

    case 0:
        std::cout << "Voltando...\n" << std::endl;
        menu_major();

        break;
    default:
        std::cout << "Opcao invalida" << std::endl;

        return;
    }
}

int main()
{
    menu_major();
    return 0;
}