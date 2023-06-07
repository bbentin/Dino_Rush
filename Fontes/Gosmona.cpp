#include "../Cabecalhos/Gosmona.h"

Entidades::Personagens::Gosmona::Gosmona():Inimigo(15),meleca() {
	num_vidas = 5;
}
Entidades::Personagens::Gosmona::~Gosmona() {
}


void Entidades::Personagens::Gosmona::executar() {
	desenhar();
}

void Entidades::Personagens::Gosmona::padrao_acao() {

}

void Entidades::Personagens::Gosmona::atirar(){
}

void Entidades::Personagens::Gosmona::Colisao(Entidade* colidida, sf::Vector2f limites){
}
