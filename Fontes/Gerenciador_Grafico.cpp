#include "../Cabecalhos/Gerenciador_Grafico.h"

Gerenciadores::Gerenciador_Grafico::Gerenciador_Grafico():Tela(sf::VideoMode(900,900),"Jogo") {
	Gerar_Inimigos();	Gerar_Menu();	Gerar_Jogador();	Gerar_Obstaculos(); Gerar_Projetil();
}
Gerenciadores::Gerenciador_Grafico::~Gerenciador_Grafico() {
}

void Gerenciadores::Gerenciador_Grafico::Gerar_Jogador(){
}

void Gerenciadores::Gerenciador_Grafico::Gerar_Inimigos(){
}

void Gerenciadores::Gerenciador_Grafico::Gerar_Obstaculos(){
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
