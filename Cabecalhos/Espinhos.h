#pragma once
#include "Obstaculo.h"
namespace Entidades {
    namespace Obstaculos {
        class Espinhos :
            public Obstaculo {
        private:

        public:
            Espinhos();
            ~Espinhos();

            void executar();
            void Colisao(Entidade* colidida, sf::Vector2f limites);
        };
    }
}
