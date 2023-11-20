#pragma once
#include "Obstaculo.h"
#include "Personagem.h"
namespace Entidades {
    namespace Obstaculos {
        class Espinhos :
            public Obstaculo {
        private:
            const int dano;
            bool visivel;
            sf::Clock relogio;
        public:
            Espinhos(const float limite_alt = 860);
            ~Espinhos();

            void Inicializa();
            void executar();
            void Colisao(Entidade* colidida, sf::Vector2f limites);
            void obstacular(Entidade* obstaculada);
            void salvar();
            void brotar();
            const bool getVisivel() const;
        };
    }
}
