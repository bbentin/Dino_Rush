#include "../Cabecalhos/Entidade.h"

Entidades::Entidade::Entidade():Ente() {
}

Entidades::Entidade::Entidade(sf::Vector2i posi){
	posicao = posi;
}

Entidades::Entidade::~Entidade() {
}
