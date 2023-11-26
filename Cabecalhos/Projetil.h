#pragma once
#include "Personagem.h"

namespace Entidades {
	class Projetil :public Entidade {
	private:
		bool visivel;
		bool pontua;
		Entidade* dono;
	public:
		Projetil(sf::Vector2f pos = sf::Vector2f(0.0f, 0.0f), Entidade* Dono = nullptr, float vel = 0.0f, bool visi = false);
		~Projetil();

		void reseta_posicao();
		void Colisao(Entidade* colidida, sf::Vector2f limites);
		void ColisaoPersonagem(Entidade* colidida);
		void ColisaoObstaculo(Entidade* colidida);
		void executar();
		void atirada();
		void avanca();
		void salvar(std::ostringstream* entrada);
		void setDono(Entidade* Dono);
		const bool getPontos();

		bool GetVisibilidade() const;
	};
}