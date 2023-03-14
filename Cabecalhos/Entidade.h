#pragma once
#include "Ente.h"
namespace Entidades {


	class Entidade :
		public Ente {
	protected:
		sf::Vector2i posicao;

	public:
		Entidade();
		Entidade(sf::Vector2i posi);
		~Entidade();

		virtual void executar() = 0;
	};


	}