#include "../Cabecalhos/Chao_Floresta.h"


Entidades::Obstaculos::Chao_Floresta::Chao_Floresta(const int limit) :Obstaculo(9), limite_altura(limit) {
}
Entidades::Obstaculos::Chao_Floresta::~Chao_Floresta() {
}

void Entidades::Obstaculos::Chao_Floresta::executar(){
	desenhar();
	if (getPosicao().y >= limite_altura) {
		setPosi(getPosicao().x, limite_altura);
		no_ar = false; 
	}
	else {
		Calc_Fisica();
	}
}

void Entidades::Obstaculos::Chao_Floresta::Colisao(Entidade* colidida, sf::Vector2f limites){
}

void Entidades::Obstaculos::Chao_Floresta::obstacular(Entidade* obstaculada){
}

void Entidades::Obstaculos::Chao_Floresta::salvar(){
}
