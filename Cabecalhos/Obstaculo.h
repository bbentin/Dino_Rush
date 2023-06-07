#pragma once
#include "../Cabecalhos/Entidade.h"

namespace Entidades {
	namespace Obstaculos {
		class Obstaculo :
			public Entidade {
		private:

		public:
			Obstaculo(const int i = 0);
			~Obstaculo();

			void Inicializa();
			void executar();
		};
	}
}