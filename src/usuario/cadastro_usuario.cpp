#include "include/usuario/cadastro_usuario.hpp"
#include <fstream> //trabalhar com arquivos
#include <iostream>

    //Implementação do método de cadastro de usuário:
void Usuario::cadastrar_usuario(){
    std::ofstream arquivo("usuarios.txt", std::ios_base::app);
    if (arquivo.is_open()) {
        // Escreve os dados do usuário no arquivo
        arquivo <<" "<< nome <<" "<< sobrenome <<" "<< email << " "<< senha << std::endl;
        std::cout << "Usuário cadastrado com sucesso !!" << std::endl;
        arquivo.close();
    } else {
        std::cerr << "Erro ao abrir o arquivo usuarios.txt!" << std::endl;
    }
}