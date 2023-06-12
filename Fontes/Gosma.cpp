#include "../Cabecalhos/Gosma.h"

Entidades::Personagens::Gosma::Gosma():Inimigo(3),direita(true),distancia(2) {
	num_vidas = 3;
}
Entidades::Personagens::Gosma::~Gosma() {
}

void Entidades::Personagens::Gosma::padrao_acao() {
	if (direita) {
		pular();
		soma_forca(sf::Vector2f(distancia, 0));
	}
	else {
		pular();
		soma_forca(sf::Vector2f(-distancia, 0));
	}
}

void Entidades::Personagens::Gosma::executar(){
	if (iniciar) { padrao_acao(); }
	Calc_Fisica();
	desenhar();
}

void Entidades::Personagens::Gosma::Colisao(Entidade* colidida, sf::Vector2f limites){
	int verificador = colidida->getId();
	if ((verificador == 9) || (verificador == 10)) {
		Colisao_Chao(colidida,limites);
		iniciar = true;
	}else if (verificador == 1 || verificador == 2) {

	}
}

void Entidades::Personagens::Gosma::Colisao_Chao(Entidade* Chao,sf::Vector2f limites){
	if (limites.y < 0) {
		direita = inverte();
		setPosi(getPosicao().x, getPosicao().y + limites.y);
		reseta_forca_res_y();
		no_ar = false;
	}
}

void Entidades::Personagens::Gosma::Colisao_Jogador(Entidade* Jogador,sf::Vector2f limites){
	if (limites.y < 0) {
		setPosi(getPosicao().x, getPosicao().y - (Jogador->getTamanho().y / 16 - getTamanho().y / 2));
		reseta_forca_res_y();
	}
	if (limites.x < 0) {
		if (getPosicao().x > Jogador->getPosicao().x) {
			setPosi(getPosicao().x - Jogador->getTamanho().x/2,getPosicao().y);
		}else if(getPosicao().x < Jogador->getPosicao().x){
			setPosi(getPosicao().x + Jogador->getTamanho().x/2, getPosicao().y);
		}
	}
	danar(Jogador);
}

void Entidades::Personagens::Gosma::danar(Entidade* afetada){
	static_cast<Entidades::Personagens::Personagem*>(afetada);
	afetada--;
}

bool Entidades::Personagens::Gosma::inverte(){
	if (direita) { return false; }
	else { return true; }
}
