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
		public:
			void pular();
			void alterar_pulo();
			void mover_direita();
			void mover_esquerda();
			void causa_dano(Personagem* afetado);
			void recebe_dano(int dano);
			Personagem();
			~Personagem();
		};
	
	
	}
}
