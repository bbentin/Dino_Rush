#pragma once
#include "Lista.h"
#include "Personagem.h"

namespace Listas {
	class ListaEntidades {
	private:
		Lista<Entidades::Entidade> LEs;
	public:

		ListaEntidades();
		~ListaEntidades();

		bool InserirEntidade(Entidades::Entidade* inserida);
		bool RemoverEntidade(Entidades::Entidade* removida);
		void executar_entidades();
		void executar();
		void Inicializar();
		void salvar(std::ostringstream* entrada);
	};
}


