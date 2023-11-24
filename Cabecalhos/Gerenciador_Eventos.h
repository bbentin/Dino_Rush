#pragma once
#include "Jogador.h"
#include "Menu.h"

namespace Gerenciadores {

	class Gerenciador_Eventos {

	private:
		Gerenciador_Eventos* Unico;
		Entidades::Personagens::Jogador* Jogador1;
		Entidades::Personagens::Jogador* Jogador2;
		sf::RenderWindow* PTela;
		Menu* menu;
		int state;

	public:

		~Gerenciador_Eventos();
		Gerenciador_Eventos();
		Gerenciador_Eventos* Singleton();
		void setTela(sf::RenderWindow* Tela);
		void executar();
		void setJogador(Entidades::Personagens::Jogador* Player);
		int getstate();
		void setMenu(Menu* men);
		void setState(int s) { state = s; }
	};

}
