#pragma once
#include "Gerenciador_Grafico.h"
#include "Entidade.h"
class Principal{
private:
	Gerenciadores::Gerenciador_Grafico GGrafico;
	Gerenciadores::Gerenciador_Grafico* teste;
	sf::Clock relogio_global;
public:

	sf::Clock* getRelogio();
	Gerenciadores::Gerenciador_Grafico* getGrafico();
};

