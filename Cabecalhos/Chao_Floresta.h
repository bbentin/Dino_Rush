#pragma once
#include "Obstaculo.h"

namespace Entidades {
    namespace Obstaculos {
        class Chao_Floresta :
            public Obstaculo {
        private:
            const int limite_altura;
        public:
            Chao_Floresta(const int limite_altura);
            ~Chao_Floresta();

            void executar();
            void Colisao(Entidade* colidida, sf::Vector2f limites);
            void obstacular(Entidade* obstaculada);
        };
    }
}