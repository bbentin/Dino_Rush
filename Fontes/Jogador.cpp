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
	case 3:
		Colisao_Gosma(colidida,limites);
		break;
	case 4:
		Colisao_Mosca(colidida,limites);
		break;
	case 5:
		Colisao_Moscona(colidida,limites);
		break;
	case 6:
		break;
	case 7:
		break;
	case 8:
		break;
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


void Entidades::Personagens::Jogador::Colisao_Mosca(Entidade* odiada, sf::Vector2f limites) {
	operator--();
}

void Entidades::Personagens::Jogador::Colisao_Moscona(Entidade* parada, sf::Vector2f limites) {
	operator--();
}

void Entidades::Personagens::Jogador::Colisao_Gosma(Entidade* atirada, sf::Vector2f limites) {
	
}

void Entidades::Personagens::Jogador::Colisao_Decapitado(Entidade* decapitado, sf::Vector2f limites){
}

void Entidades::Personagens::Jogador::Colisao_Chefao(Entidade* chefao, sf::Vector2f limites){
}

void Entidades::Personagens::Jogador::Colisao_Espinhos(Entidade* espinhos, sf::Vector2f limites){
}

void Entidades::Personagens::Jogador::Colisao_Lama(Entidade* lama, sf::Vector2f limites){
}

void Entidades::Personagens::Jogador::Colisao_Deserto(Entidade* deserto, sf::Vector2f limites){
	if (limites.y < 0) {
		setPosi(getPosicao().x, getPosicao().y - (deserto->getTamanho().y / 16 - getTamanho().y/2));
		reseta_forca_res_y();
		no_ar = false;
	}

}

void Entidades::Personagens::Jogador::Colisao_Floresta(Entidade* floresta, sf::Vector2f limites){
	if (limites.y < 0) {
		setPosi(getPosicao().x, getPosicao().y - (floresta->getTamanho().y / 16 - getTamanho().y / 2));
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

