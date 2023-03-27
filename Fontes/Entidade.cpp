#include "../Cabecalhos/Entidade.h"

Entidades::Entidade::Entidade():Ente(),massa(5) {
}

Entidades::Entidade::Entidade(sf::Vector2f posi):massa(5) {
	posicao = posi;
}

Entidades::Entidade::~Entidade() {
}


const int Entidades::Entidade::Gravidade = 10;