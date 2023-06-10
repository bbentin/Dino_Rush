#include "../Cabecalhos/Mosca.h"

Entidades::Personagens::Mosca::Mosca():Inimigo(5) {
}
Entidades::Personagens::Mosca::~Mosca() {

}

void Entidades::Personagens::Mosca::executar(){
	desenhar();
	padrao_acao();
}

void Entidades::Personagens::Mosca::padrao_acao() {
}

void Entidades::Personagens::Mosca::Colisao(Entidade* colidida, sf::Vector2f limites){
}

void Entidades::Personagens::Mosca::danar(Entidade* Afetada){
}
