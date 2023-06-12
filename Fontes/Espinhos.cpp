#include "../Cabecalhos/Espinhos.h"

Entidades::Obstaculos::Espinhos::Espinhos():Obstaculo(10),dano(2) {
}

Entidades::Obstaculos::Espinhos::~Espinhos(){
}

void Entidades::Obstaculos::Espinhos::executar(){
	desenhar();
	Calc_Fisica();
}

void Entidades::Obstaculos::Espinhos::Colisao(Entidade* colidida, sf::Vector2f limites){
}

void Entidades::Obstaculos::Espinhos::obstacular(Entidade* obstaculada){
	obstaculada--;
}
