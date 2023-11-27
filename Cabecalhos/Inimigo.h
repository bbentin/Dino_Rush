#pragma once
#include "Personagem.h"
namespace Entidades {
	namespace Personagens {
		class Inimigo:public Personagem {
	
		protected:
			int nivel_maldade;
			virtual void padrao_acao() = 0; //fun��o abstrata para padr�o de a��o
		public:

			Inimigo(const int i = 0, sf::Vector2f posi = sf::Vector2f(0,0));
			~Inimigo();

			virtual void danar(Entidade* Afetada) = 0;
			virtual void executar() = 0;
			virtual void salvar (std::ostringstream* entrada) = 0;
		};
	}
}

