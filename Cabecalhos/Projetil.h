#pragma once
#include "Personagem.h"

namespace Entidades {
	class Projetil :public Entidade {
	private:
		bool visivel;
		bool pontua;
		Entidade* dono;
	public:
		Projetil();
		~Projetil();

		void reseta_posicao();
		void Colisao(Entidade* colidida, sf::Vector2f limites);
		void ColisaoPersonagem(Entidade* colidida);
		void ColisaoObstaculo(Entidade* colidida);
		void executar();
		void atirada();
		void avanca();
		void salvar();
		void setDono(Entidade* Dono);
		const bool getPontos();

		bool GetVisibilidade() const;
	};
}
