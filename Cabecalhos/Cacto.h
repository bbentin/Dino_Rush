#pragma once
#include "Obstaculo.h"

namespace Entidades {
    namespace Obstaculos {
        class Cacto :
            public Obstaculo {
        private:
        public:
            Cacto();
            ~Cacto();

            void executar();
            void Colisao(Entidade* colidida,sf::Vector2f limites);
            void obstacular(Entidade* obstaculada);
            
        };
    }
}