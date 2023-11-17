#include "../Cabecalhos/Projetil.h"

Entidades::Projetil::Projetil():Entidade(12),visivel(false),dono(nullptr) {
}

Entidades::Projetil::~Projetil(){
}

void Entidades::Projetil::reseta_posicao(){
	setPosi(dono->getPosicao().x + 10, dono->getPosicao().y+8);
}

void Entidades::Projetil::Colisao(Entidade* colidida, sf::Vector2f limites){
	int IdDono = dono->getId();
	int IdColidida = colidida->getId();

	if (IdDono == 1 || IdDono == 2) {
		switch (IdColidida){
		case 3:
			ColisaoPersonagem(colidida);
			if (static_cast<Entidades::Personagens::Personagem*>(colidida)->getVidas() == 0)
			{
				static_cast<Entidades::Personagens::Personagem*>(dono)->pontua();
			}
			break;
		case 4:
			ColisaoPersonagem(colidida);
			if (static_cast<Entidades::Personagens::Personagem*>(colidida)->getVidas() == 0)
			{
				static_cast<Entidades::Personagens::Personagem*>(dono)->pontua();
			}
			break;
		case 5:
			ColisaoPersonagem(colidida);
			if (static_cast<Entidades::Personagens::Personagem*>(colidida)->getVidas() == 0)
			{
				static_cast<Entidades::Personagens::Personagem*>(dono)->pontua();
			}
			break;
		case 6:
			ColisaoPersonagem(colidida);
			if (static_cast<Entidades::Personagens::Personagem*>(colidida)->getVidas() == 0)
			{
				static_cast<Entidades::Personagens::Personagem*>(dono)->pontua();
			}
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
	else if (IdDono == 4) {
		switch (IdColidida){
		case 1:
			ColisaoPersonagem(colidida);
			break;
		case 2:
			ColisaoPersonagem(colidida);
			break;
		case 8:
			ColisaoObstaculo(colidida);
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

void Entidades::Projetil::avanca(){
	if (dono->getId() == 1) {
		if (visivel) {
			Soma_Velocidade(sf::Vector2f(40.0, -5));
			Calc_Fisica();
			desenhar();
		}
		else { reseta_posicao(); }
	}
	else if (dono->getId() == 4) {
		if (visivel) {
			Soma_Velocidade(sf::Vector2f(-40.0, -5));
			Calc_Fisica();
			desenhar();
		}
		else { reseta_posicao(); }
	}
	if (getPosicao().x > 1300 || getPosicao().x < 0) {
		reseta_posicao(); visivel = false;
	} 
}

void Entidades::Projetil::salvar(){
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
	avanca();
}