#pragma once
#include "Obstaculo.h"
namespace Entidades {
    namespace Obstaculos {
        class Chao_Deserto :
            public Obstaculo {
        private:
        public:
            Chao_Deserto(const float limite_alt = 0);
            ~Chao_Deserto();

            void executar();
            void Colisao(Entidade* colidida, sf::Vector2f limites);
            void obstacular(Entidade* obstaculada);
            void salvar();
        };
    }
}