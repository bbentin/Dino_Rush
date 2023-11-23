#include "../Cabecalhos/Personagem.h"

Entidades::Personagens::Personagem::Personagem(const int i, sf::Vector2f posi) :Entidade(i, posi), num_vidas(3), Dano(1), iniciar(false),
olhando_direita(false),no_chao(false) {
}
Entidades::Personagens::Personagem::~Personagem(){
}

int Entidades::Personagens::Personagem::getVidas() {
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

void Entidades::Personagens::Personagem::pular(int altura){
	multiplica_Rapidez(true);
	if (no_chao) {
		Imagem.move(sf::Vector2f(0, -altura));
		 no_ar = true;
		 no_chao = false;
	}
	else { return; }
}

void Entidades::Personagens::Personagem::causa_dano(Personagem* afetado){
	afetado->recebe_dano(Dano);
}

void Entidades::Personagens::Personagem::recebe_dano(int dano){
	num_vidas -= dano;
}
