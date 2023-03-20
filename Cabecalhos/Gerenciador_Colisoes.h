#pragma once
#include <vector>
#include <list>
#include "Obstaculo.h"
#include "Inimigo.h"

namespace Gerenciadores {
	class Gerenciador_Colisoes {
	private:
		vector<Entidades::Obstaculos::Obstaculo*> Vector_Obstaculos;
		list<Entidades::Personagens::Inimigo*>    Lista_Inimigos;
	public:

		Gerenciador_Colisoes();
		~Gerenciador_Colisoes();
	
	};
}

