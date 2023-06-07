#include "../Cabecalhos/Chao_Floresta.h"


Entidades::Obstaculos::Chao_Floresta::Chao_Floresta():Obstaculo(10) {
}
Entidades::Obstaculos::Chao_Floresta::~Chao_Floresta() {
}

void Entidades::Obstaculos::Chao_Floresta::executar(){
	desenhar();
}

void Entidades::Obstaculos::Chao_Floresta::Colisao(Entidade* colidida, sf::Vector2f limites){
}
