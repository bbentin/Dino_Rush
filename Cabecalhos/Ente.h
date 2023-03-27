#pragma once
#include "SFML/Graphics.hpp"
#include <iostream>
#include "Gerenciador_Grafico.h"
using namespace std;

class Ente{
protected:

	int id;
	sf::Sprite corpo;
	Gerenciadores::Gerenciador_Grafico* Grafico;
	const sf::Vector2f Nulo2f;

public:

	Ente();
	~Ente();

	virtual void incializar() = 0;
	virtual void executar() = 0;
	void set_Gerenciador(Gerenciadores::Gerenciador_Grafico* gerenciador);
};

