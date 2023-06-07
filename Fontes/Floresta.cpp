#include "../Cabecalhos/Floresta.h"

Fases::Floresta::Floresta():Fase(11,1) {
}

Fases::Floresta::~Floresta(){
}

void Fases::Floresta::executar(){
	desenhar();
	LEs.executar();
	if (Entidades::Personagens::Jogador::Jogador2) {
		Player1->executar();
		//Player2->executar();
	}
	else {
		Player1->executar();
	}
	G_Colisoes.executar();
	Player1->setIntervalo(relogio_global.restart().asMilliseconds() / 2);
}
