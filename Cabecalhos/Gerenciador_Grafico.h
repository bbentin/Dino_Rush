#pragma once
#include "./SFML/Graphics.hpp"
namespace Gerenciadores {
	class Gerenciador_Grafico {
	private:
		sf::RenderWindow Tela;
		sf::Image Jogador1, Jogador2, Inimigo1, Inimigo2, Caverna,
				  Inimigo3, Obstaculo1, Obstaculo2, Projetil, Menu;
	public:

		Gerenciador_Grafico();
		~Gerenciador_Grafico();
		void Gerar_Jogador();
		void Gerar_Inimigos();
		void Gerar_Obstaculos();
		void Gerar_Projetil();
		void Gerar_Menu();
		void DesenharEnte(sf::Sprite sprite);
		void Exibir();
		void Limpar_Tela();
		void Fecha_Tela();
		sf::RenderWindow* getTela();

		

	};
}

