#include "../Cabecalhos/Gerenciador_Grafico.h"

Gerenciadores::Gerenciador_Grafico::Gerenciador_Grafico():Tela(sf::VideoMode(900,900),"Jogo") {

}
Gerenciadores::Gerenciador_Grafico::~Gerenciador_Grafico() {
}

void Gerenciadores::Gerenciador_Grafico::Gerar_Jogador(){
}

void Gerenciadores::Gerenciador_Grafico::Gerar_Inimigo(){
}

void Gerenciadores::Gerenciador_Grafico::Gerar_Obstaculo(){
}

void Gerenciadores::Gerenciador_Grafico::Executar() {
	Tela.clear();
	Tela.display();
}

void Gerenciadores::Gerenciador_Grafico::Imprimir(sf::Sprite body) {
	Tela.draw(body);
}