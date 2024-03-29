#include "../Cabecalhos/Menu.h"

Menu::Menu(int type):Ente(13),tipo(type), fonte(), pressed(false), selected(1){
	Inicializa();
}

Menu::~Menu() {

}

void Menu::executar() {
	if (!pressed){
		Desenhar();
	}
}

void Menu::Inicializa(){
	if (tipo == 0) {
		Textura.loadFromImage(Grafico->getImagem(getId()));
		Imagem.setTexture(Textura);
		fonte.loadFromFile("Imagens/Texto/PressStart2P-Regular.ttf");
		textos[0].setString("Dino Rush");
		textos[1].setString("Fase 1");
		textos[2].setString("Fase 2");
		textos[3].setString("Ranking");
		textos[4].setString("Sair");
		
		for (int i = 0; i < 5; i++){
			textos[i].setFont(fonte);
			textos[i].setFillColor(sf::Color::Green);
			textos[i].setOutlineColor(sf::Color::Black);
			textos[i].setOutlineThickness(2);
			textos[i].setPosition(sf::Vector2f(100, (i + 1) * 100));
		}
		textos[1].setFillColor(sf::Color::Red);
		textos[1].setOutlineThickness(4);
	}
	if (tipo == 1) {
		Textura.loadFromImage(Grafico->getImagem(getId()));
		Imagem.setTexture(Textura);
		fonte.loadFromFile("Imagens/Texto/PressStart2P-Regular.ttf");
		textos[0].setString("Menu Pause");
		textos[1].setString("Salvar");
		textos[2].setString("Sair do pause");
		textos[3].setString("Voltar ao menu");
		textos[4].setString("Fechar o Jogo");

		for (int i = 0; i < 5; i++) {
			textos[i].setFont(fonte);
			textos[i].setFillColor(sf::Color::Green);
			textos[i].setOutlineColor(sf::Color::Black);
			textos[i].setOutlineThickness(2);
			textos[i].setPosition(sf::Vector2f(100, (i + 1) * 100));
		}
		textos[1].setFillColor(sf::Color::Red);
		textos[1].setOutlineThickness(4);
	}
	if (tipo == 2)
	{
		Textura.loadFromImage(Grafico->getImagem(getId()));
		Imagem.setTexture(Textura);
		fonte.loadFromFile("Imagens/Texto/PressStart2P-Regular.ttf");
		textos[0].setString("Digite o nome da dupla:");
		// seta string vazia que vai ler o valor digitado:
		textos[1].setString("");
		textos[2].setString("Confirmar");
		textos[3].setString("Voltar");
		textos[4].setString("Sair sem salvar");
		for (int i = 0; i < 5; i++) {
			textos[i].setFont(fonte);
			textos[i].setFillColor(sf::Color::Green);
			textos[i].setOutlineColor(sf::Color::Black);
			textos[i].setOutlineThickness(2);
			textos[i].setPosition(sf::Vector2f(100, (i + 1) * 100));
		}
		textos[1].setFillColor(sf::Color::Red);
		textos[1].setOutlineThickness(4);
	}
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
}

void Menu::reset(){
	pressed = false;
	textos[selected].setOutlineThickness(2);
	textos[selected].setFillColor(sf::Color::Green);
	selected = 1;
	textos[1].setOutlineThickness(4);
	textos[1].setFillColor(sf::Color::Red);
}

int Menu::GetItem(){
	return selected;
}

void Menu::setPressed(bool press){
	pressed = press;
}

bool Menu::isPressed(){
	return pressed;
}

const int Menu::getType(){
	return tipo;
}


sf::Font Menu::getFonte(){
	return fonte;
}

void Menu::setNome(std::string nome) {
	if (tipo == 2) {
		textos[1].setString(nome);
	}
}

std::string Menu::getNome() {
	if (tipo == 2) {
		return textos[1].getString();
	}
}
