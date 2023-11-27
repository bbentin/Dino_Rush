#include "../Cabecalhos/Principal.h"
#include "../Cabecalhos/Menu.h"
#include "../Cabecalhos/Ranking.h"

Principal::Principal() : GGrafico(), Primeiro(), Segundo(), Primeira_fase(nullptr), Segunda_fase(nullptr), menu_principal(nullptr), ranking(nullptr),
menu_pause(nullptr),menu_salvar(nullptr){
	Primeiro.setNome("Bruno");
	Ente::setGerenciador(&GGrafico);
	GEventos.Singleton();
	menu_principal = new Menu(0);
	menu_pause = new Menu(1);
	menu_salvar = new Menu(2);
	ranking = new Ranking();
	ranking->Inicializa();
	GEventos.setTela(GGrafico.getTela());
	GEventos.setJogador(&Primeiro);
	GEventos.setJogador(&Segundo);
	GEventos.setMenu(menu_principal);
	GEventos.setMenu(menu_pause);
	GEventos.setMenu(menu_salvar);
}
Principal::~Principal(){
}
Gerenciadores::Gerenciador_Grafico *Principal::getGrafico(){
	return &GGrafico;
}

void Principal::Executar() {
	while (GGrafico.getTela()->isOpen()) {
		GGrafico.Limpar_Tela();
		GEventos.executar();
		if (GEventos.getstate() == 0){
			menu_principal->executar();
		}
		if (GEventos.getstate() == 1){
			if (Primeira_fase == nullptr)
			{
				Primeira_fase = new Fases::Floresta();
				Primeira_fase->setJogador(&Primeiro);
				Primeira_fase->setJogador(&Segundo);
				Primeira_fase->Inicializa();
			}
			else
			{
				Primeira_fase->executar();
				if (Primeira_fase->verificaFinal())
				{
					Primeira_fase = nullptr;
					delete Primeira_fase;
					Primeiro.Reseta_Vidas();
					Segundo.Reseta_Vidas();
					GEventos.finaliza_atual();
				}
			}
		}
		if (GEventos.getstate() == 2){
			if (Segunda_fase == nullptr)
			{
				Segunda_fase = new Fases::Deserto();
				Segunda_fase->setJogador(&Primeiro);
				Segunda_fase->setJogador(&Segundo);
				Segunda_fase->Inicializa();
			}
			else
			{
				Segunda_fase->executar();
				if (Segunda_fase->verificaFinal() || GEventos.getstate() == 0)
				{
					Segunda_fase = nullptr;
					delete Segunda_fase;
					Primeiro.Reseta_Vidas();
					Segundo.Reseta_Vidas();
					GEventos.finaliza_atual();
				}
			}
		}
		if (GEventos.getstate() == 3){						
				ranking->executar();
		}
		if (GEventos.getstate() == 5){
			menu_pause->executar();
		}
		if (GEventos.getstate() == 6){
			
			menu_salvar->executar();
			if (menu_salvar->isPressed()) {
				switch (menu_salvar->GetItem()) {
				case 2:
					GEventos.finaliza_atual();
					GEventos.finaliza_atual();
					Primeiro.setNome(menu_salvar->getNome());
					if (GEventos.getstate() == 2)
					{
						Segunda_fase->salvar();
						ranking->escrever(Primeiro.getNome(), Primeiro.getPontos() + Segundo.getPontos());
					}
					if (GEventos.getstate() == 1) {
						Primeira_fase->salvar();
						ranking->escrever(Primeiro.getNome(), Primeiro.getPontos() + Segundo.getPontos());
					}
					GEventos.finaliza_atual();
					menu_salvar->setPressed(false);
					break;
				case 3:
					menu_salvar->setPressed(false);
					GEventos.finaliza_atual();
					break;
				case 4:
					menu_salvar->setPressed(false);
					GGrafico.Fecha_Tela();
					break;
				default:
					break;
				}
			}
		}
		else if (GEventos.getstate() == 4)
		{
			GGrafico.Fecha_Tela();
		}
		GGrafico.Exibir();
	}
}
