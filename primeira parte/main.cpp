
#include "historia1.hpp"
#include <iostream>

int main () {
    bool historia_desejada = true;
  while(historia_desejada){
    std::cout << "Escolha a historia de usuario:" << std::endl;
    std::cout << "1 - Historia 01" << std::endl;
    std::cout << "2 - Historia 02" << std::endl;
    std::cout << "3 - Historia 03" << std::endl;
    std::cout << "4 - Historia 04" << std::endl;
    std::cout << "5 - Historia 05" << std::endl;

    int escolha;
    cin >> escolha;

    switch (historia_desejada){
      case 1:
        (); //Historia 01 
        break;
      case 2:
        (); //Historia 02
        break;
      case 3:
        (); //Historia 03
        break;
      case 4:
        (); //Historia 04
        break;
      case 5:
        (); //Historia 05
        break;
      case 0:
        historia_desejada = false;
        break;
      default:
        std::cout << "Opcao invalida" << std::endl;
        break;
    }
  }
  return 0;
}