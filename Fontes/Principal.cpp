#include "../Cabecalhos/Principal.h"

Principal::Principal():GGrafico(), Primeiro(), Segundo(){
	Primeira_fase = nullptr;
	Ente::setGerenciador(&GGrafico);
	GEventos.Singleton();
	GEventos.setTela(GGrafico.getTela());
	GEventos.setJogador(&Primeiro); GEventos.setJogador(&Segundo);
	Primeiro.Inicializa();
	Primeira_fase = new Fases::Deserto();
	Primeira_fase->setJogador(&Primeiro);
	Primeira_fase->Inicializa();
}
Principal::~Principal() {
}
Gerenciadores::Gerenciador_Grafico* Principal::getGrafico(){
	return &GGrafico;
}

void Principal::Executar() {
	while (true) {
		GGrafico.Limpar_Tela();
		GEventos.executar_fases();
		Primeira_fase->executar();
		GGrafico.Exibir();
	}
}

