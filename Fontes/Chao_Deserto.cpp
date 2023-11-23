#include "../Cabecalhos/Chao_Deserto.h"

Entidades::Obstaculos::Chao_Deserto::Chao_Deserto(const float limite_alt):Obstaculo(8,limite_alt) {
}
Entidades::Obstaculos::Chao_Deserto::~Chao_Deserto() {

}

void Entidades::Obstaculos::Chao_Deserto::executar(){
	desenhar();
	if (getPosicao().y >= limite_altura) {
		Soma_Velocidade(sf::Vector2f(0.0, -0.5));
		Calc_Fisica();
	}
	else {
		Calc_Fisica();
	}
}

void Entidades::Obstaculos::Chao_Deserto::Colisao(Entidade* colidida, sf::Vector2f limites){
		
}

void Entidades::Obstaculos::Chao_Deserto::obstacular(Entidade* obstaculada){
	obstaculada->multiplica_Rapidez(true);
}

void Entidades::Obstaculos::Chao_Deserto::salvar(std::ostringstream* entrada){
}