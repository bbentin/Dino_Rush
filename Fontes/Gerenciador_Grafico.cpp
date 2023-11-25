#include "../Cabecalhos/Gerenciador_Grafico.h"
#include <iostream>
using namespace std;
Gerenciadores::Gerenciador_Grafico::Gerenciador_Grafico() :Tela(sf::VideoMode(1280, 960), "Jogo"),
Jogador1() {
	Tela.setFramerateLimit(200);
	Gerar_Inimigos();	Gerar_Menu();	Gerar_Jogador();	Gerar_Obstaculos(); Gerar_Projetil();	Gerar_Fases(); Gerar_Ranking();
}
Gerenciadores::Gerenciador_Grafico::~Gerenciador_Grafico() {
}

void Gerenciadores::Gerenciador_Grafico::Gerar_Jogador() {
	Jogador1.loadFromFile("Imagens/Jogador/Dino1_estatico.png");
}

void Gerenciadores::Gerenciador_Grafico::Gerar_Inimigos() {
	Decapitado.loadFromFile("Imagens/Inimigos/Decapitado/Decapitado.png");
	Mosca.loadFromFile("Imagens/Inimigos/Mosca/Mosca.png");
	Gosma.loadFromFile("Imagens/Inimigos/Gosma/Gosma.png");
	Chefao.loadFromFile("Imagens/Inimigos/Chefao/Chefao.png");
	Gosmona.loadFromFile("Imagens/Inimigos/Gosmona/Gosmona.png");
	Moscona.loadFromFile("Imagens/Inimigos/Moscona/Moscona.png");
}

void Gerenciadores::Gerenciador_Grafico::Gerar_Obstaculos() {
	Chao_Deserto.loadFromFile("Imagens/Obstaculos/Chao_Deserto/Chao_Deserto.png");
	Chao_Floresta.loadFromFile("Imagens/Obstaculos/Chao_Floresta/Chao_Floresta.png");
	Espinhos.loadFromFile("Imagens/Obstaculos/Espinhos/Espinhos.png");
	Lama.loadFromFile("Imagens/Obstaculos/Lama/Lama.png");
}

void Gerenciadores::Gerenciador_Grafico::Gerar_Fases() {
	Deserto.loadFromFile("Imagens/Fase/Deserto/Deserto.png");
	Floresta.loadFromFile("Imagens/Fase/Floresta/Floresta.png");
}

void Gerenciadores::Gerenciador_Grafico::Gerar_Menu() {
	Menu.loadFromFile("Imagens/Menus/Menu.png");
}

void Gerenciadores::Gerenciador_Grafico::Gerar_Projetil() {
	Projetil.loadFromFile("Imagens/Projetil/Projetil.png");
}

void Gerenciadores::Gerenciador_Grafico::Gerar_Ranking() {
	Ranking.loadFromFile("Imagens/Menus/Ranking.png");
}

void Gerenciadores::Gerenciador_Grafico::DesenharEnte(sf::Sprite sprite) {
	Tela.draw(sprite);
}

void Gerenciadores::Gerenciador_Grafico::Exibir() {
	Tela.display();
}

void Gerenciadores::Gerenciador_Grafico::Limpar_Tela() {
	Tela.clear();
}

void Gerenciadores::Gerenciador_Grafico::Fecha_Tela() {
	Tela.close();
}

sf::RenderWindow* Gerenciadores::Gerenciador_Grafico::getTela() {
	return &Tela;
}

sf::Image Gerenciadores::Gerenciador_Grafico::getImagem(int identificacao) {
	switch (identificacao) {
	case 1:
		return Jogador1;
		break;
	case 2:
		return Jogador2;
		break;
	case 3:
		return Gosma;
		break;
	case 4:
		return Chefao;
		break;
	case 5:
		return Mosca;
		break;
	case 6:
		return Gosmona;
		break;
	case 7:
		return Lama;
		break;
	case 8:
		return Chao_Deserto;
		break;
	case 9:
		return Chao_Floresta;
		break;
	case 10:
		return Espinhos;
		break;
	case 11:
		return Deserto;
		break;
	case 12:
		return Projetil;
		break;
	case 13:
		return Menu;
		break;
	case 14:
		return Floresta;
		break;
	case 15:
		return Ranking;
	default:
		break;
	}

}

