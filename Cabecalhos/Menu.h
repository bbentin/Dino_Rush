#pragma once
#include "Ente.h"
class Menu :
	public Ente{

private:
	int selecao;
	sf::Image Caixa_exibicao;
	sf::Font fonte;
public:
	Menu();
	~Menu();

	int Menu_Principal();
	int Menu_Jogo();
	int Menu_Select_Fase();
	void Menu_Salvar();
};

