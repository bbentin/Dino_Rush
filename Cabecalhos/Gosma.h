#pragma once
#include "Inimigo.h"
namespace Entidades {
    namespace Personagens {
        class Gosma :
            public Inimigo {

        private:                 
        public:
            Gosma();
            ~Gosma();
            void padrao_acao();
            void executar();
            void Colisao(Entidade* colidida, sf::Vector2f limites);
            void Colisao_Chao(Entidade* Chao,sf::Vector2f limites);
            void Colisao_Jogador(Entidade* Jogador,sf::Vector2f limites);
            void danar(Entidade* afetada);
            void salvar();
        };
    }
}