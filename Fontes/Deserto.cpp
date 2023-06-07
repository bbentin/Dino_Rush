#include "../Cabecalhos/Deserto.h"

Fases::Deserto::Deserto():Fase(12,2) {
}

Fases::Deserto::~Deserto(){
}

void Fases::Deserto::executar() {
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
	Player1->setIntervalo(relogio_global.restart().asMilliseconds()/2);
}