#include "alertas_preco.hpp"
#include "cadastro_usuario.hpp"
#include <fstream>

alertas_preco::alertas_preco(float preco) : preco(preco){}

void alertas_preco::alertas(){
  std::cout << "-----------//-----------" << std::endl;
  std::cout << "Configurar alertas de preco para ser notificado quando um ativo atingir um determinado valor" << std::endl;
  std::cout << "-----------//-----------" << std::endl;
}
alertas_preco::~alertas_preco(){}



//Era a Historia 4