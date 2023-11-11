#pragma once
#include "Inimigo.h"
namespace Entidades {
    namespace Personagens {
        class Mosca :
            public Inimigo {
        private:
            bool direita;
            float pos_x_inicial;
        public:
            Mosca();
            ~Mosca();

            void inverter();
            void executar();
            void padrao_acao();
            void Colisao(Entidade* colidida, sf::Vector2f limites);
            void danar(Entidade* Afetada);
            void Inicializa();
            void ColisaoChao(Entidade* Chao,sf::Vector2f limites);
            void salvar();
        };
    }
}