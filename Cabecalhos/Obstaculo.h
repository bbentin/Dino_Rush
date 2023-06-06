#pragma once
#include "Entidade.h"

namespace Entidades {
	namespace Obstaculos {
		class Obstaculo :
			public Entidade {

		public:
			Obstaculo(const int i = 0);
			~Obstaculo();

			void executar();
		};
	}
}