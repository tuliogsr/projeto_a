#include "login.hpp"
#include <iostream>
#include <fstream>

Login::Login(const std::string& dado_entrada, const std::string& nome_arquivo)
        : dado_entrada(dado_entrada), nome_arquivo(nome_arquivo) {}
bool Login::verificacao_de_dados() {
    std::ifstream arquivo(nome_arquivo);// criando um objeto para o arquivo que será usado para verificar os dados
    if (!arquivo) { // Verifica se o arquivo foi aberto
      std::cerr << "Erro ao abrir o arquivo: " << nome_arquivo << std::endl;
      return false;
    }
    std::string linha;
    while (std::getline(arquivo, linha)){
      if (linha == dado_entrada)      {
        return true;
      }
    }
    return false;
}