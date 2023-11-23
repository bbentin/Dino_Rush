#include "../Cabecalhos/Gosma.h"
#include <sstream>

Entidades::Personagens::Gosma::Gosma(sf::Vector2f pos, float vel):Inimigo(3, pos),num_pulos(10) {
	num_vidas = 3;
}

Entidades::Personagens::Gosma::~Gosma() {
}

void Entidades::Personagens::Gosma::padrao_acao() {
		pular(0);	
		num_pulos--;
		if (num_pulos <= 0){
			//delete this;
		}
}

void Entidades::Personagens::Gosma::executar(){
	if (iniciar) { padrao_acao(); }
	Calc_Fisica();
	desenhar();
}

void Entidades::Personagens::Gosma::Colisao(Entidade* colidida, sf::Vector2f limites){
	int verificador = colidida->getId();
	if ((verificador == 8) || (verificador == 9)) {
		Colisao_Chao(colidida,limites);
		iniciar = true;
	}
}

void Entidades::Personagens::Gosma::Colisao_Chao(Entidade* Chao,sf::Vector2f limites){
	if (limites.y < 0) {
		setPosi(getPosicao().x, getPosicao().y + limites.y);
		no_ar = false;
	}
}

void Entidades::Personagens::Gosma::Colisao_Jogador(Entidade* Jogador,sf::Vector2f limites){
	if (limites.y < 0) {
		setPosi(getPosicao().x, getPosicao().y - (Jogador->getTamanho().y / 16 - getTamanho().y / 2));
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
	empurrar(afetada);
	static_cast<Entidades::Personagens::Personagem*>(afetada);
	afetada--;
}

void Entidades::Personagens::Gosma::salvar(std::ostringstream* entrada){
	sf::Vector2f pos = getPosicao();
	float vel = getRapidez();
	(*entrada) << "{ \"id\": [" << getId() << "], \"posicao\": [" << pos.x << "," << pos.y << "], \"velocidade\": [" << vel << "] }" << std::endl;
}