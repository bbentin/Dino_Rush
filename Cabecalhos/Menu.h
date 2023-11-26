#pragma once
#include "Ente.h"
#include <vector>

#define MAX_NUMBER_OF_ITEMS 5

class Menu :
	public Ente {

private:
	const bool pause;
	sf::Font fonte;
	int selected;
	bool pressed;
	sf::Text textos[MAX_NUMBER_OF_ITEMS];

public:
	Menu(bool stop = false);
	~Menu();

	void executar();
	void Desenhar();
	void Inicializa();
	void MoveUp();
	void MoveDown();
	void reset();
	int GetItem() { return selected; }
	void setPressed(bool press) { pressed = press; }
	bool isPressed() { return pressed; }
	const bool getPause();
	sf::Font getFonte();
};

