
#pragma once
#include "Gerenciador_Grafico.h"
#include "Gerenciador_Eventos.h"
#include "ListaEntidades.h"
#include "Deserto.h"
#include "Floresta.h"
//#include "Menu.h"
#include <iostream>

enum EstadoJogo {
	MENU = 0,
	FASE1 = 1,
	FASE2 = 2,
};

class Menu;

class Principal{
private:
	Gerenciadores::Gerenciador_Grafico GGrafico;
	Gerenciadores::Gerenciador_Eventos GEventos;
	Fases::Deserto* Segunda_fase;
	Fases::Floresta* Primeira_fase;
	Menu* menu;
	EstadoJogo estadoJogo;
	Entidades::Personagens::Jogador Primeiro, Segundo;

public:
	Principal();
	~Principal();
	 
	Gerenciadores::Gerenciador_Grafico* getGrafico();
	void Executar();
	void verifica_estado();
	void Inicializar();
};

