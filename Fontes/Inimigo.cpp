#include "../Cabecalhos/Inimigo.h"

Entidades::Personagens::Inimigo::Inimigo(const int i, sf::Vector2f posi):Personagem(i,posi) {
	srand(time(NULL));
	nivel_maldade = 1 + rand() % 2;
}

Entidades::Personagens::Inimigo::~Inimigo(){
}

void Entidades::Personagens::Inimigo::executar(){
}
