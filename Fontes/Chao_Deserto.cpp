#include "../Cabecalhos/Chao_Deserto.h"

Entidades::Obstaculos::Chao_Deserto::Chao_Deserto(const int limite_alt):Obstaculo(8),limite_altura(limite_alt) {
}
Entidades::Obstaculos::Chao_Deserto::~Chao_Deserto() {

}

void Entidades::Obstaculos::Chao_Deserto::executar(){
	desenhar();
	if (getPosicao().y >= limite_altura) {
		setPosi(getPosicao().x, limite_altura);
		no_ar = false;
	}
	else {
		Calc_Fisica();
	}
}

void Entidades::Obstaculos::Chao_Deserto::Colisao(Entidade* colidida, sf::Vector2f limites){
		
}

void Entidades::Obstaculos::Chao_Deserto::obstacular(Entidade* obstaculada){
}
