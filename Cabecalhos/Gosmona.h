#pragma once
#include "Inimigo.h"
#include "Projetil.h"
namespace Entidades {
    namespace Personagens {
        class Gosmona :
            public Inimigo {
        private:
            Projetil meleca;
        public:
            Gosmona();
            ~Gosmona();

            void executar();
            void padrao_acao();
            void atirar();
            void Colisao(Entidade* colidida, sf::Vector2f limites);
        };
    }
}

