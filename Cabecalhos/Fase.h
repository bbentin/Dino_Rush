#pragma once
#include "Ente.h"
#include "Gerenciador_Colisoes.h"
#include "ListaEntidades.h"
#include <fstream>
#include "Lama.h"
#include "Chao_Deserto.h"
#include "Chao_Floresta.h"
#include "Estado.h"

using namespace Entidades;
using namespace Personagens;
using namespace Obstaculos;
using namespace Estados;

namespace Fases {
	class Fase :
		public Ente, public Estado {
	protected:
		sf::Clock relogio_global;
		Gerenciadores::Gerenciador_Colisoes G_Colisoes;
		Listas::ListaEntidades LEs;
		Entidades::Personagens::Jogador* Player1;
		Entidades::Personagens::Jogador* Player2;
		const int k_fase, altura_spawn_inimigos, altura_spawn_obstaculos;
		int num_inimigos;
		bool ativa, final;
	public:

		Fase(const int i = 0, const int k = 0, int estado = -1);
		virtual ~Fase();

		sf::Clock* getRelogio();
		virtual void executar() = 0;
		void gerenciar_colisoes();
		void setJogador(Entidades::Personagens::Jogador* inserido);
		void gerar_fase(int fase);
		void CriarEntidades(char leitura, sf::Vector2f pos);
		void CriarChao(int i, sf::Vector2f pos);
		void VerificaMortos();
		bool verificaFinal();
		bool getAtiva();
		virtual void Inicializa();
	};
}
