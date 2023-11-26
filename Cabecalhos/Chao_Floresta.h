#pragma once
#include "Obstaculo.h"
#include <sstream>

namespace Entidades {
    namespace Obstaculos {
        class Chao_Floresta :
            public Obstaculo {
        private:          
        public:
            Chao_Floresta(const float limite_alt = 0);
            ~Chao_Floresta();

            void executar();
            void Colisao(Entidade* colidida, sf::Vector2f limites);
            void obstacular(Entidade* obstaculada);
            void salvar(std::ostringstream* entrada);
        };
    }
}