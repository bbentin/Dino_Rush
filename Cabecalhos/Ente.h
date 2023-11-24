#pragma once
#include "SFML/Graphics.hpp"
#include "Gerenciador_Grafico.h"
#include <iostream>

class Ente{
private:

protected:
	const int id;
	sf::Sprite Imagem;
	const sf::Vector2f Nulo2f;
	sf::Texture Textura;
	static Gerenciadores::Gerenciador_Grafico* Grafico;

public:

	Ente(const int i = 0);
	virtual ~Ente();

	virtual void executar() = 0;
	const int getId() const;
	void desenhar();
	sf::Sprite getSprite();
	static void setGerenciador(Gerenciadores::Gerenciador_Grafico* Gra);
	virtual void Inicializa();
};

