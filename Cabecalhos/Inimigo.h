#pragma once
#include "Personagem.h"
namespace Entidades {
	namespace Personagens {
		class Inimigo:public Personagem {

		protected:
			int dano; //dano causado ao contato
			virtual void padrao_acao() = 0; //fun��o abstrata para padr�o de a��o
		public:

			Inimigo(const int i = 0, sf::Vector2f posi = sf::Vector2f(0,0));
			~Inimigo();

			virtual void executar();
			virtual void danar(Entidade* Afetada) = 0;
		};
	}
}

