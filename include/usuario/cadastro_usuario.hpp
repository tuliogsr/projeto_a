#ifndef CADASTRO_USUARIO
#define CADASTRO_USUARIO

#include <iostream>
#include <string>
#include <fstream>
#include <vector>


//declaração da classe no cabeçalho
class Usuario{
public:
// aqui declarei as variaveis como como sendo referenciada, dessa forma quando o usuario entrar com os dados de cadastro irá atribuir para o constructor da classe
    Usuario(const std::string& nome, const std::string& sobrenome, const std::string& email, const std::string& senha, const std::vector<float>& investimentos)
        : nome(nome), sobrenome(sobrenome), email(email), senha(senha), investimentos(investimentos) {}
    void cadastrar_usuario();

    // Método getter para obter os investimentos
    std::vector<float> get_investimentos() const {
        return investimentos;
    }
    //Método para adicionar novos investimentos
    void adicionar_investimento(float novo_investimento);
    void atualizar_arquivo();
private:
        std::string nome;
        std::string sobrenome;
        std::string email;
        std::string senha; 
        std::vector<float> investimentos;
};

#endif //CADASTRO_USUARIO