#include "../Cabecalhos/Principal.h"
#include "../Cabecalhos/Menu.h"
#include "../Cabecalhos/Ranking.h"

Principal::Principal() :GGrafico(), Primeiro(), Segundo(), Primeira_fase(nullptr), Segunda_fase(nullptr), menu(nullptr), selected(10), pressed(false), ranking()
{
	Ente::setGerenciador(&GGrafico);
	GEventos.Singleton();
	GEventos.setTela(GGrafico.getTela());
	GEventos.setJogador(&Primeiro);
	GEventos.setJogador(&Segundo);
	menu = new Menu();
	ranking = new Ranking();
	ranking->carregar();
	Primeira_fase = new Fases::Floresta();
	Inicializar();
}
Principal::~Principal() {
	delete Primeira_fase;
	delete Segunda_fase;
}
Gerenciadores::Gerenciador_Grafico* Principal::getGrafico() {
	return &GGrafico;
}

void Principal::Executar() {
	while (GGrafico.getTela()->isOpen()) {
		GGrafico.Limpar_Tela();

		menu->executar();
		selected = menu->GetItem();
		pressed = menu->isPressed();
		if (selected == 0 && pressed) {
			if (!Primeira_fase->getAtiva()) { Primeira_fase->Inicializa(); }
			GEventos.executar();
			Primeira_fase->executar();
		}
		else if (selected == 1 && pressed) {
			if (Segunda_fase == nullptr) { 
				Segunda_fase = new Fases::Deserto(); 
				Segunda_fase->setJogador(&Primeiro);
				Segunda_fase->setJogador(&Segundo);
				Segunda_fase->Inicializa();
			}
			else {
				GEventos.executar();
				Segunda_fase->executar();
			}
		}
		else if (selected == 2 && pressed) {
			//ranking->executar();
		}
		else if (selected == 3 && pressed) {
			GGrafico.getTela()->close();
		}
		GGrafico.Exibir();
	}
}

void Principal::verifica_estado() {
}

void Principal::Inicializar() {
	menu->inicializar();
	Primeira_fase->setJogador(&Primeiro);
	Primeira_fase->setJogador(&Segundo);
}