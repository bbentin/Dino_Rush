#include "../Cabecalhos/Gerenciador_Colisoes.h"

Gerenciadores::Gerenciador_Colisoes::Gerenciador_Colisoes(){
	LPersonagens.clear();	LOs.clear();
}

Gerenciadores::Gerenciador_Colisoes::~Gerenciador_Colisoes() {
	LPersonagens.clear();	LOs.clear();
}

void Gerenciadores::Gerenciador_Colisoes::addInimigo(Entidades::Personagens::Inimigo* pIni){
	if (pIni != nullptr) {
		LPersonagens.push_back(static_cast<Entidades::Personagens::Personagem*>(pIni));
	}
}

void Gerenciadores::Gerenciador_Colisoes::addJogador(Entidades::Personagens::Jogador* pJog){
	if(pJog != nullptr){
		static_cast<Entidades::Personagens::Personagem*>(pJog);
		LPersonagens.push_back(pJog);
	}
}



void Gerenciadores::Gerenciador_Colisoes::addObstaculo(Entidades::Obstaculos::Obstaculo* pObs){
	if (pObs != nullptr) {
		LOs.push_back(pObs);
	}
}

void Gerenciadores::Gerenciador_Colisoes::ajustaPosicao(Entidades::Entidade* intrometida,Entidades::Entidade* invadida, sf::Vector2f limites){
	sf::Vector2f pos1, pos2, vel_intro;
	vel_intro = intrometida->Get_Velocidade();
	pos1 = intrometida->getPosicao(); pos2 = invadida->getPosicao();

	if (limites.x > limites.y) {
		if (pos2.x < pos1.x) {
			pos1.x -= limites.x;
		}
		else{
			pos1.x += limites.x;
		}
		vel_intro.x = 0;
	}
	else {
		if (pos2.y < pos1.y) {
			pos2.y -= limites.y;
		}
		else {
			pos2.y += limites.y;
		}
		intrometida->setPosi(pos1);
		vel_intro.y = 0;
	}
	intrometida->setVelo(vel_intro);
	intrometida->setPosi(pos1);
}


void Gerenciadores::Gerenciador_Colisoes::executar() {
	int N_Obs = LOs.size();
	int N_Pers = LPersonagens.size();

	for (int i = 0; i < N_Pers - 1; i++) {
		Entidades::Entidade* primeira = LPersonagens[i];
		for (int j = i + 1; j < N_Pers; j++) {
			Entidades::Entidade* segunda = LPersonagens[j];
			sf::Vector2f coli = primeira->Colide(segunda);
			if (coli.x < 0 && coli.y < 0 ) {
				primeira->Colisao(segunda,coli);
			}
		}
		for (int k = 0; k < N_Obs; k++) {
			Entidades::Entidade* segunda = LOs[k];
			sf::Vector2f coli = primeira->Colide(segunda);
			if (coli.x < 0 && coli.y < 0) {
				primeira->Colisao(segunda,coli);
			}
		}

	}
}