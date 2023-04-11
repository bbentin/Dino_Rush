#include "../Cabecalhos/Personagem.h"

Entidades::Personagens::Personagem::Personagem():Entidade(),Poder(2.5),num_vidas(3),flag_pulo(false),Dano(1){
}
Entidades::Personagens::Personagem::~Personagem(){
}

void Entidades::Personagens::Personagem::mover_esquerda(){
	soma_forca(sf::Vector2f(-Poder, 0.0)); 
}

void Entidades::Personagens::Personagem::mover_direita() {
	soma_forca(sf::Vector2f(Poder, 0.0));
}

void Entidades::Personagens::Personagem::pular(){
	if (!flag_pulo) {
		soma_forca(sf::Vector2f(0.0, Poder));
		alterar_pulo();
	}
	else {}
}

void Entidades::Personagens::Personagem::causa_dano(Personagem* afetado){
	afetado->recebe_dano(Dano);
}

void Entidades::Personagens::Personagem::recebe_dano(int dano){
	num_vidas -= dano;
}


void Entidades::Personagens::Personagem::alterar_pulo() {
	flag_pulo ? false : true;
}
