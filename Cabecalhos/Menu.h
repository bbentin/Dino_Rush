#pragma once
#include "Ente.h"
#include "Principal.h"
#include <vector>

#define MAX_NUMBER_OF_ITEMS 4

class Menu :
	public Ente {

private:
	sf::Font fonte;
	int selected;
	bool pressed;
	sf::Text textos[MAX_NUMBER_OF_ITEMS];

public:
	Menu();
	~Menu();

	void executar();
	void inicializar();
	void Desenhar();
	void MoveUp();
	void MoveDown();
	void handleInput(sf::Event evento);
	int GetItem() { return selected; }
	bool isPressed() { return pressed; }
	sf::Font getFonte() { return fonte; }
};

