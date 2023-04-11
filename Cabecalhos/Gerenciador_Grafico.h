#pragma once
#include "./SFML/Graphics.hpp"
namespace Gerenciadores {
	class Gerenciador_Grafico {
	private:
		sf::RenderWindow Tela;
		sf::Image Jogador1, Jogador2, Inimigo1, Inimigo2,
				  Inimigo3, Obstaculo1, Obstaculo2, Projetil, Menu;
	public:

		Gerenciador_Grafico();
		~Gerenciador_Grafico();
		void Gerar_Jogador();
		void Gerar_Inimigo();
		void Gerar_Obstaculo();
		void Gerar_Projetil();
		void Gerar_Menu();
		void Imprimir(sf::Sprite body);
		void Executar();

	};
}

