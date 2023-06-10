#include "../Cabecalhos/Floresta.h"

Fases::Floresta::Floresta() :Fase(11, 1), pos_Cactos{3,25}, pos_Gosmas{10,20,45,58,32}, pos_Moscas{15,30,49,51,60} {
	num_Gosmas = rand() % 5 + 3;
	num_Moscas = rand() % 5 + 3;
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
