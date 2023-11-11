#pragma once
#include "../Cabecalhos/Entidade.h"

namespace Entidades {
	namespace Obstaculos {
		class Obstaculo :
			public Entidade {
		protected:
			bool danoso;
		public:
			Obstaculo(const int i = 0);
			~Obstaculo();

			void Inicializa();
			virtual void executar() = 0;
			virtual void obstacular(Entidade* obstaculada) = 0;
			virtual void salvar() = 0;
		};
	}
}