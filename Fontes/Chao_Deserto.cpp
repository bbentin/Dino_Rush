#include "../Cabecalhos/Chao_Deserto.h"

Entidades::Obstaculos::Chao_Deserto::Chao_Deserto():Obstaculo(9) {
}
Entidades::Obstaculos::Chao_Deserto::~Chao_Deserto() {

}

void Entidades::Obstaculos::Chao_Deserto::executar(){
	desenhar();
}

void Entidades::Obstaculos::Chao_Deserto::Colisao(Entidade* colidida, sf::Vector2f limites){
}
