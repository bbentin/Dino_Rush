#pragma once
#include "./SFML/Graphics.hpp"
namespace Gerenciadores {
	class Gerenciador_Grafico {
	private:
		sf::RenderWindow Tela;
		sf::Image Jogador1, Jogador2, Mosca, Gosma, Deserto, Floresta, Chao_Floresta, Chao_Deserto, Lama,
			Decapitado, Chefao, Espinhos, Obstaculo2, Projetil, Menu, Gosmona, Moscona, Ranking;
	public:

		Gerenciador_Grafico();
		~Gerenciador_Grafico();

		void Exibir();
		void Fecha_Tela();
		void Gerar_Menu();
		void Gerar_Ranking();
		void Gerar_Fases();
		void Limpar_Tela();
		void Gerar_Jogador();
		void Gerar_Inimigos();
		void Gerar_Projetil();
		void Gerar_Obstaculos();
		sf::RenderWindow* getTela();
		void DesenharEnte(sf::Sprite sprite);
		sf::Image getImagem(int identificador);
	};
}

