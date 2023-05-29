#include "../Cabecalhos/Ente.h"

Ente::Ente(const int i):id(i),Nulo2f(0.0, 0.0) {
}

Ente::~Ente(){
	Grafico = nullptr;
}

void Ente::desenhar() {
	Grafico->DesenharEnte(getSprite());
}

sf::Sprite Ente::getSprite(){
	return Imagem;
}


void Ente::setGerenciador(Gerenciadores::Gerenciador_Grafico* Gra){
	Grafico = Gra;
}

const int Ente::getId() {
	return id;
}

Gerenciadores::Gerenciador_Grafico* Ente::Grafico = nullptr;