#pragma once
#include "Gerenciador_Grafico.h"
#include "Gerenciador_Eventos.h"
#include "ListaEntidades.h"
#include "Deserto.h"
#include "Floresta.h"
#include <iostream>

class Principal {
private:
	Gerenciadores::Gerenciador_Grafico GGrafico;
	Gerenciadores::Gerenciador_Eventos GEventos;
	Fases::Deserto* Segunda_fase;
	Fases::Floresta* Primeira_fase;
	Menu* menu;
	Entidades::Personagens::Jogador Primeiro, Segundo;

public:
	Principal();
	~Principal();

	Gerenciadores::Gerenciador_Grafico* getGrafico();
	void Executar();
	void verifica_estado();
	void Inicializar();
};

