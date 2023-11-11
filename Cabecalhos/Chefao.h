#pragma once
#include "Inimigo.h"
#include "Projetil.h"
namespace Entidades {
    namespace Personagens {
        class Chefao :
            public Inimigo {
        private:
            Entidades::Projetil* arma;
        public:
            Chefao();
            ~Chefao();

            void executar();
            void padrao_acao();
            void Colisao(Entidade* colidida, sf::Vector2f limites);
            void danar(Entidade* Afetada);
            void Colisao_Chao(Entidade* colidida, sf::Vector2f limites);
            void setArma(Entidades::Projetil* gun);
            void salvar();
        };
    }
}