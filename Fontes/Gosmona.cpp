#include "../Cabecalhos/Gosmona.h"

Entidades::Personagens::Gosmona::Gosmona():Inimigo(6),meleca() {
	num_vidas = 5; massa = 20;
}
Entidades::Personagens::Gosmona::~Gosmona() {
}


void Entidades::Personagens::Gosmona::executar() {
	padrao_acao();
	Calc_Fisica();
	desenhar();
}

void Entidades::Personagens::Gosmona::padrao_acao() {
	pular();
}

void Entidades::Personagens::Gosmona::Colisao(Entidade* colidida, sf::Vector2f limites){
	int verificador = colidida->getId();
	if ((verificador == 9) || (verificador == 10)) {
		Colisao_Chao(colidida, limites);
		iniciar = true;
	}
	else if (verificador == 1 || verificador == 2) {

	}
}

void Entidades::Personagens::Gosmona::Colisao_Chao(Entidade* Chao, sf::Vector2f limites){
	if (limites.y < 0) {
		setPosi(getPosicao().x, getPosicao().y + limites.y);
		reseta_forca_res_y();
		no_ar = false;
	}
}

void Entidades::Personagens::Gosmona::danar(Entidade* Afetada){
}
