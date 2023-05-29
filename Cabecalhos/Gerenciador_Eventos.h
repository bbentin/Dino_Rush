#pragma once
#include "SFML/System.hpp"
#include "Jogador.h"

namespace Gerenciadores {
	class Gerenciador_Eventos {

	private:
		Gerenciador_Eventos* Unico;
		Entidades::Personagens::Jogador* Jogador1;
		Entidades::Personagens::Jogador* Jogador2;
		sf::RenderWindow* PTela;
		sf::Event evento;
	public:

		~Gerenciador_Eventos();
		Gerenciador_Eventos();
		Gerenciador_Eventos* Singleton();
		void Leitura_teclado();
		void setTela(sf::RenderWindow* Tela);
		void executar_fases();
		void executar_menu();
		void setJogador(Entidades::Personagens::Jogador* Player);
	};

}
