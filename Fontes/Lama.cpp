#include "../Cabecalhos/Lama.h"
#include <sstream>

Entidades::Obstaculos::Lama::Lama(sf::Vector2f pos, const float limite):Obstaculo(7,limite),viscosidade(0) {
}

Entidades::Obstaculos::Lama::~Lama() {

}

void Entidades::Obstaculos::Lama::executar() {
	desenhar();
	if (getPosicao().y > limite_altura) {
		no_ar = false;
		parar_movimento_y();
	}
	else {
		Calc_Fisica();
	}
}

void Entidades::Obstaculos::Lama::Colisao(Entidade* colidida, sf::Vector2f limites){
}

void Entidades::Obstaculos::Lama::obstacular(Entidade* obstaculada){
	//empurrar(obstaculada);
	if (obstaculada->getRapidez() > 2) {
		obstaculada->multiplica_Rapidez(false);
	}
}

void Entidades::Obstaculos::Lama::salvar(std::ostringstream* entrada){
	sf::Vector2f pos = getPosicao();
	(*entrada) << "{ \"id\": [" << getId() << "], \"posicao\": [" << pos.x << "," << pos.y << "] }" << std::endl;
}
