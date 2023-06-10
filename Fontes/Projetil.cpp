#include "../Cabecalhos/Projetil.h"

Entidades::Projetil::Projetil():Entidade(13),visivel(false),dano(1),dono(nullptr) {
}

Entidades::Projetil::~Projetil(){
}

void Entidades::Projetil::reseta_posicao(){
	setPosi(dono->getPosicao());
}

void Entidades::Projetil::Colisao(Entidade* colidida, sf::Vector2f limites){
	int IdDono = dono->getId();
	int IdColidida = colidida->getId();

	if (IdDono == 1 || IdDono == 2) {
		switch (IdColidida){

		default:
			break;
		}
	}
	else if (IdDono == 5) {
		switch (IdColidida){
		default:
			break;
		}
	}
	
	visivel = false;
	reseta_posicao();
}

void Entidades::Projetil::atirada(){
	visivel = true;
}

void Entidades::Projetil::setDono(Entidade* Dono){
	if (Dono != nullptr) {
		dono = Dono;
	}
	else { std::cout << "Dono invalido" << std::endl; }
}

void Entidades::Projetil::executar() {
	if (visivel) {
		soma_forca(sf::Vector2f(20, 0));
		Calc_Fisica();
		desenhar();
	}
}