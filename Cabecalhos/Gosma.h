#pragma once
#include "Inimigo.h"
namespace Entidades {
    namespace Personagens {
        class Gosma :
            public Inimigo {

        private:

        public:
            Gosma();
            ~Gosma();
            void padrao_acao();
            void executar();
            void Colisao(Entidade* colidida, sf::Vector2f limites);
        };
    }
}