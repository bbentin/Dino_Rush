
#pragma once
#include "Gerenciador_Grafico.h"
#include "Gerenciador_Eventos.h"
#include "Gerenciador_Estados.h"
#include "ListaEntidades.h"
#include "Deserto.h"
#include "Floresta.h"
//#include "Menu.h"
//#include "Ranking.h"
#include <iostream>

class Menu;
class Ranking;

class Principal {
private:
	Gerenciadores::Gerenciador_Grafico GGrafico;
	Gerenciadores::Gerenciador_Eventos GEventos;
	Gerenciadores::Gerenciador_Estados GEstados;
	Fases::Deserto* Segunda_fase;
	Fases::Floresta* Primeira_fase;
	Menu* menu;
	Ranking* ranking;
	int selected;
	bool pressed;
	Entidades::Personagens::Jogador Primeiro, Segundo;

public:
	Principal();
	~Principal();

	Gerenciadores::Gerenciador_Grafico* getGrafico();
	void Executar();
	void verifica_estado();
	void Inicializar();
};

