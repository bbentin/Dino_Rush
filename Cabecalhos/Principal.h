#pragma once
#include "Gerenciador_Grafico.h"
#include "Jogador.h"
#include "Gerenciador_Eventos.h"
#include "ListaEntidades.h"
#include "Deserto.h"
#include "Floresta.h"
#include <iostream>
class Principal{
private:
	Gerenciadores::Gerenciador_Grafico GGrafico;
	Gerenciadores::Gerenciador_Eventos GEventos;
	Fases::Deserto* Segunda_fase;
	Fases::Floresta* Primeira_fase;
	Entidades::Personagens::Jogador Primeiro, Segundo;
	enum estado{menu,fase1,fase2,menu_salvar};

public:
	Principal();
	~Principal();

	Gerenciadores::Gerenciador_Grafico* getGrafico();
	void Executar();
};

