#pragma once
#include "Inimigo.h"
namespace Entidades {
    namespace Personagens {
        class Gosma :
            public Inimigo {

        private:
           const int tempo_pulo;
           int tempo;
        public:
            Gosma();
            ~Gosma();
            void padrao_acao();
            void executar();
            void Colisao(Entidade* colidida, sf::Vector2f limites);
            void Colisao_Chao(Entidade* Chao);
            void Colisao_Jogador(Entidade* Jogador);
            void danar(Entidade* afetada);
        };
    }
}