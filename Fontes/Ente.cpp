#include "../Cabecalhos/Ente.h"

Ente::Ente():id(0),Nulo2f(0.0, 0.0) {
	corpo.setColor(sf::Color::Cyan);
	Grafico = nullptr;
}

Ente::~Ente(){
}
void Ente::set_Gerenciador(Gerenciadores::Gerenciador_Grafico* gerenciador){
	Grafico = gerenciador;
}
