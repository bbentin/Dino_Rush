#pragma once
#include "../Cabecalhos/Entidade.h"

namespace Entidades {
	class Projetil :public Entidade {
	private:
		int dano;
	public:
		Projetil();
		~Projetil();

		void reseta_posicao();
		void Colisao(Entidade* colidida, sf::Vector2f limites);
	};
}
