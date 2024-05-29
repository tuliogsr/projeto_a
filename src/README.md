# Projeto Prático PDSII-TM2
Em primeiro momento, queremos fazer um projeto voltado a parte de investimento, sendo uma plataforma de investimentos em diferentes áreas, com as seguintes funcionalidades:
# Historias de usuário
 - 01: Eu como usuário de uma plataforma de investimento, gostaria de ter acesso a catálogos de diferentes tipos de investimento, para ter uma maior diversificações de meus investimentos;
 - 02: Mário como um investidor experiente, gostaria de ver por meio da plataforma, os graficos dos investimentos feitos por ele nos ultimos anos;
 - 03: Como um investidor experiente, eu quero ter acesso a uma variedade de classes de ativos, em determinada moeda, ações ou etc;
 - 04: Como um investidor conservador, eu quero poder configurar alertas de preço para ser notificado quando um ativo atingir um determinado valor, para que eu possa tomar medidas adequadas.
 - 05: Como um investidor que deseja maximizar retornos, eu quero ter acesso a ferramentas de análise e algoritmos de recomendação para identificar oportunidades de investimento promissoras.

 # Implementação (Yan)
 - O projeto se trata de um sistema de contas onde o usuário deve logar e ter acesso aos dados e funcionalisades que o programa irá fornercer, pensando nisso realizamos a implementação da funcionalidade de login.
    - funções:
        - Cadastrar e-mail e senha;
        - Entrar com e-mail e senha;
        - Os dados cadastrados irão ser armazenados em um arquivo txt;
        - Incluir um menu de login com as opções de inserir os dados para logar ou cadastrar
        - Retirei o "case 6", inclui a funcionalidade de login e cadastro antes de iniciar o programa, para fazer mais sentido
        - Para chamar os arquivos de definição de classe preciso do caminho parecido com este:
            #include "include/usuario/cadastro_usuario.hpp"
        
        

# Site com banco de dados:
link: https://basedosdados.org/dataset?q=investimento

Este site nos dá a base necessária para trabalhar no projeto, com dados validos, mas que não contém informações que possam comprometer alguma pessoa;



