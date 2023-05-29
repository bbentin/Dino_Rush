#pragma once
#include "Personagem.h"
namespace Entidades {
    namespace Personagens {
        class Jogador :
            public Personagem {
        private:
            int pontos;
            bool andar_direita,andar_esquerda;
        public:
            Jogador(const int i = 1, sf::Vector2f posi = sf::Vector2f(0,0));
            ~Jogador();

            void Colisao_Inimigo(Entidade* odiada);
            void Colisao_Obstaculo(Entidade* parada);
            void Colisao_Projetil(Entidade* atirada);
            void setMovimento_direita(bool direita);
            void setMovimento_esquerda(bool esquerda);
            virtual void executar();
            bool Colisoes(Entidade* colidida);
            static bool Jogador2;
        };
    }
}