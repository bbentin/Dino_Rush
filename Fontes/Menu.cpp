#include "../Cabecalhos/Menu.h"

Menu::Menu():Ente(13), fonte(), pressed(false), selected(1)
{
	fonte.loadFromFile("Imagens/Texto/PressStart2P-Regular.ttf");
	textos[0].setString("Dino Rush");
	textos[1].setString("Fase 1");
	textos[2].setString("Fase 2");
	textos[3].setString("Ranking");
	textos[4].setString("Sair");
	for (int i = 0; i < 5; i++)
	{
		textos[i].setFont(fonte);
		textos[i].setFillColor(sf::Color::Green);
		textos[i].setOutlineColor(sf::Color::Black);
		textos[i].setOutlineThickness(2);
		textos[i].setPosition(sf::Vector2f(100, (i + 1) * 100));
	}
	textos[0].setCharacterSize(50);
	textos[0].setOutlineThickness(4);
	textos[1].setOutlineThickness(4);
	textos[1].setFillColor(sf::Color::Red);
}

Menu::~Menu() {

}

void Menu::executar() {
	if (!pressed){
		Desenhar();
	}
}

void Menu::inicializar()
{
	Textura.loadFromImage(Grafico->getImagem(getId()));
	Imagem.setTexture(Textura);
}

void Menu::Desenhar() {
	desenhar();
	for (auto t : textos){
		Grafico->getTela()->draw(t);
	}
}

void Menu::MoveUp() {
	if ((selected - 1) >= 1)
	{
		textos[selected].setFillColor(sf::Color::Green);	
		textos[selected].setOutlineThickness(2);
		selected--;
		textos[selected].setFillColor(sf::Color::Red);
		textos[selected].setOutlineThickness(4);
	}
	Desenhar();
}

void Menu::MoveDown() {
	if ((selected + 1) < MAX_NUMBER_OF_ITEMS)
	{
		textos[selected].setFillColor(sf::Color::Green);
		textos[selected].setOutlineThickness(2);
		selected++;
		textos[selected].setFillColor(sf::Color::Red);
		textos[selected].setOutlineThickness(4);
	}
	Desenhar();
}

void Menu::reset(){
	pressed = false;
	selected = 1;
}
