#pragma once
#include "Inimigo.h"
namespace Entidades {
    namespace Personagens {
        class Mosca :
            public Inimigo {
        private:
            bool direita;
            float pos_x_inicial;
            const int sujeira; // desacelera o jogador
        public:
            Mosca(sf::Vector2f pos = sf::Vector2f(0.f, 0.f), float vel = 0.0);
            ~Mosca();

            void inverter();
            void executar();
            void padrao_acao();
            void Colisao(Entidade* colidida, sf::Vector2f limites);
            void danar(Entidade* Afetada);
            void Inicializa();
            void ColisaoChao(Entidade* Chao,sf::Vector2f limites);
            void salvar(std::ostringstream* entrada);
        };
    }
}