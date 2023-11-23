#include "../Cabecalhos/Lama.h"

Entidades::Obstaculos::Lama::Lama(const float limite):Obstaculo(7,limite),viscosidade(0) {
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
}
