#include "../Cabecalhos/Projetil.h"

Entidades::Projetil::Projetil():Entidade(12),visivel(false),dono(nullptr) {
	massa = 10;
}

Entidades::Projetil::~Projetil(){
}

void Entidades::Projetil::reseta_posicao(){
	setPosi(dono->getPosicao().x + 10, dono->getPosicao().y);
}

void Entidades::Projetil::Colisao(Entidade* colidida, sf::Vector2f limites){
	int IdDono = dono->getId();
	int IdColidida = colidida->getId();

	if (IdDono == 1 || IdDono == 2) {
		switch (IdColidida){
		case 3:
			ColisaoPersonagem(colidida);
			break;
		case 4:
			ColisaoPersonagem(colidida);
			break;
		case 5:
			ColisaoPersonagem(colidida);
			break;
		case 6:
			ColisaoPersonagem(colidida);
			break;
		case 8:
			ColisaoObstaculo(colidida);
			break;
		case 9:
			ColisaoObstaculo(colidida);
			break;
		default:
			break;
		}
	}
	else if (IdDono == 5) {
		switch (IdColidida){
		case 1:
			ColisaoPersonagem(colidida);
			break;
		case 2:
			ColisaoPersonagem(colidida);
			break;
		default:
			break;
		}
	}
	
}

void Entidades::Projetil::ColisaoPersonagem(Entidade* colidida){
	reseta_posicao();	visivel = false;
	static_cast<Entidades::Personagens::Personagem*>(colidida)->operator--();
}

void Entidades::Projetil::ColisaoObstaculo(Entidade* colidida){
	reseta_posicao();	visivel = false;
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

bool Entidades::Projetil::GetVisibilidade() const{
	return visivel;
}

void Entidades::Projetil::executar() {
	if (visivel) {
		soma_forca(sf::Vector2f(30, 0));
		Calc_Fisica();
		desenhar();
	}
	else { reseta_posicao(); }
}