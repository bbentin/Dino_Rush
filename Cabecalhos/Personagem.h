#pragma once
#include "Entidade.h"
namespace Entidades {

	namespace Personagens {
	
		class Personagem :
			public Entidade {
		private:
			int Dano;
		protected:
			int num_vidas;
			static const int forca_movimento;
			bool iniciar;
		public:
			void pular();
			void mover_direita();
			void mover_esquerda();
			void causa_dano(Personagem* afetado);
			void recebe_dano(int dano);
			virtual void executar() = 0;

			int getVidas() const;
			void operator--();
			void operator++();
			Personagem(const int i = 0,sf::Vector2f posi = sf::Vector2f(0,0));
			~Personagem();
		};
	
	
	}
}
