#pragma once
#include "SFML/System.hpp"
#include "Jogador.h"

class Menu;

namespace Gerenciadores {
	class Gerenciador_Eventos {

	private:
		Gerenciador_Eventos* Unico;
		Entidades::Personagens::Jogador* Jogador1;
		Entidades::Personagens::Jogador* Jogador2;
		Menu* menu;

		sf::RenderWindow* PTela;
		int state;
	public:

		~Gerenciador_Eventos();
		Gerenciador_Eventos();
		Gerenciador_Eventos* Singleton();
		void setTela(sf::RenderWindow* Tela);
		void executar();
		void setJogador(Entidades::Personagens::Jogador* Player);
		void setMenu(Menu* menu) { this->menu = menu; }
		int getstate();
		void setState(int s) { state = s; }
	};

}
