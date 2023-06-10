#include "../Cabecalhos/Gosma.h"

Entidades::Personagens::Gosma::Gosma():Inimigo(3),tempo_pulo(3),tempo(0) {
	num_vidas = 3;
}
Entidades::Personagens::Gosma::~Gosma() {
}

void Entidades::Personagens::Gosma::padrao_acao() {
	pular();
}

void Entidades::Personagens::Gosma::executar(){
	padrao_acao();
	Calc_Fisica();
	desenhar();
}

void Entidades::Personagens::Gosma::Colisao(Entidade* colidida, sf::Vector2f limites){
	int verificador = colidida->getId();
	if ((verificador == 9) || (verificador == 10)) {
		if (limites.y < 0) {
			setPosi(getPosicao().x, getPosicao().y - (colidida->getTamanho().y / 16 - getTamanho().y / 2));
			reseta_forca_res_y();
			no_ar = false;
		}
	}
}

void Entidades::Personagens::Gosma::danar(Entidade* afetada){
}
