#pragma once
#include "Inimigo.h"
namespace Entidades {
    namespace Personagens {
        class Decapitado :
            public Inimigo {
        private:

        public:
            Decapitado();
            ~Decapitado();

            void executar();
            void padrao_acao();
            void Colisao(Entidade* colidida, sf::Vector2f limites);
            void danar(Entidade* Afetada);
            void salvar();
        };
    }
}