#include "../Cabecalhos/Chefao.h"

Entidades::Personagens::Chefao::Chefao() :Inimigo(6) {
	num_vidas = 10;
}
Entidades::Personagens::Chefao::~Chefao() {
}

void Entidades::Personagens::Chefao::executar(){
	desenhar();
}

void Entidades::Personagens::Chefao::padrao_acao() {
}

void Entidades::Personagens::Chefao::Colisao(Entidade* colidida, sf::Vector2f limites){
}

void Entidades::Personagens::Chefao::danar(Entidade* Afetada){
}
