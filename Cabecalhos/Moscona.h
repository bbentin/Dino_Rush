#pragma once
#include "Inimigo.h"
namespace Entidades {
    namespace Personagens {
        class Moscona :
            public Inimigo {
        private:

        public:
            Moscona();
            ~Moscona();

            void executar();
            void padrao_acao();
            void Colisao(Entidade* colidida, sf::Vector2f limites);
            void danar(Entidade* Afetada);
        };
    }
}