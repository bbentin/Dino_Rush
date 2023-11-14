#include "../Cabecalhos/Menu.h"

Menu::Menu(EstadoJogo* estado) :Ente(13), fonte(), estadoJogo(estado)
{
	fonte.loadFromFile("Imagens/Texto/PressStart2P-Regular.ttf");
	textos[0].setString("Fase 1");
	textos[1].setString("Fase 2");
	textos[2].setString("Ranking");
	textos[3].setString("Opcoes");
	textos[4].setString("Sair");
	for (int i = 0; i < 5; i++)
	{
		textos[i].setFont(fonte);
		//textos[i].setColor(sf::Color::Red);
		textos[i].setPosition(sf::Vector2f(100, (i + 1) * 100));
	}
	selected = 0;
	textos[selected].setOutlineThickness(5);
}

Menu::~Menu() {

}

int Menu::Menu_Principal() {
	/*fonte.loadFromFile("Imagens/Texto/PressStart2P-Regular.ttf");
	options = { "Fase 1", "Fase 2", "Ranking", "Opcoes", "Sair" };
	textos.resize(5);
	coords = { {100, 100}, {100, 200}, {100, 300}, {100, 400}, {100, 500} };
	sizes = { 50, 50, 50, 50, 50 };
	for (std::size_t i{}; i < textos.size(); i++)
	{
		textos[i].setFont(fonte);
		textos[i].setString(options[i]);
		textos[i].setCharacterSize(sizes[i]);
		textos[i].setOutlineColor(sf::Color::Black);
		textos[i].setPosition(coords[i]);
	}
	sf::Event event;
	while (Grafico->getTela()->pollEvent(event))
	{
		textos[pos].setOutlineThickness(5);
		if (event.type == sf::Event::Closed)
		{
			Grafico->getTela()->close();
			return false;
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && !pressed && pos < 4)
		{
			pos++;
			pressed = true;
			textos[pos].setOutlineThickness(5);
			textos[pos - 1].setOutlineThickness(0);
			pressed = false;
			select = false;
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && !pressed && pos > 0)
		{
			pos--;
			pressed = true;
			textos[pos].setOutlineThickness(5);
			textos[pos + 1].setOutlineThickness(0);
			pressed = false;
			select = false;
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter) && !select)
		{
			select = true;
			switch (pos)
			{
			case 4:
				Grafico->getTela()->close();
				break;
			case 0:
				Menu_Select_Fase();
				break;
			case 1:
				Menu_Select_Fase();
				break;
			case 2:
				//Ranking ranking;
				//ranking.run();
				break;
			case 3:
				//Opcoes opcoes;
				//opcoes.run();
				break;
			}
			return pos;
		}
	}*/
	return 0;
}

int Menu::Menu_Jogo() {
	return 0;
}

int Menu::Menu_Select_Fase() {
	return 0;
}

void Menu::Menu_Salvar() {
}

void Menu::executar() {
	/*desenhar();
	for (auto t : textos) {
		Grafico->getTela()->draw(t);
	}
	*estadoJogo = static_cast<EstadoJogo>(Menu_Principal());*/
}

void Menu::inicializar()
{
	Textura.loadFromImage(Grafico->getImagem(getId()));
	Imagem.setTexture(Textura);
}

void Menu::Desenhar() {
	desenhar();
	for (auto t : textos) {
		Grafico->getTela()->draw(t);
	}
}

void Menu::MoveUp() {
	if (selected - 1 >= 0)
	{
		//textos[selected].setColor(sf::Color::Red);
		textos[selected].setOutlineThickness(0);
		selected--;
		//textos[selected].setColor(sf::Color::Blue);
	}
}

void Menu::MoveDown() {
	if (selected + 1 < MAX_NUMBER_OF_ITEMS)
	{
		//textos[selected].setColor(sf::Color::Red);
		textos[selected].setOutlineThickness(0);
		selected++;
		//textos[selected].setColor(sf::Color::Blue);
	}
}
