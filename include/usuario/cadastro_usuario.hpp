#ifndef CADASTRO_USUARIO
#define CADASTRO_USUARIO

#include <iostream>
#include <string>
#include<fstream>


//declaração da classe no cabeçalho
class Usuario{
public:
// aqui declarei as variaveis como como sendo referenciada, dessa forma quando o usuario entrar com os dados de cadastro irá atribuir para o constructor da classe
    Usuario(const std::string& nome, const std::string& sobrenome, const std::string& email, const std::string& senha)
        : nome(nome), sobrenome(sobrenome), email(email), senha(senha) {}
    void cadastrar_usuario();
private:
        std::string nome;
        std::string sobrenome;
        std::string email;
        std::string senha; 
};

#endif //CADASTRO_USUARIO