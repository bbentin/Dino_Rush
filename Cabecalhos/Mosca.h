#pragma once
#include "Inimigo.h"
namespace Entidades {
    namespace Personagens {
        class Mosca :
            public Inimigo {
        private:

        public:
            Mosca();
            ~Mosca();

            void executar();
            void padrao_acao();
            void Colisao(Entidade* colidida, sf::Vector2f limites);
            void danar(Entidade* Afetada);
        };
    }
}