#pragma once
#include "Ente.h"
#include <vector>

#define MAX_NUMBER_OF_ITEMS 5

class Menu :
	public Ente {

private:
	const int tipo;
	sf::Font fonte;
	int selected;
	bool pressed;
	sf::Text textos[MAX_NUMBER_OF_ITEMS];

public:
	Menu(int type = 0);
	~Menu();

	void executar();
	void Desenhar();
	void Inicializa();
	void MoveUp();
	void MoveDown();
	void reset();
	int GetItem();
	void setPressed(bool press);
	bool isPressed();
	const int getType();
	sf::Font getFonte();
	void setNome(std::string nome);
	std::string getNome();
};

