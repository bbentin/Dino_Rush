#include "../Cabecalhos/Principal.h"
#include "../Cabecalhos/Menu.h"
#include "../Cabecalhos/Ranking.h"

Principal::Principal() :GGrafico(), Primeiro(), Segundo(), Primeira_fase(nullptr), Segunda_fase(nullptr), menu(nullptr), ranking()
{
	Ente::setGerenciador(&GGrafico);
	GEventos.Singleton();
	GEventos.setTela(GGrafico.getTela());
	GEventos.setJogador(&Primeiro);
	GEventos.setJogador(&Segundo);
	menu = new Menu(&GEventos);
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
		GEventos.setState(0);
		GEventos.setMenu(menu);
		menu->executar();
		if (menu->GetItem() == 1 && menu->isPressed()) {
			GEventos.setState(1);
			if (Primeira_fase == nullptr) {
				Primeira_fase = new Fases::Floresta();
				Primeira_fase->setJogador(&Primeiro);
				Primeira_fase->setJogador(&Segundo);
				Primeira_fase->Inicializa();
			}else {
				GEventos.executar();
				Primeira_fase->executar();
				Primeira_fase->salvar();
				if (Primeira_fase->verificaFinal()) {
					Primeira_fase = nullptr;
					delete Primeira_fase;
					Primeiro.Reseta_Vidas();
					Segundo.Reseta_Vidas();
					menu->reset();
				}
			}
		}
		else if (menu->GetItem() == 2 && menu->isPressed()) {
			GEventos.setState(2);
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
					Primeiro.Reseta_Vidas();
					Segundo.Reseta_Vidas();
					menu->reset();
				}
			}
		}
		else if (menu->GetItem() == 3 && menu->isPressed()) {
			GEventos.setState(3);
			//ranking->executar();
		}
		else if (menu->GetItem() == 4 && menu->isPressed()) {
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