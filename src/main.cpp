#include "Catalogo.hpp"
#include "Grafics.hpp"
#include "classes_ativos.hpp"
#include "alertas_preco.hpp"
#include "analise_oportuna.hpp"
#include "cadastro_usuario.hpp"
#include "login.hpp"
#include "carregar_usuario.hpp"
#include <iostream>
#include <string>
#include <vector>
#include <sstream>

int main () {
    float alertinha = 0;
    std::string email_de_entrada;
    std::string senha_de_entrada;
    std::string opcao_de_cadastro;
    std::string nome_cadastro;
    std::string sobrenome_cadastro;
    std::string email_cadastro;
    std::string senha_cadastro;
    bool login_sucesso = false;
    Usuario usuario_logado("", "", "", "", {});

    // Adiciona um loop de repetição que vai verificar o e-mail e senha e dar a opção de cadastro para o cliente
    do {
        std::cout << "------ Login ------" << std::endl;
        std::cout << " " << std::endl;
        std::cout << "Email: ";
        std::getline(std::cin, email_de_entrada);
        std::cout << "Senha: "; 
        std::getline(std::cin, senha_de_entrada);
        std::cout << " " << std::endl;

        // Objeto para verificar o e-mail e senha no login
        Login login(email_de_entrada, senha_de_entrada, "usuarios.txt");

        if (login.verificacao_de_dados()) {
            login_sucesso = true;
            //utilizei try e catch, para capturar exceções que conversão de strings para números podem causar e lidar com elas de forma apropriada.
            try {
                usuario_logado = carregar_usuario(email_de_entrada, "usuarios.txt");
            } catch (const std::exception& e) {
                std::cerr << e.what() << std::endl;
                return 1;
            }
        } else {
            std::cout << " " << std::endl;
            std::cout << "Email ou senha incorretos" << std::endl;
            std::cout << " " << std::endl;
            std::cout << "Deseja cadastrar um novo usuario? (sim/nao - ou aperte qualquer tecla para sair do programa) " << std::endl;
            std::getline(std::cin, opcao_de_cadastro);
            if (opcao_de_cadastro != "sim" && opcao_de_cadastro != "nao") {
                std::cout << "Opcao invalida, encerrando o programa!!" << std::endl;
                return 0;
            } else if (opcao_de_cadastro == "sim") {
                std::cout << "---- Cadastro de usuario ----" << std::endl;
                std::cout << " " << std::endl;
                std::cout << "Nome: ";
                std::getline(std::cin, nome_cadastro);
                std::cout << "Sobrenome: ";
                std::getline(std::cin, sobrenome_cadastro);
                std::cout << "E-mail: ";
                std::getline(std::cin, email_cadastro);
                std::cout << "Senha: ";
                std::getline(std::cin, senha_cadastro);
                std::cout << " " << std::endl;
                std::vector<float> investimentos_cadastro;
                std::string input;
                std::cout << "Investimentos (digite 'fim' para encerrar): ";
                while (true) {
                    std::cin >> input;
                    if (input == "fim") {
                        break;
                    }
                    try { //utilizei try e catch, para capturar exceções que conversão de strings para números podem causar e lidar com elas de forma apropriada.
                        float investimento = std::stof(input); // Converte a string para float
                        investimentos_cadastro.push_back(investimento);
                    } catch (const std::invalid_argument& e) {
                        std::cout << "Entrada invalida. Por favor, insira um numero ou 'fim' para encerrar." << std::endl;
                    }
                }
                std::cin.ignore(); // Limpa o buffer de entrada
                Usuario usuario(nome_cadastro, sobrenome_cadastro, email_cadastro, senha_cadastro, investimentos_cadastro);
                usuario.cadastrar_usuario();
            }
        }
    } while (!login_sucesso);

    std::cout << "Login bem-sucedido" << std::endl;

    bool historia_desejada = true;
    while (historia_desejada) {
        std::cout << "Escolha a historia de usuario:" << std::endl;
        std::cout << "1 - Catalogo de diferentes tipos de investimento" << std::endl;
        std::cout << "2 - Graficos dos investimentos feitos pelo usuario nos ultimos meses" << std::endl;
        std::cout << "3 - Ver exemplos de bancos que trabalham com CDI" << std::endl;
        std::cout << "4 - Configurar alertas de preco para ser notificado quando um ativo atingir um determinado valor" << std::endl;
        std::cout << "5 - Recomendacao de oportunidades de investimento promissoras." << std::endl;
        std::cout << "6 - Adicionar novos investimentos." << std::endl;
        std::cout << "0 - Para sair do programa" << std::endl;

        int escolha;
        std::cin >> escolha;

        switch (escolha) {
            case 1: {
                menu_major(); // Historia 01
                break;
            }
            case 2: {
                std::cout << " " << std::endl;
                Grafics grafic;
                grafic.grafico(usuario_logado); 
                std::cout << " " << std::endl;// Historia 02
                break;
            }
            case 3:{
                std::cout << " " << std::endl;
                Ativo* ativo = new  CDI("usuario", 100.0, 1);
                ativo->info();// Historia 03
                break;
            }
            case 4: {
                std::cout << " " << std::endl;
                std::cout << "Digite o limite de alerta que voce deseja: " << std::endl;
                std::cin >> alertinha;
                alertas_preco Alertas(alertinha, usuario_logado);
                Alertas.alertas(); // Historia 04
                break;
            }
            case 5: {
                std::cout << " " << std::endl;
                std::cout << "Escolha o tipo de investimento que voce gostaria de saber alguma oportunidade promissora:" << std::endl;
                std::cout << "1 - Renda Fixa" << std::endl;
                std::cout << "2 - Acoes" << std::endl;
                int tipo_investimento;
                std::cin >> tipo_investimento;
                analise_oportuna analise;
                if (tipo_investimento == 1) {
                    analise.imprimir_oportunidade_recomendada("RecomendaRenFix.txt"); 
                } else if (tipo_investimento == 2) {
                    analise.imprimir_oportunidade_recomendada("RecomendaAcoVar.txt");
                } else {
                    std::cout << "Opcao invalida" << std::endl;
                }// Historia 05
                std::cout << " " << std::endl;
                break;
            }
            case 6: {
                float novo_investimento;
                std::cout << "Digite o valor do novo investimento: ";
                std::cin >> novo_investimento;
                usuario_logado.adicionar_investimento(novo_investimento);
            }
            case 0: {
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
