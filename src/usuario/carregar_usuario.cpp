#include "carregar_usuario.hpp"
#include <fstream>
#include <sstream>
#include <stdexcept>

Usuario carregar_usuario(const std::string& email, const std::string& nome_arquivo) {
    std::ifstream arquivo(nome_arquivo);
    if (!arquivo) {
        throw std::runtime_error("Erro ao abrir o arquivo: " + nome_arquivo);
    }
    std::string linha;
    while (std::getline(arquivo, linha)) {
        std::istringstream iss(linha);
        std::string nome, sobrenome, email_arquivo, senha;
        std::vector<float> investimentos;
        iss >> nome >> sobrenome >> email_arquivo >> senha;
        if (email_arquivo == email) {
            float investimento;
            while (iss >> investimento) {
                investimentos.push_back(investimento);
            }
            return Usuario(nome, sobrenome, email_arquivo, senha, investimentos);
        }
    }
    throw std::runtime_error("Usuario nao encontrado: " + email);
}
