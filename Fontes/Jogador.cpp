#include "../Cabecalhos/Jogador.h"

Entidades::Personagens::Jogador::Jogador(const int i, sf::Vector2f posi) :Personagem(i, posi), pontos(0),
andar_direita(false),andar_esquerda(false),arma(nullptr) {
	num_vidas = 5; 
	olhando_direita = true;
	arma = new Projetil();
	no_ar = true;
	arma->setDono(this);
	if (!Jogador2) {
		Jogador2 = true;
	}
	else {
		Imagem.setColor(sf::Color::Red);
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
	case 8:
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

void Entidades::Personagens::Jogador::salvar(){
}

const bool Entidades::Personagens::Jogador::getJogador2(){
	return Jogador2;
}

void Entidades::Personagens::Jogador::Colisao_Inimigo(Entidade* inimigo, sf::Vector2f limites){
	if (limites.x < 0) {
		if (inimigo->getPosicao().x < getPosicao().x) {
			setPosi(getPosicao().x - limites.x, getPosicao().y);
		}
		if (inimigo->getPosicao().x > getPosicao().x) {
			setPosi(getPosicao().x + limites.x, getPosicao().y);
		}
	}else if (limites.y < 0) {
		if (inimigo->getPosicao().y < getPosicao().y) {
		setPosi(getPosicao().x, getPosicao().y - (limites.y));
		}
		if (inimigo->getPosicao().y > getPosicao().y) {
			setPosi(getPosicao().x, getPosicao().y + (limites.y));
			no_ar = false;
		}
	}
	static_cast<Entidades::Personagens::Inimigo*>(inimigo)->danar(this);
}

void Entidades::Personagens::Jogador::Colisao_Obstaculo(Entidade* obstaculo, sf::Vector2f limites) {
	if (limites.y < 0) {
		setPosi(getPosicao().x, getPosicao().y + (limites.y));
		no_ar = false;
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
		mover_direita(rapidez);
	}
	else if (andar_esquerda) {
		mover_esquerda(rapidez);
	}
	Calc_Fisica();
	desenhar();
}

// define o primeiro jogador
bool Entidades::Personagens::Jogador::Jogador2 = false;
const float Entidades::Personagens::Jogador::rapidez = 40;

