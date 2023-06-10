#include "../Cabecalhos/Jogador.h"

Entidades::Personagens::Jogador::Jogador(const int i, sf::Vector2f posi):Personagem(i,posi),pontos(0),andar_direita(false),andar_esquerda(false) {
	num_vidas = 5; 
	setPosi(50, 400);
	if (!Jogador2) {
		Jogador2 = true;
	}
	else {
		
	}
}
Entidades::Personagens::Jogador::~Jogador() {
}

void Entidades::Personagens::Jogador::Colisao(Entidade* colidida, sf::Vector2f limites) {
	int verificador = colidida->getId();
	
	switch (verificador){
	case 9:
		Colisao_Deserto(colidida,limites);
		break;
	case 10:
		Colisao_Floresta(colidida,limites);
		break;
	default:
		break;
	}
	 //retora se houve colisão 
}


void Entidades::Personagens::Jogador::Colisao_Deserto(Entidade* deserto, sf::Vector2f limites){
	if (limites.y < 0) {
		setPosi(getPosicao().x, getPosicao().y - ((deserto->getTamanho().y / 200) - (getTamanho().y/200)));
		reseta_forca_res_y();
		no_ar = false;
	}

}

void Entidades::Personagens::Jogador::Colisao_Floresta(Entidade* floresta, sf::Vector2f limites){
	if (limites.y < 0) {
		setPosi(getPosicao().x, getPosicao().y - ((floresta->getTamanho().y / 200) + (getTamanho().y / 200)));
		reseta_forca_res_y();
		no_ar = false;
	}
}

void Entidades::Personagens::Jogador::Colisao_Projetil(Entidade* projetil, sf::Vector2f limites){
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
	//soma_forca(sf::Vector2f(10, 0));
	Calc_Fisica();
	desenhar();
}


// define o primeiro jogador
bool Entidades::Personagens::Jogador::Jogador2 = false;

