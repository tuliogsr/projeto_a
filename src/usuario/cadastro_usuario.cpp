#include "cadastro_usuario.hpp"
#include <fstream> //trabalhar com arquivos
#include <iostream>
#include <sstream>

    //Implementação do método de cadastro de usuário:
void Usuario::cadastrar_usuario(){
    std::ofstream arquivo("usuarios.txt", std::ios_base::app);
    if (arquivo.is_open()) {
        // Escreve os dados do usuário no arquivo
        arquivo <<" "<< nome <<" "<< sobrenome <<" "<< email << " "<< senha << " ";
        for (const auto& investimento : investimentos) {
            arquivo << investimento << " ";
        }
        arquivo << std::endl;
        std::cout << "Usuário cadastrado com sucesso !!" << std::endl;
        arquivo.close();
    } else {
        std::cerr << "Erro ao abrir o arquivo usuarios.txt!" << std::endl;
    }
}
// Implementação do método adicionar_investimento
void Usuario::adicionar_investimento(float novo_investimento) {
    investimentos.push_back(novo_investimento);
    atualizar_arquivo();
}

// Implementação do método privado atualizar_arquivo
// Método privado para atualizar o arquivo usuarios.txt com os dados atualizados do usuário
// Método privado para atualizar o arquivo usuarios.txt com os dados atualizados do usuário
void Usuario::atualizar_arquivo() {
    std::ifstream arquivo_entrada("usuarios.txt");
    if (!arquivo_entrada.is_open()) {
        std::cerr << "Erro ao abrir o arquivo usuarios.txt para leitura!" << std::endl;
        return;
    }

    std::ofstream arquivo_saida("temp.txt");
    if (!arquivo_saida.is_open()) {
        std::cerr << "Erro ao abrir o arquivo temp.txt para escrita!" << std::endl;
        return;
    }

    std::string linha;
    while (std::getline(arquivo_entrada, linha)) {
        std::istringstream iss(linha);
        std::string email_arquivo;
        iss >> email_arquivo;
        if (email_arquivo == email) {
            // Substituir a linha do usuário com os novos investimentos
            arquivo_saida << nome << " " << sobrenome << " " << email << " " << senha << " ";
            for (const auto& investimento : investimentos) {
                arquivo_saida << investimento << " ";
            }
            arquivo_saida << std::endl;
        } else {
            // Escrever a linha original no arquivo temporário
            arquivo_saida << linha << std::endl;
        }
    }

    arquivo_entrada.close();
    arquivo_saida.close();

    // Substituir o arquivo original pelo temporário
    if (std::remove("usuarios.txt") != 0) {
        std::cerr << "Erro ao excluir o arquivo usuarios.txt!" << std::endl;
        return;
    }
    if (std::rename("temp.txt", "usuarios.txt") != 0) {
        std::cerr << "Erro ao renomear o arquivo temp.txt para usuarios.txt!" << std::endl;
        return;
    }
}

