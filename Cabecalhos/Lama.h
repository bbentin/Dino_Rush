#include "Obstaculo.h"

namespace Entidades {
	namespace Obstaculos {
		class Lama :
			public Obstaculo {
		private:
			const int viscosidade;
			const float limite_altura;
		public:
			Lama();
			~Lama();
			void executar();
			void Colisao(Entidade* colidida, sf::Vector2f limites);
			void obstacular(Entidade* obstaculada);
			void salvar();
		};
	}
}