#include "../Cabecalhos/Projetil.h"
#include <sstream>


Entidades::Projetil::Projetil(sf::Vector2f pos, Entidade* Dono, float vel, bool visi) :Entidade(12), visivel(visi), dono(Dono) {
}

Entidades::Projetil::~Projetil() {
}

void Entidades::Projetil::reseta_posicao(){
	setPosi(dono->getPosicao().x + 10, dono->getPosicao().y+4);
}

void Entidades::Projetil::Colisao(Entidade* colidida, sf::Vector2f limites) {
	int IdDono = dono->getId();
	int IdColidida = colidida->getId();

	if (IdDono == 1 || IdDono == 2) {
		switch (IdColidida) {
		case 3:
			ColisaoPersonagem(colidida);
			if (static_cast<Entidades::Personagens::Personagem*>(colidida)->getVidas() == 0){
				pontua = true;
			}
			break;
		case 4:
			ColisaoPersonagem(colidida);
			if (static_cast<Entidades::Personagens::Personagem*>(colidida)->getVidas() == 0) {
				pontua = true;
			}
			break;
		case 5:
			ColisaoPersonagem(colidida);
			if (static_cast<Entidades::Personagens::Personagem*>(colidida)->getVidas() == 0) {
				pontua = true;
			}
			break;
		case 6:
			ColisaoPersonagem(colidida);
			if (static_cast<Entidades::Personagens::Personagem*>(colidida)->getVidas() == 0) {
				pontua = true;
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
		switch (IdColidida) {
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

void Entidades::Projetil::ColisaoPersonagem(Entidade* colidida) {
	if (visivel) {
		reseta_posicao();	visivel = false;
		static_cast<Entidades::Personagens::Personagem*>(colidida)->operator--();
	}
}

void Entidades::Projetil::ColisaoObstaculo(Entidade* colidida) {
	reseta_posicao();	visivel = false;
}

void Entidades::Projetil::atirada() {
	visivel = true;
}

void Entidades::Projetil::avanca() {
	if (dono->getId() == 1) {
		if (visivel) {
			Soma_Velocidade(sf::Vector2f(2.0,-0.3));
			Calc_Fisica();
			desenhar();
		}
		else { reseta_posicao(); }
	}
	else if (dono->getId() == 4) {
		if (visivel) {
			Soma_Velocidade(sf::Vector2f(-2.0,-0.3));
			Calc_Fisica();
			desenhar();
		}
		else { reseta_posicao(); }
	}
	if (getPosicao().x > 1300 || getPosicao().x < 0) {
		reseta_posicao(); visivel = false;
	}
}

void Entidades::Projetil::salvar(std::ostringstream* entrada) {
	/*sf::Vector2f pos = getPosicao();
	float vel = getRapidez();
	(*entrada) << "{ \"id\": [" << getId() << "], \"posicao\": [" << pos.x << "," << pos.y << "], \"velocidade\": [" << vel << "], \"visibilidade\": [" << visivel << "], \"dono\": [" << dono->getId() << "] }" << std::endl;*/
}

void Entidades::Projetil::setDono(Entidade* Dono) {
	if (Dono != nullptr) {
		dono = Dono;
	}
	else { std::cout << "Dono invalido" << std::endl; }
}


const bool Entidades::Projetil::getPontos(){
	if (pontua) {
		pontua = false;
		return true;
	}
	else { return false; }
}

bool Entidades::Projetil::GetVisibilidade() const{
	return visivel;
}

void Entidades::Projetil::executar() {
	avanca();
}