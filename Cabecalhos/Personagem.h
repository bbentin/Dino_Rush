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
			float Poder;
			bool flag_pulo;
			static const int forca_movimento;
		public:
			void pular();
			void alterar_pulo();
			void mover_direita();
			void mover_esquerda();
			void causa_dano(Personagem* afetado);
			void recebe_dano(int dano);
			virtual void executar();
			


			Personagem(const int i = 0,sf::Vector2f posi = sf::Vector2f(0,0));
			~Personagem();
		};
	
	
	}
}
