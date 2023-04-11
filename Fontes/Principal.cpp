#include "../Cabecalhos/Principal.h"

Principal::Principal() :relogio_global(), GGrafico() {
	Ente::setGerenciador(getGrafico());
}
Principal::~Principal() {
}

sf::Clock* Principal::getRelogio() {
	return &relogio_global;
}

Gerenciadores::Gerenciador_Grafico* Principal::getGrafico(){
	return &GGrafico;
}


