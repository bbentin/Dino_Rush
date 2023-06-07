#include "../Cabecalhos/Decapitado.h"

Entidades::Personagens::Decapitado::Decapitado() :Inimigo(4) {
	num_vidas = 4;
}
Entidades::Personagens::Decapitado::~Decapitado() {
}

void Entidades::Personagens::Decapitado::executar(){
	desenhar();
}

void Entidades::Personagens::Decapitado::padrao_acao() {
}

void Entidades::Personagens::Decapitado::Colisao(Entidade* colidida, sf::Vector2f limites){
}
