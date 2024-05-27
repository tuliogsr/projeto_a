
#include "Catalogo.hpp"
#include "Grafics.hpp"
#include "classes_ativos.hpp"
#include "alertas_preco.hpp"
#include "analise_oportuna.hpp"
#include "cadastro_usuario.hpp"
//#include "login.hpp"
#include <iostream>
#include <string>

int main () {
    bool historia_desejada = true;
  while(historia_desejada){
    std::cout << "Escolha a historia de usuario:" << std::endl;
    std::cout << "1 - Historia 01" << std::endl;
    std::cout << "2 - Historia 02" << std::endl;
    std::cout << "3 - Historia 03" << std::endl;
    std::cout << "4 - Historia 04" << std::endl;
    std::cout << "5 - Historia 05" << std::endl;
    std::cout << "6 - Cadastrar usuario" << std::endl;
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
      case 6:
          cadastrarusuario();
          break;
        // Solicita os dados do usuário
/*        std::string Nome, Sobrenome, Email, Senha;

        std::cout << "Digite o nome: "<<std::endl;
        std::getline(std::cin, Nome);

        std::cout << "Digite o sobrenome: "<<std::endl;
        std::cin >> Sobrenome;
        std::cin.ignore(); // Limpa o buffer de entrada para evitar problemas com a próxima entrada

        std::cout << "Digite o email: "<<std::endl;
        std::getline(std::cin, Email);

        std:: cout << "Digite a senha: "<<std::endl;
        std::getline(std::cin, Senha);

       // Cria um objeto Usuario com os dados fornecidos pelo usuário
        Usuario usuario(Nome, Sobrenome, Email, Senha);

        // Chamando o método para cadastrar o usuário
        usuario.cadastrar_usuario();
       break;
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