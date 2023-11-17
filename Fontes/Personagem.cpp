#include "../Cabecalhos/Personagem.h"

Entidades::Personagens::Personagem::Personagem(const int i, sf::Vector2f posi) :Entidade(i, posi), num_vidas(3), Dano(1), iniciar(false), pontos(),
olhando_direita(false){
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
	if (!no_ar) {
		for (int i = 0; i < 10; i++) {
			Soma_Velocidade(sf::Vector2f(0.0, -80 -altura));
			Calc_Fisica();
		}
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

void Entidades::Personagens::Personagem::pontua() {
	this->pontos += 1;
	cout << this->getId() << " Pontos: " << pontos << endl;
	// Hud de pontos furutamente
}