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
	GEstados.get_instancia();
	menu = new Menu();
	ranking = new Ranking();
	ranking->carregar();
	Inicializar();
}

Principal::~Principal() {
}

Gerenciadores::Gerenciador_Grafico* Principal::getGrafico() {
	return &GGrafico;
}

void Principal::Executar() {
	while (GGrafico.getTela()->isOpen()) {
		GGrafico.Limpar_Tela();
		GEstados.executar();

		menu->executar();
		selected = menu->GetItem();
		pressed = menu->isPressed();
		if (selected == 0 && pressed) {
			if (Primeira_fase == nullptr) {
				Primeira_fase = new Fases::Floresta();
				Primeira_fase->setJogador(&Primeiro);
				Primeira_fase->setJogador(&Segundo);
				Primeira_fase->Inicializa();
			}
			else {
				GEventos.executar();
				Primeira_fase->executar();
				if (Primeira_fase->verificaFinal()) {
					Primeira_fase = nullptr;
					delete Primeira_fase;
					menu->reset();
				}
			}
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
				if (Segunda_fase->verificaFinal()) {
					Segunda_fase = nullptr;
					delete Segunda_fase;
					menu->reset();
				}
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
}