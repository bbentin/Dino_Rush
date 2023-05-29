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
		vector<Entidades::Personagens::Inimigo*> LIs;
		vector<Entidades::Obstaculos::Obstaculo*> LOs;
		Entidades::Personagens::Jogador* Player1;
		Entidades::Personagens::Jogador* Player2;
	public:
		Gerenciador_Colisoes();
		~Gerenciador_Colisoes();

		void addInimigo(Entidades::Personagens::Inimigo* pIni);
		void addObstaculo(Entidades::Obstaculos::Obstaculo* pObs);
		void setJogadores(Entidades::Personagens::Jogador* pPrim);
		void setJogadores(Entidades::Personagens::Jogador* pPrim, Entidades::Personagens::Jogador* pSegun);
		void ajustaPosicao(Entidades::Entidade* intrometida, Entidades::Entidade* limite); //Impede que os objetos atravessem os outros
		void executar();
	};
}

