#include "../Cabecalhos/Ente.h"

Ente::Ente():id(0) {
	corpo.setColor(sf::Color::Cyan);
}

Ente::~Ente() {
}

void Ente::imprimirse() {
	Grafico->Imprimir(corpo);
}
