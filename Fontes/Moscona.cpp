#include "../Cabecalhos/Moscona.h"

Entidades::Personagens::Moscona::Moscona():Inimigo(16) {
	num_vidas = 5;
}
Entidades::Personagens::Moscona::~Moscona() {
}


void Entidades::Personagens::Moscona::executar() {
	desenhar();
}

void Entidades::Personagens::Moscona::padrao_acao() {

}

void Entidades::Personagens::Moscona::Colisao(Entidade* colidida, sf::Vector2f limites){
}

void Entidades::Personagens::Moscona::danar(Entidade* Afetada){
}
