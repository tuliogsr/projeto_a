#include "alertas_preco.hpp"
#include "cadastro_usuario.hpp"
#include <fstream>
#include <sstream> // Adicionado para std::istringstream

alertas_preco::alertas_preco(float preco) : preco(preco) {}

void alertas_preco::alertas(const Usuario& usuario) {

    std::cout << "Verificando investimentos para alertas. Limite de alerta: " << preco << std::endl;

    const std::vector<float>& investimentos = usuario.get_investimentos();
    if (investimentos.empty()) {
        std::cout << "Nenhum investimento encontrado para o usuario." << std::endl;
    } else {
        bool alerta_emitido = false;
    int num_investimento=0;
    for (float investimento : investimentos) {
        num_investimento++;
        if (investimento < preco) {
            std::cout << "Alerta: Investimento "<< num_investimento <<" abaixo do limite de alerta: " << investimento << std::endl;
            alerta_emitido = true;
        }
    }

    if (!alerta_emitido) {
        std::cout << "Todos os investimentos estao acima do limite de alerta." << std::endl;
    }
    }
}

alertas_preco::~alertas_preco() {}

//Era a Historia 4