#include "Obstaculo.h"

namespace Entidades {
	namespace Obstaculos {
		class Lama :
			public Obstaculo {
		private:
			const int viscosidade;
		public:
			Lama(sf::Vector2f pos = sf::Vector2f(0.f, 0.f), const float limite = 920);
			~Lama();
			void executar();
			void Colisao(Entidade* colidida, sf::Vector2f limites);
			void obstacular(Entidade* obstaculada);
			void salvar(std::ostringstream* entrada);
		};
	}
}