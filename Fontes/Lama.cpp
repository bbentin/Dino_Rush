#include "../Cabecalhos/Lama.h"

Entidades::Obstaculos::Lama::Lama():Obstaculo(7),limite_altura(887.6),viscosidade(0) {
}
Entidades::Obstaculos::Lama::~Lama() {

}

void Entidades::Obstaculos::Lama::executar() {
	desenhar();
	if (getPosicao().y >= limite_altura) {
		setPosi(getPosicao().x, limite_altura);
		no_ar = false;
	}
	else {
		Calc_Fisica();
	}
}

void Entidades::Obstaculos::Lama::Colisao(Entidade* colidida, sf::Vector2f limites){
}

void Entidades::Obstaculos::Lama::obstacular(Entidade* obstaculada){
obstaculada->soma_forca(sf::Vector2f(-5,0));

}
