#pragma once
#include "SFML/Graphics.hpp"
#include <iostream>
using namespace std;
#include "Gerenciador_Grafico.h"
class Ente{
private:

protected:
	const int id;
	sf::Sprite Imagem;
	const sf::Vector2f Nulo2f;
	static Gerenciadores::Gerenciador_Grafico* Grafico;

public:

	Ente(const int i = 0);
	~Ente();

	virtual void executar() = 0;
	const int getId();
	void desenhar();
	sf::Sprite getSprite();
	static void setGerenciador(Gerenciadores::Gerenciador_Grafico* Gra);

};

