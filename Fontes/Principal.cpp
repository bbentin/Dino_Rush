#include "../Cabecalhos/Principal.h"

Principal::Principal():GGrafico(), Primeiro(), Segundo(){
	Primeira_fase = nullptr;
	Ente::setGerenciador(&GGrafico);
	GEventos.Singleton();
	GEventos.setTela(GGrafico.getTela());
	Primeiro.Inicializa();
	GEventos.setJogador(&Primeiro);
	Primeira_fase = new Fases::Floresta();
	Primeira_fase->setJogador(&Primeiro);
	Primeira_fase->Inicializa();
}
Principal::~Principal() {
	delete Primeira_fase;
}
Gerenciadores::Gerenciador_Grafico* Principal::getGrafico(){
	return &GGrafico;
}

void Principal::Executar() {
	while (GGrafico.getTela()->isOpen()) {
			GGrafico.Limpar_Tela();
			GEventos.executar_fases();
			Primeira_fase->executar();
				GGrafico.Exibir();
	}
}

