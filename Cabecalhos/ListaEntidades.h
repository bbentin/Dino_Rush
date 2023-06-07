#pragma once
#include "Lista.h"
#include "Entidade.h"

namespace Listas {
	class ListaEntidades {
	private:
		Lista<Entidades::Entidade> LEs;
	public:

		ListaEntidades();
		~ListaEntidades();

		bool InserirEntidade(Entidades::Entidade* inserida);
		bool RemoverEntidade(Entidades::Entidade* removida);
		void executar();
		void Inicializar();
	};
}


