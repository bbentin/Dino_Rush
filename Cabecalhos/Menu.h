#pragma once
#include "Ente.h"
#include "Principal.h"
#include <vector>

#define MAX_NUMBER_OF_ITEMS 5

class Menu :
	public Ente {

private:
	sf::Font fonte;
	int selected;
	bool pressed;
	sf::Text textos[MAX_NUMBER_OF_ITEMS];
	Gerenciadores::Gerenciador_Eventos* ge;

public:
	Menu(Gerenciadores::Gerenciador_Eventos* pGE);
	~Menu();

	void executar();
	void inicializar();
	void Desenhar();
	void MoveUp();
	void MoveDown();
	void reset();
	void setGerenciador(Gerenciadores::Gerenciador_Eventos* pGE) { ge = pGE; }
	int GetItem() { return selected; }
	void setPressed(bool press) { pressed = press; }
	bool isPressed() { return pressed; }
	sf::Font getFonte() { return fonte; }
};

