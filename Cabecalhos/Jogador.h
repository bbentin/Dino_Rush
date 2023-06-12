#pragma once
#include "Personagem.h"
#include "Obstaculo.h"
#include "Inimigo.h"
#include "Projetil.h"
namespace Entidades {
    namespace Personagens {
        class Jogador :
            public Personagem {
        private:
            int pontos;
            bool andar_direita,andar_esquerda;
            Entidades::Projetil* arma;
        public:
            Jogador(const int i = 1, sf::Vector2f posi = sf::Vector2f(0,0));
            ~Jogador();

          
            void Colisao_Deserto(Entidade* deserto, sf::Vector2f limites);
            void Colisao_Floresta(Entidade* floresta, sf::Vector2f limites);
            void Colisao_Projetil(Entidade* projetil, sf::Vector2f limites);
            void Colisao_Inimigo(Entidade* projetil, sf::Vector2f limites);
            void Colisao_Obstaculo(Entidade* obstaculo, sf::Vector2f limites);

            Entidades::Projetil* getArma() const;

            void setMovimento_direita(bool direita);
            void setMovimento_esquerda(bool esquerda);
            virtual void executar();
            void Colisao(Entidade* colidida, sf::Vector2f limites);
            void atirar();
            static bool Jogador2;
        };
    }
}