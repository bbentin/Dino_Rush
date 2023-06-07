#pragma once
#include "Inimigo.h"
namespace Entidades {
    namespace Personagens {
        class Chefao :
            public Inimigo {
        private:
        public:
            Chefao();
            ~Chefao();

            void executar();
            void padrao_acao();
            void Colisao(Entidade* colidida, sf::Vector2f limites);
        };
    }
}