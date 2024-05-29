
#include "Catalogo.hpp"
#include "Grafics.hpp"
#include "classes_ativos.hpp"
#include "alertas_preco.hpp"
#include "analise_oportuna.hpp"
#include "cadastro_usuario.hpp"
//#include "login.hpp"
#include <iostream>
#include <string>
bool verificacao_de_dados(const std::string& dado_entrada, const std::string& nome_arquivo ){
    std::ifstream arquivo(nome_arquivo);// criando um objeto para o arquivo que será usado para verificar os dados
    if (!arquivo) { // Verifica se o arquivo foi aberto
      std::cerr << "Erro ao abrir o arquivo: " << nome_arquivo << std::endl;
      return false;
    }
    std::string linha;
    while (std::getline(arquivo, linha)){
      if (linha.find(dado_entrada) != std::string::npos)
      {
        return true;
      }
      return false;
    }
}

int main () {
  std::string email_de_entrada;
  std::string senha_de_entrada;
  std::string opcao_de_cadastro;
  std::string nome_cadastro ;
  std::string sobrenome_cadastro;
  std::string email_cadastro;
  std::string senha_cadastro;

  bool historia_desejada = true;
  //aqui foi adicionado um loop de repetição que vai verificar o e-mail e senha e dar a opção de cadastro patra o cliente
  do
  {
    std::cout << "------ Login ------" << std::endl;
    std::cout << " " << std::endl;
    std::cout << "Email: ";
    std::getline(std::cin, email_de_entrada);
    std::cout << "Senha: "; 
    std::getline(std::cin, senha_de_entrada);
    std::cout << " " << std::endl;
    if (verificacao_de_dados(email_de_entrada) = 0 || verificacao_de_dados(senha_de_entrada) = 0)
    {
      std::cout << " " << std::endl;
      std::cout << " Email ou senha incorretos " << std::endl;
      std::cout << " " << std::endl;
      std::cout << "Deseja cadastrar um novo usuario? " << std::endl;
      std::getline(std::cin, opcao_de_cadastro);
      if (opcao_de_cadastro == "sim")
      {
        std::cout << " ---- Cadastro de usuario ----" << std::endl;
        std::cout << " " << std::endl;
        std::cout << "Nome: ";
        std::getline(std::cin,nome_cadastro);
        std::cout << "Sobrenome: ";
        std::getline(std::cin,sobrenome_cadastro);
        std::cout << "E-mail: ";
        std::getline(std::cin,email_cadastro);
        std::cout << "Senha:  ";
        std::getline(std::cin,senha_cadastro);

        Usuario usuario(nome_cadastro, sobrenome_cadastro, email_cadastro, senha_cadastro);
        usuario.cadastrar_usuario();
      }
      else{
        return 0;
      }
    }
  } while (verificacao_de_dados(email_de_entrada) = 0 || verificacao_de_dados(senha_de_entrada) = 0);
  
  std::cout << "------ Login ------" << std::endl;
  std::cout << " " << std::endl;
  std::cout << "Email: ";
  std::getline(std::cin, email_de_entrada) << std::endl;
  std::cout << "Senha: "; 
  std::getline(std::cin, senha_de_entrada);
  
  while(historia_desejada){
    std::cout << "Escolha a historia de usuario:" << std::endl;
    std::cout << "1 - Historia 01" << std::endl;
    std::cout << "2 - Historia 02" << std::endl;
    std::cout << "3 - Historia 03" << std::endl;
    std::cout << "4 - Historia 04" << std::endl;
    std::cout << "5 - Historia 05" << std::endl;
//    std::cout << "7 - Login" << std::endl;

    int escolha;
    std::cin >> escolha;

    switch (escolha){
      case 1:
        catalogo(); //Historia 01 
        break;
      case 2:
        grafico(); //Historia 02
        break;
      case 3:
        classes_ativos(); //Historia 03
        break;
      case 4: {
      alertas_preco Alertas(100.0);
        Alertas.alertas(); //Historia 04
        break;
      }
      case 5: {
      analise_oportuna Analise(100.0);
        Analise.analise(); //Historia 05
        break;
      }
//        case 7:
//          login_usuario(); 
//          break; */
      case 0:
      {
        historia_desejada = false;
        break;
      }
      default:
        std::cout << "Opcao invalida" << std::endl;
        break;
    }
  }
  return 0;
}