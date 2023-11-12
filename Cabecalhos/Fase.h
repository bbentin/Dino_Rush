#pragma once
#include "Ente.h"
#include "Gerenciador_Colisoes.h"
#include "ListaEntidades.h"
#include <fstream>
#include "Lama.h"
#include "Chao_Deserto.h"
#include "Chao_Floresta.h"

using namespace Entidades;
using namespace Personagens;
using namespace Obstaculos;

namespace Fases{
    class Fase :
        public Ente {
    protected:
        sf::Clock relogio_global;
        Gerenciadores::Gerenciador_Colisoes G_Colisoes;
        Listas::ListaEntidades LEs;
        static Entidades::Personagens::Jogador* Player1;
        static Entidades::Personagens::Jogador* Player2;
        const int k_fase, altura_spawn_inimigos, altura_spawn_obstaculos;
    public:

        Fase(const int i = 0, const int k = 0);
        ~Fase();

        sf::Clock* getRelogio();
        virtual void executar() = 0;
        void gerenciar_colisoes();
        void setJogador(Entidades::Personagens::Jogador* inserido);
        void gerar_fase(int fase);
        void CriarEntidades(char leitura, sf::Vector2f pos);
        void CriarChao(int i, sf::Vector2f pos);
        void VerificaMortos();
        virtual void Inicializa();
    };
}
