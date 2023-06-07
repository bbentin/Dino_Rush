#include "../Cabecalhos/Gosma.h"

Entidades::Personagens::Gosma::Gosma():Inimigo(3){
	num_vidas = 3;
}
Entidades::Personagens::Gosma::~Gosma() {
}

void Entidades::Personagens::Gosma::padrao_acao(){
	pular();
}

void Entidades::Personagens::Gosma::executar(){
	desenhar();
}

void Entidades::Personagens::Gosma::Colisao(Entidade* colidida, sf::Vector2f limites){
}
