#include "../Cabecalhos/Jogador.h"

Entidades::Personagens::Jogador::Jogador(const int i, sf::Vector2f posi):Personagem(i,posi),pontos(0),andar_direita(false),andar_esquerda(false) {
	num_vidas = 5; 
	setPosi(50, 400);
	if (!Jogador2) {
		Jogador2 = true;
	}
	else {
		
	}
}
Entidades::Personagens::Jogador::~Jogador() {
}

bool Entidades::Personagens::Jogador::Colisoes(Entidade* colidida) {
	int verificador = colidida->getId();
	bool bateu = Colide(colidida);
	switch (verificador){
	case 1:
		Colisao_Inimigo(colidida);
		break;
	case 2:
		Colisao_Obstaculo(colidida);
		break;
		return colidida;
	case 3:
		Colisao_Projetil(colidida);
		break;
	default:
		break;
	}
	return bateu; //retora se houve colisão 
}


void Entidades::Personagens::Jogador::Colisao_Inimigo(Entidade* odiada) {
	Colide(odiada);
}

void Entidades::Personagens::Jogador::Colisao_Obstaculo(Entidade* parada) {
	Colide(parada);
}

void Entidades::Personagens::Jogador::Colisao_Projetil(Entidade* atirada) {
	Colide(atirada);
}

void Entidades::Personagens::Jogador::setMovimento_direita(bool direita){
	andar_direita = direita;
}

void Entidades::Personagens::Jogador::setMovimento_esquerda(bool esquerda){
	andar_esquerda = esquerda;
}

void Entidades::Personagens::Jogador::executar() {
	if (andar_direita) {
		soma_forca(sf::Vector2f(10, 0));
	}
	else if (andar_esquerda) {
		soma_forca(sf::Vector2f(-10, 0));
	}
////	soma_forca(sf::Vector2f(10, 0));
	Aplicar_Forca();
	desenhar();
}


// define o primeiro jogador
bool Entidades::Personagens::Jogador::Jogador2 = false;

