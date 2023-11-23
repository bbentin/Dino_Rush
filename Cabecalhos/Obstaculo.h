#pragma once
#include "../Cabecalhos/Entidade.h"

namespace Entidades {
	namespace Obstaculos {
		class Obstaculo :
			public Entidade {
		protected:
			const float limite_altura;
		public:
			Obstaculo(const int i = 0,const float limite = 500);
			~Obstaculo();

			virtual void Inicializa();
			virtual void executar() = 0;
			virtual void obstacular(Entidade* obstaculada) = 0;
			virtual void salvar(std::ostringstream* entrada) = 0;
		};
	}
}