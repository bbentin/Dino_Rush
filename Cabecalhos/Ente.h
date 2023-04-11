#pragma once
#include "SFML/Graphics.hpp"
#include <iostream>
#include "Gerenciador_Grafico.h"
using namespace std;

class Ente{
private:
	static Gerenciadores::Gerenciador_Grafico* Grafico;
protected:

	int id;
	sf::Sprite corpo;
	const sf::Vector2f Nulo2f;

public:

	Ente();
	~Ente();

	virtual void incializar() = 0;
	virtual void executar() = 0;
	void imprimirse();
	void static setGerenciador(Gerenciadores::Gerenciador_Grafico* Gra);


};

