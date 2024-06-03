#include "alertas_preco.hpp"
#include "cadastro_usuario.hpp"
#include <fstream>

alertas_preco::alertas_preco(float preco) : preco(preco){}

void alertas_preco::alertas(const Usuario& usuario) {
  std::cout << "-----------//-----------" << std::endl;
  std::cout << "Configurar alertas de preco para ser notificado quando um ativo atingir um determinado valor" << std::endl;
  std::cout << "-----------//-----------" << std::endl;

  bool alerta_emitido = false;

    for (float investimento : usuario.get_investimentos()) {
        if (investimento < preco) {
            std::cout << "Alerta: Investimento abaixo do limite de alerta: " << investimento << std::endl;
            alerta_emitido = true;
        }
    }

    if (!alerta_emitido) {
        std::cout << "Todos os investimentos estao acima do limite de alerta." << std::endl;
    }
}
alertas_preco::~alertas_preco(){}



//Era a Historia 4