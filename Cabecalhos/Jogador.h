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
            bool andar_direita,andar_esquerda;
            Entidades::Projetil* arma;
            const static float rapidez;
            static bool Jogador2;

        public:
            Jogador(const int i = 1, sf::Vector2f posi = sf::Vector2f(0,0));
            ~Jogador();
        
            void Colisao_Inimigo(Entidade* projetil, sf::Vector2f limites);
            void Colisao_Obstaculo(Entidade* obstaculo, sf::Vector2f limites);

            Entidades::Projetil* getArma() const;

            void setMovimento_direita(bool direita);
            void setMovimento_esquerda(bool esquerda);
            void executar();
            void Colisao(Entidade* colidida, sf::Vector2f limites);
            void atirar();
            void salvar();
            static const bool getJogador2();
        };
    }
}