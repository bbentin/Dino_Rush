#include "../Cabecalhos/Personagem.h"

int Entidades::Personagens::Personagem::getVidas() const{
	return num_vidas;
}

void Entidades::Personagens::Personagem::operator--(){
	num_vidas--;
}

void Entidades::Personagens::Personagem::operator++(){
	num_vidas -= 1;
}

Entidades::Personagens::Personagem::Personagem(const int i,sf::Vector2f posi):Entidade(i,posi),num_vidas(3),Dano(1),iniciar(false) {
}
Entidades::Personagens::Personagem::~Personagem(){
}

void Entidades::Personagens::Personagem::mover_esquerda(){
	soma_forca(sf::Vector2f(-forca_movimento, 0.0)); 
}

void Entidades::Personagens::Personagem::mover_direita() {
	soma_forca(sf::Vector2f(forca_movimento, 0.0));
}

void Entidades::Personagens::Personagem::pular(){
	if (!no_ar) {
		soma_forca(sf::Vector2f(0.0, -400));
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

void Entidades::Personagens::Personagem::executar(){
}


const int Entidades::Personagens::Personagem::forca_movimento = 4.0;