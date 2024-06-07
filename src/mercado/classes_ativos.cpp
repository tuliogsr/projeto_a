#include "classes_ativos.hpp"
#include <iostream>

Ativo::Ativo(const std::string& nome, double valor) : nome(nome), valor(valor) {
}
Ativo::~Ativo() {
}
void Ativo::info() const {
    std::cout << "Ativo: " << nome << std::endl;
}
CDI::CDI(const std::string& nome, double valor, int quantidade) : Ativo(nome, valor), quantidade(quantidade) {
}
CDI::~CDI() {
}
void CDI::info() const {
    std::cout << "Ativo: " << nome << ", Quantidade: " << quantidade << std::endl;
}
void classes_ativos() {
    std::cout << "Bancos que trabalham com CDI:" << std::endl;
    std::cout << "Mercado Pago" << std::endl;
    std::cout << "Neon" << std::endl;
    std::cout << "C6 Bank" << std::endl;
}
