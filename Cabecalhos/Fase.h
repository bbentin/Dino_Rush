#pragma once
#include "Ente.h"
#include "Gerenciador_Colisoes.h"
#include "ListaEntidades.h"
#include <fstream>
namespace Fases{
    class Fase :
        public Ente {
    protected:
        sf::Clock relogio_global;
        Gerenciadores::Gerenciador_Colisoes G_Colisoes;
        Listas::ListaEntidades LEs;
        Entidades::Personagens::Jogador* Primeiro;
        Entidades::Personagens::Jogador* Segundo;
    public:

        Fase(const int i = 0);
        ~Fase();

        sf::Clock* getRelogio();
        virtual void executar() = 0;
        void gerenciar_colisoes();
        void setJogador(Entidades::Personagens::Jogador* inserido);
        void gerar_fase(int fase);
    };
}
