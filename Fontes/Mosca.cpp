#include "../Cabecalhos/Mosca.h"
#include <sstream>

Entidades::Personagens::Mosca::Mosca(sf::Vector2f pos, float vel):Inimigo(5),pos_x_inicial(getPosicao().x),direita(true),sujeira(20) {
}

Entidades::Personagens::Mosca::~Mosca() {

}

void Entidades::Personagens::Mosca::inverter(){
	if (getPosicao().x > (pos_x_inicial + 20)) {
		direita = true;
	}
	else if (getPosicao().x < (pos_x_inicial - 20)) {
		direita = false;
	}
}

void Entidades::Personagens::Mosca::executar(){
	if (iniciar) { padrao_acao(); }
	Calc_Fisica();
	desenhar();
}

void Entidades::Personagens::Mosca::padrao_acao() {
	if (!direita) {
		mover_direita(1);
	}
	else {
		mover_esquerda(1);
	}
	inverter();
}

void Entidades::Personagens::Mosca::Colisao(Entidade* colidida, sf::Vector2f limites){
	int verificador = colidida->getId();

	if (verificador == 9 || verificador == 8) {
		ColisaoChao(colidida,limites);
	}
}

void Entidades::Personagens::Mosca::danar(Entidade* Afetada){
	Afetada--;
	Afetada->multiplica_Rapidez(false);
}

void Entidades::Personagens::Mosca::Inicializa(){
	Textura.loadFromImage(Grafico->getImagem(getId()));
	Imagem.setTexture(Textura);
	Imagem.setScale(2.0, 2.0);
	pos_x_inicial = getPosicao().x;
}

void Entidades::Personagens::Mosca::ColisaoChao(Entidade* Chao, sf::Vector2f limites){
	if (limites.y < 0) {
		Imagem.move(0, limites.y);
		no_chao = true;
		no_ar = false;
		iniciar = true;
	}
}

void Entidades::Personagens::Mosca::salvar(std::ostringstream* entrada){
	sf::Vector2f pos = getPosicao();
	float vel = getRapidez();
	(*entrada) << "{ \"id\": [" << getId() << "], \"posicao\": [" << pos.x << "," << pos.y << "], \"velocidade\": [" << vel << "] }" << std::endl;
}