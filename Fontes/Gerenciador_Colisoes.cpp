#include "../Cabecalhos/Gerenciador_Colisoes.h"

Gerenciadores::Gerenciador_Colisoes::Gerenciador_Colisoes(){
	LIs.clear();	LOs.clear();	Player1 = nullptr;
	Player2 = nullptr;
}

Gerenciadores::Gerenciador_Colisoes::~Gerenciador_Colisoes(){
	LIs.clear();	LOs.clear();	Player1 = nullptr;	Player2 = nullptr;
}

void Gerenciadores::Gerenciador_Colisoes::addInimigo(Entidades::Personagens::Inimigo* pIni){
	if (pIni != nullptr) {
		LIs.push_back(pIni);
	}
}

void Gerenciadores::Gerenciador_Colisoes::addObstaculo(Entidades::Obstaculos::Obstaculo* pObs){
	if (pObs != nullptr) {
		LOs.push_back(pObs);
	}
}

void Gerenciadores::Gerenciador_Colisoes::setJogadores(Entidades::Personagens::Jogador* pPrim){
	Player1 = pPrim;	Player2 = nullptr;
}

void Gerenciadores::Gerenciador_Colisoes::setJogadores(Entidades::Personagens::Jogador* pPrim, Entidades::Personagens::Jogador* pSegun){
	Player1 = pPrim; Player2 = pSegun;
}

void Gerenciadores::Gerenciador_Colisoes::ajustaPosicao(Entidades::Entidade* intrometida, Entidades::Entidade* limite){
	sf::Vector2f nova_posi(0, 0);
	nova_posi.x = intrometida->getPosicao().x + intrometida->getTamanho().x - limite->getTamanho().x;
	intrometida->setPosi(nova_posi); 
}


void Gerenciadores::Gerenciador_Colisoes::executar() {
	int N_Obs = LOs.size();
	int N_Inim = LIs.size();
	
	if (!Player2) {
		for (int i = 0; i < N_Obs; i++) { //Verificando se o Jogador colide com Obstaculos
			if (Player1->Colisoes(static_cast<Entidades::Entidade*>(LOs[i]))) {
				ajustaPosicao(Player1, static_cast<Entidades::Entidade*>(LOs[i]));
			}
			for (int j = 0; j < N_Inim; j++) {//Verificando se o Jogador colide com Inimigos
				Player1->Colisoes(static_cast<Entidades::Entidade*>(LIs[j]));

				//Implementar colisoes de Inimigos
			}
		}
	}
	else {
		for (int i = 0; i < N_Obs; i++) {
			if (Player1->Colisoes(static_cast<Entidades::Entidade*>(LOs[i]))) {
				ajustaPosicao(Player1, static_cast<Entidades::Entidade*>(LOs[i]));
			}
			if (Player2->Colisoes(static_cast<Entidades::Entidade*>(LOs[i]))) {
				ajustaPosicao(Player2, static_cast<Entidades::Entidade*>(LIs[i]));
			}
				for (int j = 0; j < N_Inim; j++) {
					if (Player1->Colisoes(static_cast<Entidades::Entidade*>(LIs[i]))) {
						ajustaPosicao(Player1, static_cast<Entidades::Entidade*>(LIs[i]));
					} // Fazendo colisões de Jogadores e Inimigos
					if (Player2->Colisoes(static_cast<Entidades::Entidade*>(LIs[i]))) {
						ajustaPosicao(Player2, static_cast<Entidades::Entidade*>(LIs[i]));
					}
				//Implementar colisoes de Inimigos
				}
		}
	}
}