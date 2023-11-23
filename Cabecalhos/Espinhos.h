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
            int tempo;
        public:
            Espinhos(sf::Vector2f pos = sf::Vector2f(0.f, 0.f), int tmp = 0, bool visi = false, const float limite_alt = 860);
            ~Espinhos();

            void Inicializa();
            void executar();
            void Colisao(Entidade* colidida, sf::Vector2f limites);
            void obstacular(Entidade* obstaculada);
            void salvar(std::ostringstream* entrada);
            void brotar();
            const bool getVisivel() const;
        };
    }
}
