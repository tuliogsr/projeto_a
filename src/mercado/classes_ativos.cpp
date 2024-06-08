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
void CDI::info() const {
    std::cout << "Bancos que trabalham com CDI:" << std::endl;
    std::cout << " " << std::endl;
    std::cout << "Mercado Pago" << std::endl;
    std::cout << "Neon" << std::endl;
    std::cout << "Banco do Brasil" << std::endl;
    std::cout << "Caixa Economica Federal" << std::endl;
    std::cout << "Banco Bradesco" << std::endl;
    std::cout << "Banco Itau" << std::endl;
    std::cout << "Banco Santander" << std::endl;
    std::cout << "Banco Safra" << std::endl;
    std::cout << "Banco Inter" << std::endl;
    std::cout << "C6 Bank" << std::endl;
    std::cout << " " << std::endl;
}
CDI::~CDI() {
}
