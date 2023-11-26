#pragma once
#include "Inimigo.h"
#include "Projetil.h"
#include <sstream>
#include <fstream>
#include <iostream>
#include <string>
#include "../json.hpp"
using namespace std;

#define ARQUIVOD "Imagens/Fase/Deserto/entidades.json"

namespace Entidades {
    namespace Personagens {
        class Chefao :
            public Inimigo {
        private:
            Entidades::Projetil* arma;
        public:
            Chefao(sf::Vector2f pos = sf::Vector2f(0.f, 0.f));
            ~Chefao();

            void executar();
            void padrao_acao();
            void Colisao(Entidade* colidida, sf::Vector2f limites);
            void danar(Entidade* Afetada);
            void Colisao_Chao(Entidade* colidida, sf::Vector2f limites);
            void setArma(Entidades::Projetil* gun);
            Entidades::Projetil* getArma() const;
            void criarArma();
            void salvar(std::ostringstream* entrada);
        };
    }
}