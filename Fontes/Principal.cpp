#include "../Cabecalhos/Principal.h"
#include "../Cabecalhos/Menu.h"
#include "../Cabecalhos/Ranking.h"

Principal::Principal() :GGrafico(), Primeiro(), Segundo(), Primeira_fase(nullptr), Segunda_fase(nullptr){
	Ente::setGerenciador(&GGrafico);
	GEventos.Singleton();
	menu_principal = new Menu(false);
	menu_pause = new Menu(true);
	GEventos.setTela(GGrafico.getTela());
	GEventos.setJogador(&Primeiro);
	GEventos.setJogador(&Segundo);
	GEventos.setMenu(menu_principal);
	GEventos.setMenu(menu_pause);
}
Principal::~Principal() {
}
Gerenciadores::Gerenciador_Grafico* Principal::getGrafico() {
	return &GGrafico;
}

void Principal::Executar() {
	//GEventos.setState(0);
	while (GGrafico.getTela()->isOpen()) {
		GGrafico.Limpar_Tela();
		GEventos.executar();
		if(GEventos.getstate() == 0){ menu_principal->executar();}

		if (GEventos.getstate() == 1) {
			if (Primeira_fase == nullptr) {
				Primeira_fase = new Fases::Floresta();
				Primeira_fase->setJogador(&Primeiro);
				Primeira_fase->setJogador(&Segundo);
				Primeira_fase->Inicializa();
			}else {
				Primeira_fase->executar();
				if (Primeira_fase->verificaFinal()) {
					Primeira_fase = nullptr;
					delete Primeira_fase;
					Primeiro.Reseta_Vidas();
					Segundo.Reseta_Vidas();
					//menu->reset();
					GEventos.finaliza_atual();
				}
			}
		}
		else if (GEventos.getstate() == 2) {
			if (Segunda_fase == nullptr) { 
				Segunda_fase = new Fases::Deserto(); 
				Segunda_fase->setJogador(&Primeiro);
				Segunda_fase->setJogador(&Segundo);
				Segunda_fase->Inicializa();
			}
			else {
				Segunda_fase->executar();
				if (Segunda_fase->verificaFinal()) {
					Segunda_fase = nullptr;
					delete Segunda_fase;
					Primeiro.Reseta_Vidas();
					Segundo.Reseta_Vidas();
					//menu->reset();
					GEventos.finaliza_atual();
				}
			}
		}
		else if (GEventos.getstate() == 3) {
			//GEventos.setState(3);
			//ranking->executar();
		}
		else if (GEventos.getstate() == 5) {
			menu_pause->executar();
			if (menu_pause->isPressed()) {
				switch (menu_pause->GetItem()) {
				case 1:
					if (GEventos.getstate() == 1) {
						Primeira_fase->salvar();
					}
					else if (GEventos.getstate() == 2) {
						Segunda_fase->salvar();
					}
					menu_pause->setPressed(false);
					GEventos.finaliza_atual();
					break;
				case 2:
					menu_pause->setPressed(false);
					GEventos.finaliza_atual();
					break;
				case 3:
					menu_pause->setPressed(false);
					GEventos.finaliza_atual();
					GEventos.finaliza_atual();
					break;
				case 4:
					menu_pause->setPressed(false);
					GGrafico.getTela()->close();
				default:
					break;
				}
			}
		}
		else if (GEventos.getstate() == 4) {
			GGrafico.getTela()->close();
		}
		GGrafico.Exibir();
	}
}
