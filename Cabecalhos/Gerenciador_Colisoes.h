#pragma once
#include <vector>
#include <list>
#include "Inimigo.h"
#include "Obstaculo.h"
#include "Jogador.h"
#include "ListaEntidades.h"
using namespace std;
namespace Gerenciadores {
	class Gerenciador_Colisoes {
	private:
		vector<Entidades::Personagens::Personagem*> LPersonagens;
		vector<Entidades::Obstaculos::Obstaculo*> LOs;
	public:
		Gerenciador_Colisoes();
		~Gerenciador_Colisoes();

		void addInimigo(Entidades::Personagens::Inimigo* pIni);
		void addJogador(Entidades::Personagens::Jogador* pJog);
		void addObstaculo(Entidades::Obstaculos::Obstaculo* pObs);
		//void ajustaPosicao(Entidades::Entidade* intrometida, Entidades::Entidade*  invadida, sf::Vector2f limites);
		void executar();
	};
}

