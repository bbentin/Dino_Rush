#pragma once
#include <sstream>
#include <fstream>
#include <iostream>
#include <string>
#include "../json.hpp"
#include <vector>
#include <list>
#include "Ente.h"

#define ARQUIVO "Imagens/Ranking/ranking.json"

class Ranking : public Ente
{
private:
	// vetor de pontos
	std::list<std::string> pontos;
	// vetor de nomes
	std::vector<std::string> nomes;
	sf::Text text;
	sf::Font fonte;
	std::ostringstream buffer;

public:
	Ranking();
	~Ranking();

	void carregar();
	void executar();
	void desenha();
	void escrever(std::string nick, int pontuacao);

	void Inicializa();
};