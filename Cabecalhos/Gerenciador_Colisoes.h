#pragma once
#include <vector>
#include <list>
#include "Inimigo.h"
#include "Obstaculo.h"
#include "Jogador.h"
#include "ListaEntidades.h"
#include "Projetil.h"
using namespace std;
namespace Gerenciadores {
	class Gerenciador_Colisoes {
	private:
		vector<Entidades::Entidade*> LPersonagens;
		vector<Entidades::Obstaculos::Obstaculo*> LOs;
	public:
		Gerenciador_Colisoes();
		~Gerenciador_Colisoes();

		void addInimigo(Entidades::Personagens::Inimigo* pIni);
		void addJogador(Entidades::Personagens::Jogador* pJog);
		void addProjetil(Entidades::Projetil* pArma);
		void addObstaculo(Entidades::Obstaculos::Obstaculo* pObs);
		void VerificarMortos();
		void executar();
	};
}

