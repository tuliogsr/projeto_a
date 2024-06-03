#ifndef CARREGAR_USUARIO_H
#define CARREGAR_USUARIO_H

#include <string>
#include "cadastro_usuario.hpp" // Certifique-se de incluir o cabeçalho da classe Usuario

Usuario carregar_usuario(const std::string& email, const std::string& nome_arquivo);

#endif 
