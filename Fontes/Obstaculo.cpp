#include "../Cabecalhos/Obstaculo.h"

Entidades::Obstaculos::Obstaculo::Obstaculo(const int i,const float limite):Entidade(i),limite_altura(limite) {
}

Entidades::Obstaculos:: Obstaculo::~Obstaculo() {
}

void Entidades::Obstaculos::Obstaculo::Inicializa(){
	Textura.loadFromImage(Grafico->getImagem(getId()));
	Imagem.setTexture(Textura);
	if (getId() == 8 || getId() == 9) {
		Imagem.setScale(0.5, 0.25);
	}
	if (getId() == 7) {
		Imagem.setScale(0.5, 0.2);
	}
}
