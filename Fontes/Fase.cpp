#include"../Cabecalhos/Fase.h"

Fases::Fase::Fase(const int i):Ente(i),relogio_global(),G_Colisoes(),LEs(),Primeiro(nullptr),Segundo(nullptr) {

}

Fases::Fase::~Fase() {
}

void Fases::Fase::gerenciar_colisoes(){
	G_Colisoes.executar();
}

void Fases::Fase::setJogador(Entidades::Personagens::Jogador* inserido){
	if (!Primeiro) {
		Primeiro = inserido;
	}
	else if (!Segundo) {
		Segundo = inserido;
	}
}

sf::Clock* Fases::Fase::getRelogio() {
	return &relogio_global;
}

void Fases::Fase::gerar_fase(int num) {	
	std::fstream arquivo;
	if (num == 1) {
	arquivo.open("C:/Users/rbben/Documents/Projetos/Jogo_C++/Jogo/Jogo_Simao/Imagens/Fase/Caverna.txt");
	}
	else if (num == 2) {
	arquivo.open("C:/Users/rbben/Documents/Projetos/Jogo_C++/Jogo/Jogo_Simao/Imagens/Fase/Floresta.txt");
	}
}