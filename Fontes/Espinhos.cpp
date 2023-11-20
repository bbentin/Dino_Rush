#include "../Cabecalhos/Espinhos.h"

Entidades::Obstaculos::Espinhos::Espinhos(const float limite_alt):Obstaculo(10,limite_alt),dano(2),relogio(),visivel(false) {
	no_ar = true;
}

Entidades::Obstaculos::Espinhos::~Espinhos(){
}

void Entidades::Obstaculos::Espinhos::executar(){
	brotar();
	if (visivel) {
	desenhar();
	}
	if (getPosicao().y > limite_altura) {
		no_ar = false;
		parar_movimento_y();
	}
	else{
		desenhar();
		Calc_Fisica();
	}
}

void Entidades::Obstaculos::Espinhos::Colisao(Entidade* colidida, sf::Vector2f limites){
}

void Entidades::Obstaculos::Espinhos::obstacular(Entidade* obstaculada){
	if (visivel) {
		empurrar(obstaculada);
		static_cast<Entidades::Personagens::Personagem*>(obstaculada)->operator--();
	}
}

void Entidades::Obstaculos::Espinhos::salvar(){
}

void Entidades::Obstaculos::Espinhos::brotar() {
	int tempo = relogio.getElapsedTime().asSeconds();
	if (tempo == 2) {
		visivel = true;
	}
	if (tempo == 4) {
		visivel = false;
		relogio.restart();
	}
}

const bool Entidades::Obstaculos::Espinhos::getVisivel() const{
	return visivel;
}

void Entidades::Obstaculos::Espinhos::Inicializa() {
	Textura.loadFromImage(Grafico->getImagem(getId()));
	Imagem.setTexture(Textura);
	Imagem.setScale(0.25, 0.25);
}