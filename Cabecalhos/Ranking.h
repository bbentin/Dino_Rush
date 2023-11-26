#pragma once
#include <sstream>
#include <fstream>
#include <iostream>
#include <string>
#include "../json.hpp"
#include <vector>
#include <SFML/Graphics.hpp>
#include "Ente.h"
using namespace std;

#define ARQUIVO "Imagens/Fase/Floresta/entidades.json"
#define ARQUIVO2 "Imagens/Fase/Deserto/entidades.json"

class Ranking : public Ente
{
private:
	// vetor de pontos
	std::vector<string> pontos;
	// vetor de nomes
	std::vector<std::string> nomes;
	sf::Text text;
	sf::Font fonte;

public:
	Ranking();
	~Ranking();

	void carregar();
	void executar();
	void desenha();

	void Inicializa();
};