#include "analise_oportuna.hpp"
#include <iostream>
#include <fstream>
#include <vector>
#include <cstdlib>
#include <ctime>

analise_oportuna::analise_oportuna() {}

void analise_oportuna::imprimir_oportunidade_recomendada(const std::string& arquivo_nome) {
    std::ifstream arquivo(arquivo_nome);
    if (!arquivo.is_open()) {
        std::cerr << "Erro ao abrir o arquivo: " << arquivo_nome << std::endl;
        return;
    }

    std::vector<std::string> linhas;
    std::string linha;

    // Lê todas as linhas do arquivo e armazena no vetor
    while (std::getline(arquivo, linha)) {
        if (!linha.empty()) {
            linhas.push_back(linha);
        }
    }

    arquivo.close();

    if (linhas.size() > 1) { // Ignora a primeira linha (cabeçalho)
        // Inicializa o gerador de números aleatórios
        std::srand(static_cast<unsigned int>(std::time(nullptr)));
        int indice_aleatorio = std::rand() % (linhas.size() - 1) + 1; // Ignora a linha de cabeçalho
        std::cout << " " << std::endl;
        std::cout << "Oportunidade de Investimento Promissora:" << std::endl;
        std::cout << linhas[0] << std::endl;
        std::cout << linhas[indice_aleatorio] << std::endl;
        std::cout << " " << std::endl;
    } else {
        std::cerr << "O arquivo nao contem linhas suficientes para selecionar uma oportunidade promissora" << std::endl;
    }
}
analise_oportuna::~analise_oportuna() {}
