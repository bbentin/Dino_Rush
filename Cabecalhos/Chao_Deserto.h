#pragma once
#include "Obstaculo.h"
namespace Entidades {
    namespace Obstaculos {
        class Chao_Deserto :
            public Obstaculo {
        private:
            const int limite_altura;
        public:
            Chao_Deserto(const int limite_alt);
            ~Chao_Deserto();

            void executar();
            void Colisao(Entidade* colidida, sf::Vector2f limites);
            void obstacular(Entidade* obstaculada);
            
        };
    }
}