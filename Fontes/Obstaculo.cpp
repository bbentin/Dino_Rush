#include "../Cabecalhos/Obstaculo.h"

Entidades::Obstaculos::Obstaculo::Obstaculo(const int i):Entidade(i){
}

Entidades::Obstaculos:: Obstaculo::~Obstaculo() {
}

void Entidades::Obstaculos::Obstaculo::Inicializa(){
	Textura.loadFromImage(Grafico->getImagem(getId()));
	Imagem.setTexture(Textura);
	if (getId() != 7) {
		Imagem.setScale(0.25, 0.25);
	}
}

void Entidades::Obstaculos::Obstaculo::executar() {

}