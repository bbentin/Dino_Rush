#include "../Cabecalhos/Chao_Floresta.h"

Entidades::Obstaculos::Chao_Floresta::Chao_Floresta(const float limit) :Obstaculo(9, limit),susto() {
}

Entidades::Obstaculos::Chao_Floresta::~Chao_Floresta() {
}

void Entidades::Obstaculos::Chao_Floresta::executar() {
	desenhar();
	if (getPosicao().y >= limite_altura) {
		Soma_Velocidade(sf::Vector2f(0, -0.5));
	}
	else {
		Calc_Fisica();
	}
}

void Entidades::Obstaculos::Chao_Floresta::Colisao(Entidade* colidida, sf::Vector2f limites) {
}

void Entidades::Obstaculos::Chao_Floresta::obstacular(Entidade* obstaculada) {
	obstaculada->multiplica_Rapidez(4);
	int tempo = susto.getElapsedTime().asSeconds();
	if (tempo % 10  == 0) {
		empurrar(obstaculada);
		susto.restart();
	}
}

void Entidades::Obstaculos::Chao_Floresta::salvar(std::ostringstream* entrada) {
	sf::Vector2f pos = getPosicao();
	(*entrada) << "{ \"id\": [" << getId() << "], \"posicao\": [" << pos.x << "," << pos.y << "] }" << std::endl;
}
