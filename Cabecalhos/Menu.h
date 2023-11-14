#pragma once
#include "Ente.h"
#include "Principal.h"
#include <vector>

#define MAX_NUMBER_OF_ITEMS 5

enum EstadoJogo;

class Menu :
	public Ente {

private:
	sf::Font fonte;
	//bool pressed;
	//bool select;
	//int pos;
	int selected;
	sf::Text textos[MAX_NUMBER_OF_ITEMS];
	EstadoJogo* estadoJogo;

	//std::vector<const char*> options;
	//std::vector<sf::Text> textos;
	//std::vector<sf::Vector2f> coords;
	//std::vector<std::size_t> sizes;
public:
	Menu(EstadoJogo* estado);
	~Menu();

	int Menu_Principal();
	int Menu_Jogo();
	int Menu_Select_Fase();
	void Menu_Salvar();
	void executar();
	void inicializar();
	void Desenhar();
	void MoveUp();
	void MoveDown();
	int GetPressedItem() { return selected; }
};

