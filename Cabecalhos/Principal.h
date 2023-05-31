#pragma once
#include "Gerenciador_Grafico.h"
#include "Jogador.h"
#include "Gerenciador_Eventos.h"
#include "ListaEntidades.h"
#include "Deserto.h"
#include <iostream>
class Principal{
private:
	Gerenciadores::Gerenciador_Grafico GGrafico;
	Gerenciadores::Gerenciador_Eventos GEventos;
	Fases::Deserto* Primeira_fase;
	Entidades::Personagens::Jogador Primeiro, Segundo;

public:
	Principal();
	~Principal();

	Gerenciadores::Gerenciador_Grafico* getGrafico();
	void Executar();
};

