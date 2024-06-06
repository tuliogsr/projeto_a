#ifndef LOGIN_HPP
#define LOGIN_HPP

#include <iostream>
#include <string>
#include <fstream>

class Login{
private:
    std::string email;
    std::string senha;
    std::string nome_arquivo;
public:
    Login(const std::string& email, const std::string& senha, const std::string& nome_arquivo);
    bool verificacao_de_dados();  
};

#endif
