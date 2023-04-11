#include "../Cabecalhos/Ente.h"

Ente::Ente():id(0),Nulo2f(0.0, 0.0) {
	corpo.setColor(sf::Color::Cyan);
	Grafico = nullptr;
}

Ente::~Ente(){
	Grafico = nullptr;
}

void Ente::imprimirse() {
	Grafico->Imprimir(corpo);
}

void Ente::setGerenciador(Gerenciadores::Gerenciador_Grafico* Gra){
	Grafico = Gra;
}
