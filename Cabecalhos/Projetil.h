#pragma once
#include "../Cabecalhos/Entidade.h"

namespace Entidades {
	class Projetil :public Entidade {
	private:
		int dano;
		bool visivel;
		Entidade* dono;
	public:
		Projetil();
		~Projetil();

		void reseta_posicao();
		void Colisao(Entidade* colidida, sf::Vector2f limites);
		void executar();
		void atirada();
		void setDono(Entidade* Dono);
	};
}
