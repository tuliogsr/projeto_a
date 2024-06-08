#include <iostream> 
#include <string> 
#include <fstream> // Biblioteca para manipulação de arquivos
#include "Catalogo.hpp" 

// Método para abrir um arquivo e imprimir seu conteúdo linha por linha
void Catalogo::abrir_arquivo(const std::string &nomeArquivo)
{
    std::fstream arquivo(nomeArquivo, std::fstream::in); // Abre o arquivo em modo de leitura
    if (arquivo.is_open()) // Verifica se o arquivo foi aberto com sucesso
    {
        std::string linha;
        while (getline(arquivo, linha)) // Lê o arquivo linha por linha
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

// Função para exibir o menu principal e selecionar o catálogo desejado
void menu_major()
{
    int escolha = 0;
    std::cout << "Qual Catalogo quer acessar: \n" << std::endl;
    std::cout << "1 - Catalogo de investimentos em Acoes Variaveis:" << std::endl;
    std::cout << "2 - Catalogo de investimentos em Renda Fixa:" << std::endl;
    std::cout << "3 - Cotacao de moedas:" << std::endl;
    std::cout << "0 - Voltar\n";

    Catalogo *catalogo = nullptr; // Ponteiro para um objeto do tipo Catalogo

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
        catalogo->menu_filtrar(); // Chama o método menu_filtrar do catálogo selecionado
        delete catalogo; // Deleta o objeto criado para liberar a memória
    }
}

// Método para filtrar o catálogo de ações variáveis
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
        menu_major(); // Retorna ao menu principal
        break;
    default:
        std::cout << "Opcao invalida" << std::endl;
        return;
    }
}

// Método para filtrar o catálogo de renda fixa
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
        menu_major(); // Retorna ao menu principal
        std::cout << "\n";
        break;
    default:
        std::cout << "Opcao invalidade" << std::endl;
        return;
    }
}

// Método para filtrar o catálogo de moedas
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
        menu_major(); // Retorna ao menu principal
        break;
    default:
        std::cout << "Opcao invalida" << std::endl;
        return;
    }
}
