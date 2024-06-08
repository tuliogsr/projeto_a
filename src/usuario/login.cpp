#include "login.hpp"
#include <iostream>
#include <fstream>
#include <sstream>
//construtor
Login::Login(const std::string& email, const std::string& senha, const std::string& nome_arquivo)
        : email(email), senha(senha), nome_arquivo(nome_arquivo) {}

bool Login::verificacao_de_dados() {
    std::ifstream arquivo(nome_arquivo);
    if (!arquivo) {// Verifica se o arquivo foi aberto
        std::cerr << "Erro ao abrir o arquivo: " << nome_arquivo << std::endl;
        return false;
    }

    std::string linha;
    while (std::getline(arquivo, linha)) {//conferindo as informação de login do usuario linha por linha
        std::istringstream iss(linha);
        std::string nome_arquivo, sobrenome_arquivo, email_arquivo, senha_arquivo;
        if (!(iss >> nome_arquivo >> sobrenome_arquivo >> email_arquivo >> senha_arquivo)) {
            std::cerr << "Erro ao ler linha do arquivo" << std::endl; //depuração
            return false;
        }
        if (email_arquivo == email && senha_arquivo == senha) {
            return true;
        }
    }
    std::cout << "Login falhou para o email: " << email << std::endl;
    return false;
}