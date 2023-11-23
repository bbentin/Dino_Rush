#pragma once
#include "Inimigo.h"
namespace Entidades {
    namespace Personagens {
        class Gosma :
            public Inimigo {

        private:             
            int num_pulos; //morre apos ultrapassar o numero de pulos
        public:
            Gosma(sf::Vector2f pos = sf::Vector2f(0.f, 0.f), float vel = 0.0);
            ~Gosma();
            void padrao_acao();
            void executar();
            void Colisao(Entidade* colidida, sf::Vector2f limites);
            void Colisao_Chao(Entidade* Chao,sf::Vector2f limites);
            void Colisao_Jogador(Entidade* Jogador,sf::Vector2f limites);
            void danar(Entidade* afetada);
            void salvar(std::ostringstream* entrada);
            void atualizar();
        };
    }
}