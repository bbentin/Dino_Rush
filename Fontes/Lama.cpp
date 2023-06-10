#include "../Cabecalhos/Lama.h"

Entidades::Obstaculos::Lama::Lama():Obstaculo(8) {
}
Entidades::Obstaculos::Lama::~Lama() {

}
void Entidades::Obstaculos::Lama::desacelerar() {

}

void Entidades::Obstaculos::Lama::executar() {
	desenhar();
}

void Entidades::Obstaculos::Lama::Colisao(Entidade* colidida, sf::Vector2f limites){
}

void Entidades::Obstaculos::Lama::obstacular(Entidade* obstaculada){
}
