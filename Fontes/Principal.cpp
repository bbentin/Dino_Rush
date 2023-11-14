#include "../Cabecalhos/Principal.h"
#include "../Cabecalhos/Menu.h"

Principal::Principal() :GGrafico(), Primeiro(), Segundo(), Primeira_fase(nullptr), Segunda_fase(nullptr), estadoJogo(EstadoJogo::MENU), menu(nullptr) {
	Ente::setGerenciador(&GGrafico);
	GEventos.Singleton();
	GEventos.setTela(GGrafico.getTela());
	GEventos.setJogador(&Primeiro);
	GEventos.setJogador(&Segundo);
	menu = new Menu(&estadoJogo);
	menu->inicializar();
	Primeira_fase = new Fases::Floresta();
	//	Segunda_fase = new Fases::Deserto();
	Primeira_fase->setJogador(&Primeiro);
	Primeira_fase->setJogador(&Segundo);
	//	Segunda_fase->setJogador(&Primeiro);
	Primeira_fase->Inicializa();
	//	Segunda_fase->Inicializa();
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
		menu->Desenhar();
		sf::Event evento{};

		// Verifique o estado do jogo
		switch (estadoJogo)
		{
		case EstadoJogo::MENU:
			switch (evento.type) {
			case sf::Event::KeyReleased:
				switch (evento.key.code) {
				case sf::Keyboard::Up:
					menu->MoveUp();
					break;
				case sf::Keyboard::Down:
					menu->MoveDown();
					break;

				case sf::Keyboard::Return:
					switch (menu->GetPressedItem()) {
					case 0:
						estadoJogo = EstadoJogo::FASE1;
						break;
					case 1:
						estadoJogo = EstadoJogo::FASE2;
						break;
					case 2:
						//estadoJogo = EstadoJogo::RANKING;
						break;
					case 3:
						//estadoJogo = EstadoJogo::OPCOES;
						break;
					case 4:
						GGrafico.Fecha_Tela();
						break;
					}
					break;
				}
			}
			break;

		case EstadoJogo::FASE1:
			GEventos.executar();
			Primeira_fase->executar();
			break;

			// Adicione casos para outros estados conforme necessário

		default:
			// Trate outros estados aqui
			break;
		}

		GGrafico.Exibir();
	}
}

void Principal::verifica_estado() {
}

void Principal::Inicializar() {
}

