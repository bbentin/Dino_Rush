#include "../Cabecalhos/Jogador.h"

Entidades::Personagens::Jogador::Jogador(const int i, sf::Vector2f posi):Personagem(i,posi),pontos(0),
andar_direita(false),andar_esquerda(false),arma(nullptr) {
	num_vidas = 5; 
	arma = new Projetil();
	arma->setDono(this);
	if (!Jogador2) {
		Jogador2 = true;
	}
	else {
		
	}
}
Entidades::Personagens::Jogador::~Jogador() {
	delete arma;
}

void Entidades::Personagens::Jogador::Colisao(Entidade* colidida, sf::Vector2f limites) {
	int verificador = colidida->getId();
	
	switch (verificador){
	case 3:
		Colisao_Inimigo(colidida, limites);
		break;
	case 5:
		Colisao_Inimigo(colidida, limites);
		break;
	case 9:
		Colisao_Obstaculo(colidida, limites);
		break;
	case 10:
		Colisao_Obstaculo(colidida, limites);
		break;
	case 7:
		Colisao_Obstaculo(colidida, limites);
		break;
	default:
		break;
	}
	 //retora se houve colisão 
}

void Entidades::Personagens::Jogador::atirar(){
	arma->atirada();
}


void Entidades::Personagens::Jogador::Colisao_Deserto(Entidade* deserto, sf::Vector2f limites){
	if (limites.y < 0) {
		setPosi(getPosicao().x, getPosicao().y + (limites.y));
		reseta_forca_res_y();
		no_ar = false;
	}
	else if (limites.x < 0) {
		if (deserto->getPosicao().x < getPosicao().y) {
			setPosi(getPosicao().x + limites.x, getPosicao().y);
		}
		else if (deserto->getPosicao().x > 0) {
			setPosi(getPosicao().x - limites.x, getPosicao().y);
		}
	}
}

void Entidades::Personagens::Jogador::Colisao_Floresta(Entidade* floresta, sf::Vector2f limites){
	if (limites.y < 0) {
		setPosi(getPosicao().x, getPosicao().y + (limites.y));
		no_ar = false;
		reseta_forca_res_y();
	}else if (limites.x < 0) {
		if (floresta->getPosicao().x < getPosicao().x) {
			setPosi(getPosicao().x + limites.x, getPosicao().y);
		}
		else if (floresta->getPosicao().x > getPosicao().x) {
			setPosi(getPosicao().x - limites.x, getPosicao().y);
		}
	}
}

void Entidades::Personagens::Jogador::Colisao_Projetil(Entidade* projetil, sf::Vector2f limites){

}

void Entidades::Personagens::Jogador::Colisao_Inimigo(Entidade* inimigo, sf::Vector2f limites){
	if (limites.x < 0) {
		if (inimigo->getPosicao().x < getPosicao().x) {
			setPosi(getPosicao().x - limites.x, getPosicao().y);
			reseta_forca_res_x();
		}
		if (inimigo->getPosicao().x > getPosicao().x) {
			setPosi(getPosicao().x + limites.x, getPosicao().y);
			reseta_forca_res_x();
		}
	}else if (limites.y < 0) {
		setPosi(getPosicao().x, getPosicao().y + (limites.y));
		no_ar = false;
		reseta_forca_res_y();
	}
	static_cast<Entidades::Personagens::Inimigo*>(inimigo)->danar(this);
}

void Entidades::Personagens::Jogador::Colisao_Obstaculo(Entidade* obstaculo, sf::Vector2f limites) {
	if (limites.y < 0) {
		setPosi(getPosicao().x, getPosicao().y + (limites.y));
		no_ar = false;
		reseta_forca_res_y();
	}else if (limites.x < 0) {
		if (obstaculo->getPosicao().x < getPosicao().x) {
			setPosi(getPosicao().x + limites.x, getPosicao().y);
		}
		else if (obstaculo->getPosicao().x > getPosicao().x) {
			setPosi(getPosicao().x - limites.x, getPosicao().y);
		}
	}
	static_cast<Entidades::Obstaculos::Obstaculo*>(obstaculo)->obstacular(this);
}
Entidades::Projetil* Entidades::Personagens::Jogador::getArma() const{
	return arma;
}
void Entidades::Personagens::Jogador::setMovimento_direita(bool direita){
	andar_direita = direita;
}

void Entidades::Personagens::Jogador::setMovimento_esquerda(bool esquerda){
	andar_esquerda = esquerda;
}

void Entidades::Personagens::Jogador::executar() {
	if (andar_direita) {
		soma_forca(sf::Vector2f(10, 0));
	}
	else if (andar_esquerda) {
		soma_forca(sf::Vector2f(-10, 0));
	}
	Calc_Fisica();
	desenhar();
}


// define o primeiro jogador
bool Entidades::Personagens::Jogador::Jogador2 = false;

