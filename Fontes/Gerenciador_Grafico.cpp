#include "../Cabecalhos/Gerenciador_Grafico.h"
Gerenciadores::Gerenciador_Grafico::Gerenciador_Grafico():Tela(sf::VideoMode(1504,928),"Jogo"),
Jogador1() {
	Gerar_Inimigos();	Gerar_Menu();	Gerar_Jogador();	Gerar_Obstaculos(); Gerar_Projetil();	Gerar_Fases();
}
Gerenciadores::Gerenciador_Grafico::~Gerenciador_Grafico() {
}

void Gerenciadores::Gerenciador_Grafico::Gerar_Jogador(){
	Jogador1.loadFromFile("C:/Users/rbben/Documents/Projetos/Jogo_C++/Jogo/Jogo_Simao/Imagens/Jogador/Dino1_estatico.png");
}

void Gerenciadores::Gerenciador_Grafico::Gerar_Inimigos(){
	Decapitado.loadFromFile("Imagens/Inimigos/Decapitado/Decapitado.png");
	Mosca.loadFromFile("Imagens/Inimigos/Mosca/Mosca.png");
	Chefao.loadFromFile("Imagens/Inimigos/Chefao/Chefao.png");
}

void Gerenciadores::Gerenciador_Grafico::Gerar_Obstaculos(){
	Chao_Deserto.loadFromFile("Imagens/Obstaculos/Chao_Deserto/Chao_Deserto.png");
	Chao_Floresta.loadFromFile("Imagens/Obstaculos/Chao_Floresta/Chao_Floresta.png");
	Espinhos.loadFromFile("Imagens/Obstaculos/Espinhos/Espinhos.png");
	Lama.loadFromFile("Imagens/Obstaculos/Lama/Lama.png");
}

void Gerenciadores::Gerenciador_Grafico::Gerar_Fases() {
	Deserto.loadFromFile("Imagens/Fase/Deserto/Deserto.png");
	Deserto.loadFromFile("Imagens/Fase/Floresta/Floresta.png");
}

void Gerenciadores::Gerenciador_Grafico::Gerar_Menu() {
}

void Gerenciadores::Gerenciador_Grafico::Gerar_Projetil() {

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

void Gerenciadores::Gerenciador_Grafico::Fecha_Tela(){
	Tela.close();
}

sf::RenderWindow* Gerenciadores::Gerenciador_Grafico::getTela(){
	return &Tela;
}

sf::Image Gerenciadores::Gerenciador_Grafico::getImagem(int identificacao){

	switch (identificacao){
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
		return Decapitado;
			break;
	case 5:
		return Mosca;
			break;
	case 6:
		return Chefao;
			break;
	case 7:
		return Espinhos;
			break;
	case 8:
		return Lama;
			break;
	case 9:
		return Chao_Deserto;
			break;
	case 10:
		return Chao_Floresta;
			break;
	case 11:
		return Deserto;
			break;
	case 12:
		return Floresta;
			break;
	case 13:
		return Projetil;
		break;
	case 14:
		return Menu;
		break;
	default:
		break;
	}

}
