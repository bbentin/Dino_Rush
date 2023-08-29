#include "../Cabecalhos/Gerenciador_Colisoes.h"

Gerenciadores::Gerenciador_Colisoes::Gerenciador_Colisoes(){
	LPersonagens.clear();	LOs.clear();
}

Gerenciadores::Gerenciador_Colisoes::~Gerenciador_Colisoes() {
	LPersonagens.clear();	LOs.clear();
}

void Gerenciadores::Gerenciador_Colisoes::addInimigo(Entidades::Personagens::Inimigo* pIni){
	if (pIni != nullptr) {
		LPersonagens.push_back(static_cast<Entidades::Entidade*>(pIni));
	}
}

void Gerenciadores::Gerenciador_Colisoes::addJogador(Entidades::Personagens::Jogador* pJog) {
	if (pJog != nullptr) {
		LPersonagens.push_back(static_cast<Entidades::Entidade*>(pJog));
		LPersonagens.push_back(static_cast<Entidades::Entidade*>(pJog->getArma()));
	}
}

void Gerenciadores::Gerenciador_Colisoes::addProjetil(Entidades::Projetil* pArma){
	if (pArma != nullptr) {
		LPersonagens.push_back(static_cast<Entidades::Entidade*>(pArma));
	}
}

void Gerenciadores::Gerenciador_Colisoes::addObstaculo(Entidades::Obstaculos::Obstaculo* pObs){
	if (pObs != nullptr) {
		LOs.push_back(pObs);
	}
}

void Gerenciadores::Gerenciador_Colisoes::removeObstaculo(Entidades::Entidade* pRemovido){
	if (pRemovido != nullptr) {
		int i = 0;
		while (i < LOs.size()) {
			if (pRemovido == LOs.at(i)) {
				LOs.erase(LOs.begin() + i);
				cout << "Entidade removida do vetor no gerenciador de colisoes" << endl;
				return;
			}
			i++;
		}
	}
}

Entidades::Entidade* Gerenciadores::Gerenciador_Colisoes::VerificaMortos(){
	int i = 0;
	Entidades::Entidade* pMorto;
	while (i < LPersonagens.size()) {

		if (LPersonagens[i]->getId() < 7) {
			if (static_cast<Entidades::Personagens::Personagem*>(LPersonagens[i])->getVidas() <= 0) {
				pMorto = LPersonagens[i];
				LPersonagens.erase(LPersonagens.begin() + i);
				return pMorto;
			}
		}
		i++;
	}

}

void Gerenciadores::Gerenciador_Colisoes::executar() {
	int N_Obs = LOs.size();
	int N_Pers = LPersonagens.size();
	int k;

	for (int i = 0; i < N_Pers ; i++) {
	Entidades::Entidade* primeira = LPersonagens[i];
		
		for (int j = 0; j < N_Pers; j++) {
			Entidades::Entidade* segunda = LPersonagens[j];
			sf::Vector2f coli = primeira->Existe_Colisao(segunda);
			if (coli.x < 0 && coli.y < 0 ) {
				primeira->Colisao(segunda,coli);
			}
		}
		for (k = 0; k < N_Obs; k++) {
			Entidades::Entidade* segunda = static_cast<Entidades::Entidade*>(LOs[k]);
			sf::Vector2f coli = primeira->Existe_Colisao(segunda);
			if (coli.x < 0 && coli.y < 0) {
				primeira->Colisao(segunda,coli);
			}
		}
	}
}