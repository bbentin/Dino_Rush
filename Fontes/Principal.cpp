#include "../Cabecalhos/Principal.h"
#include "../Cabecalhos/Menu.h"
#include "../Cabecalhos/Ranking.h"

Principal::Principal() :GGrafico(), Primeiro(), Segundo(), Primeira_fase(nullptr), Segunda_fase(nullptr), menu(nullptr)
{
	Ente::setGerenciador(&GGrafico);
	GEventos.Singleton();
	menu = new Menu();
	GEventos.setTela(GGrafico.getTela());
	GEventos.setJogador(&Primeiro);
	GEventos.setJogador(&Segundo);
	GEventos.setMenu(menu);
	Inicializar();
}
Principal::~Principal() {
}
Gerenciadores::Gerenciador_Grafico* Principal::getGrafico() {
	return &GGrafico;
}

void Principal::Executar() {
	GEventos.setState(0);
	while (GGrafico.getTela()->isOpen()) {
		GGrafico.Limpar_Tela();
		menu->executar();
		GEventos.executar();
		if (menu->GetItem() == 1 && menu->isPressed()) {
			GEventos.setState(1);
			if (Primeira_fase == nullptr) {
				Primeira_fase = new Fases::Floresta();
				Primeira_fase->setJogador(&Primeiro);
				Primeira_fase->setJogador(&Segundo);
				Primeira_fase->Inicializa();
			}else {
				Primeira_fase->executar();
			//	Primeira_fase->salvar();
				if (Primeira_fase->verificaFinal()) {
					Primeira_fase = nullptr;
					delete Primeira_fase;
					Primeiro.Reseta_Vidas();
					Segundo.Reseta_Vidas();
					menu->reset();
					GEventos.setState(0);
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
				Segunda_fase->executar();
				if (Segunda_fase->verificaFinal()) {
					Segunda_fase = nullptr;
					delete Segunda_fase;
					Primeiro.Reseta_Vidas();
					Segundo.Reseta_Vidas();
					menu->reset();
					GEventos.setState(0);
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