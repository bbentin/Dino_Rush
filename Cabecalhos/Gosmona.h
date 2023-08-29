#pragma once
#include "Inimigo.h"
#include "Projetil.h"
namespace Entidades {
    namespace Personagens {
        class Gosmona :
            public Inimigo {
        private:
        public:
            Gosmona();
            ~Gosmona();

            void executar();
            void padrao_acao();
            void Colisao(Entidade* colidida, sf::Vector2f limites);
            void Colisao_Chao(Entidade* Chao, sf::Vector2f limites);
            void danar(Entidade* Afetada);
        };
    }
}

