#include "Obstaculo.h"

namespace Entidades {
	namespace Obstaculos {
		class Lama :
			public Obstaculo {
		private:
			int atrasar;
		public:
			Lama();
			~Lama();
			void desacelerar();
			void executar();
			void Colisao(Entidade* colidida, sf::Vector2f limites);
			void obstacular(Entidade* obstaculada);
		};
	}
}