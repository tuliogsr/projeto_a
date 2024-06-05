#ifndef LOGIN_HPP
#define LOGIN_HPP

#include <iostream>
#include <string>
#include <fstream>

class Login{
private:
    std::string dado_entrada;
    std::string nome_arquivo;
public:
    Login(const std::string& dado_entrada, const std::string& nome_arquivo);
    bool verificacao_de_dados();  
};

#endif