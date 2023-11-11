#include "../Cabecalhos/Personagem.h"

Entidades::Personagens::Personagem::Personagem(const int i, sf::Vector2f posi) :Entidade(i, posi), num_vidas(3), Dano(1), iniciar(false),
olhando_direita(false){
}
Entidades::Personagens::Personagem::~Personagem(){
}

int Entidades::Personagens::Personagem::getVidas() const{
	return num_vidas;
}

void Entidades::Personagens::Personagem::operator--(){
	num_vidas--;
}

void Entidades::Personagens::Personagem::operator++(){
	num_vidas += 1;
}

void Entidades::Personagens::Personagem::mover_esquerda(float velo){
	Soma_Velocidade(sf::Vector2f(-velo, 0.0));
}

void Entidades::Personagens::Personagem::mover_direita(float velo) {
	Soma_Velocidade(sf::Vector2f(velo, 0.0));
}

void Entidades::Personagens::Personagem::pular(){
	if (!no_ar) {
		Soma_Velocidade(sf::Vector2f(0.0, -800));
		 no_ar = true;
	}
	else { return; }
}

void Entidades::Personagens::Personagem::causa_dano(Personagem* afetado){
	afetado->recebe_dano(Dano);
}

void Entidades::Personagens::Personagem::recebe_dano(int dano){
	num_vidas -= dano;
}

