#include "classes_ativos.hpp"

Ativo::Ativo(const std::string& nome, double valor) : nome(nome), valor(valor) {
}

Ativo::~Ativo() {
}

std::string Ativo::getNome() const {
    return nome;
}

double Ativo::getValor() const {
    return valor;
}

void Ativo::setNome(const std::string& nome) {
    this->nome = nome;
}

void Ativo::setValor(double valor) {
    this->valor = valor;
}

void Ativo::info() const {
    std::cout << "Ativo: " << nome << std::endl;
}

CDI::CDI(const std::string& nome, double valor, int quantidade) : Ativo(nome, valor), quantidade(quantidade) {
}

CDI::~CDI() {
}

int CDI::getQuantidade() const {
    return quantidade;
}

void CDI::setQuantidade(int quantidade) {
    this->quantidade = quantidade;
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
