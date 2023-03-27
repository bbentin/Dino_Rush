#include "../Cabecalhos/Entidade.h"

Entidades::Entidade::Entidade():Ente(),massa(5) {
}

Entidades::Entidade::Entidade(sf::Vector2f posi):massa(5) {
	posicao = posi;
}

Entidades::Entidade::~Entidade() {
}

sf::Vector2f Entidades::Entidade::Limitar_Velocidade(sf::Vector2f Velocidade) {
	sf::Vector2f Velocidade_condizente(0.0, 0.0);

	Velocidade_condizente = Velocidade;
	if (Velocidade.x > 30) {
		Velocidade_condizente.x = 30;
	}
	if (Velocidade.y > 30) {
		Velocidade_condizente.y = 30;
	}

	return Velocidade_condizente;
}

void Entidades::Entidade::Aplicar_Gravidade() {
	Aplicar_Forca(sf::Vector2f(0.1f,0.1f));
}


const int Entidades::Entidade::Gravidade = 10;