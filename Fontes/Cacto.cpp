#include "../Cabecalhos/Cacto.h"

Entidades::Obstaculos::Cacto::Cacto(){
}

Entidades::Obstaculos::Cacto::~Cacto(){
}

void Entidades::Obstaculos::Cacto::executar(){
	desenhar();
	Calc_Fisica();
}

void Entidades::Obstaculos::Cacto::Colisao(Entidade* colidida, sf::Vector2f limites){
}

void Entidades::Obstaculos::Cacto::obstacular(Entidade* obstaculada){
}
