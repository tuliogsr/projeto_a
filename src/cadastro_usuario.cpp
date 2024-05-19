#include "cadastro_usuario.hpp"
#include <fstream> //trabalhar com arquivos
#include <iostream>

void cadastrarusuario(){
    std::cout << "Cadastrar Usuario" << std::endl;
}
/*
//Definindo o constructor
Usuario::usuario(std::string nome, std::string sobrenome, std::string email, std::string senha){
//        void cadastrar_usuario(){
            this -> nome = nome;
            this -> sobrenome = sobrenome;
            this -> email = email;
            this -> senha = senha;
}
    //Implementação do método de cadastro de usuário:
    void Usuario::Cadastrar_usuario(){
        std::ofstream arquivo("usuarios.txt", std::ios_base::app);
    if (arquivo.is_open()) {
        // Escreve os dados do usuário no arquivo
        arquivo << "Nome: " << nome << ", Idade: " << sobrenome << ", Email: " << email << " Senha: "<< senha std::endl;
        std::cout << "Usuário cadastrado com sucesso !!" << std::endl;
        arquivo.close(); // Fecha o arquivo
    } else {
        std::cerr << "Erro ao abrir o arquivo usuarios.txt!" << std::endl;
    }
}*/