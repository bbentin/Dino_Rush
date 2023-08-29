#include "../Cabecalhos/Mosca.h"

Entidades::Personagens::Mosca::Mosca():Inimigo(5),pos_x_inicial(getPosicao().x),direita(true) {
}
Entidades::Personagens::Mosca::~Mosca() {

}

void Entidades::Personagens::Mosca::inverter(){
	if (getPosicao().x > (pos_x_inicial + 20)) {
		direita = true;
	}
	else if (getPosicao().x < (pos_x_inicial - 20)) {
		direita = false;
	}
}

void Entidades::Personagens::Mosca::executar(){
	if (iniciar) { padrao_acao(); }
	Calc_Fisica();
	desenhar();
}

void Entidades::Personagens::Mosca::padrao_acao() {
	if (!direita) {
	}
	else {
	}
	inverter();
}

void Entidades::Personagens::Mosca::Colisao(Entidade* colidida, sf::Vector2f limites){
	int verificador = colidida->getId();

	if (verificador == 9 || verificador == 8) {
		ColisaoChao(colidida,limites);
	}
}

void Entidades::Personagens::Mosca::danar(Entidade* Afetada){
	Afetada--;
}

void Entidades::Personagens::Mosca::Inicializa(){
	Textura.loadFromImage(Grafico->getImagem(getId()));
	Imagem.setTexture(Textura);
	Imagem.setScale(2.0, 2.0);
	pos_x_inicial = getPosicao().x;
}

void Entidades::Personagens::Mosca::ColisaoChao(Entidade* Chao, sf::Vector2f limites){
	if (limites.y < 0) {
		setPosi(getPosicao().x, getPosicao().y + limites.y);
		no_ar = false;
		iniciar = true;
	}
}

