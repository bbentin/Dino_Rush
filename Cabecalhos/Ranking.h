#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include <SFML/Graphics.hpp>
#include "Menu.h"

class Ranking : public Menu
{
private:
	int score;
	char* playerName;

public:
	Ranking();
	~Ranking();

	void setScore(int score);
	int getScore();

	void setPlayerName(char* playerName);
	char* getPlayerName();

	void salvar();
	void carregar();
	void ordenar();
	void executar();
};