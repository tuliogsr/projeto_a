#include "Grafics.hpp"
#include "cadastro_usuario.hpp"

Grafics::Grafics() {}

void Grafics::grafico(const Usuario &usuario)
{
  std::cout << "Grafico dos ultimos investimentos do usuario:" << std::endl;
  const std::vector<float> &investimentos = usuario.get_investimentos();
  std::cout << "Investimentos carregados para o usuario" << ": ";
  int num_aleatorio = 0;
  for (float inv : investimentos)
  {
    num_aleatorio++;
    std::cout <<"mes "<< num_aleatorio << ": " << inv << " ";
  }
  std::cout << std::endl;
}
Grafics::~Grafics() {}
// Era a Hitoria 2