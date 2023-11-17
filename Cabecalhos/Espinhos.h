#pragma once
#include "Obstaculo.h"
namespace Entidades {
    namespace Obstaculos {
        class Espinhos :
            public Obstaculo {
        private:
            const int dano;
            bool visivel;
            sf::Clock relogio;
        public:
            Espinhos();
            ~Espinhos();

            void executar();
            void Colisao(Entidade* colidida, sf::Vector2f limites);
            void obstacular(Entidade* obstaculada);
            void salvar();
            void brotar();
        };
    }
}
