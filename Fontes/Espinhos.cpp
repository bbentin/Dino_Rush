#include "../Cabecalhos/Espinhos.h"
#include <sstream>

Entidades::Obstaculos::Espinhos::Espinhos(sf::Vector2f pos, int tmp, bool visi, const float limite_alt) :Obstaculo(10, limite_alt), dano(2), relogio(), visivel(visi), tempo(tmp) {
	no_ar = true;
}

Entidades::Obstaculos::Espinhos::~Espinhos() {
}

void Entidades::Obstaculos::Espinhos::executar() {
	brotar();
	if (visivel) {
		desenhar();
	}
	if (getPosicao().y > limite_altura) {
		no_ar = false;
		parar_movimento_y();
	}
	else {
		desenhar();
		Calc_Fisica();
	}
}

void Entidades::Obstaculos::Espinhos::Colisao(Entidade* colidida, sf::Vector2f limites) {
}

void Entidades::Obstaculos::Espinhos::obstacular(Entidade* obstaculada) {
	if (visivel) {
		empurrar(obstaculada);
		static_cast<Entidades::Personagens::Personagem*>(obstaculada)->operator--();
	}
}

void Entidades::Obstaculos::Espinhos::salvar(std::ostringstream* entrada) {
	sf::Vector2f pos = getPosicao();
	(*entrada) << "{ \"id\": [" << getId() << "], \"posicao\": [" << pos.x << "," << pos.y << "], \"visivel\": [" << getVisivel() << "], \"tempo\": [" << tempo << "] }" << endl;
}

void Entidades::Obstaculos::Espinhos::brotar() {

	if (tempo == 2) {
		visivel = true;
	}
	if (tempo == 4) {
		visivel = false;
		relogio.restart();
	}
	tempo = relogio.getElapsedTime().asSeconds();
}

const bool Entidades::Obstaculos::Espinhos::getVisivel() const {
	return visivel;
}

void Entidades::Obstaculos::Espinhos::Inicializa() {
	Textura.loadFromImage(Grafico->getImagem(getId()));
	Imagem.setTexture(Textura);
	Imagem.setScale(0.25, 0.25);
}