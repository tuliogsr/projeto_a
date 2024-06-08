#include "Grafics.hpp"
#include "cadastro_usuario.hpp"

Grafics::Grafics() {}

// Método que gera um gráfico dos últimos investimentos do usuário
void Grafics::grafico(const Usuario &usuario)
{
  std::cout << " " << std::endl;

  std::cout << "Grafico dos ultimos investimentos do usuario:" << std::endl;

  // Obtém os investimentos do usuário
  const std::vector<float> &investimentos = usuario.get_investimentos();

  std::cout << "Investimentos carregados para o usuario" << ": " << std::endl;

  std::cout << "      |" << std::endl;

  int num_aleatorio = 0;

  // Loop para percorrer todos os investimentos
  for (float inv : investimentos)
  {
    num_aleatorio++;

    std::cout << "mes " << num_aleatorio << ":|     " << inv << " ";

    // Calcula o número de símbolos para imprimir
    int numSimbolos = (int)(inv / 10);
    if (inv > 1000)
    {
      numSimbolos = (int)(inv / 100);
    }

    // Imprime os símbolos
    for (int i = 0; i < numSimbolos; ++i)
    {
      if (inv > 1000)
      {
        std::cout << "H";
      }
      else
      {
        std::cout << "#";
      }
    }

    std::cout << std::endl;
    std::cout << "      |" << std::endl;
  }

  std::cout << std::endl;
}

// Destrutor da classe Grafics
Grafics::~Grafics() {}

// Era a Hitoria 2