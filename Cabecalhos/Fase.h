#pragma once
#include "Gerenciador_Colisoes.h"
#include "ListaEntidades.h"
#include "Lama.h"
#include "Chao_Deserto.h"
#include "Chao_Floresta.h"
#include "../json.hpp"
#include <fstream>
#include <sstream>
#include <string>
#include <time.h>

#define ARQUIVOF "Imagens/Fase/Floresta/entidades.json"
#define ARQUIVOD "Imagens/Fase/Deserto/entidades.json"

namespace Fases{
    class Fase :
        public Ente {
    protected:
        sf::Clock relogio_global;
        Gerenciadores::Gerenciador_Colisoes G_Colisoes;
        Listas::ListaEntidades LEs;
        Entidades::Personagens::Jogador* Player1;
        Entidades::Personagens::Jogador* Player2;
        const int k_fase, altura_spawn_inimigos, altura_spawn_obstaculos;
        int num_inimigos;
        bool ativa,final,recuperada;
        std::ostringstream buffer;

    public:

        Fase(const int i = 0, const int k = 0);
        virtual ~Fase();

        sf::Clock* getRelogio();
        virtual void executar() = 0;
        void gerenciar_colisoes();
        void setJogador(Entidades::Personagens::Jogador* inserido);
        void gerar_fase(int fase);
        void CriarEntidades(char leitura, sf::Vector2f pos);
        void CriarChao(int i, sf::Vector2f pos);
        void VerificaMortos();
        bool verificaFinal();
        bool getAtiva();
        virtual void Inicializa();
    };
}
