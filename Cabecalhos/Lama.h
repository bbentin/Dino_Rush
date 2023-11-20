#include "Obstaculo.h"

namespace Entidades {
	namespace Obstaculos {
		class Lama :
			public Obstaculo {
		private:
			const int viscosidade;
		public:
			Lama(const float limite = 870);
			~Lama();
			void executar();
			void Colisao(Entidade* colidida, sf::Vector2f limites);
			void obstacular(Entidade* obstaculada);
			void salvar();
		};
	}
}