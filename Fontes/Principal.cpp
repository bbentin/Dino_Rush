#include "../Cabecalhos/Principal.h"

Principal::Principal():GGrafico(), Primeiro(), Segundo(),Primeira_fase(nullptr),Segunda_fase(nullptr),menu(),estado(0){
	Ente::setGerenciador(&GGrafico);
	GEventos.Singleton();
	GEventos.setTela(GGrafico.getTela());
	GEventos.setJogador(&Primeiro);
	Primeira_fase = new Fases::Floresta();
//	Segunda_fase = new Fases::Deserto();
	Primeira_fase->setJogador(&Primeiro);
//	Segunda_fase->setJogador(&Primeiro);
	Primeira_fase->Inicializa();
//	Segunda_fase->Inicializa();
}
Principal::~Principal() {
	delete Primeira_fase;
	delete Segunda_fase;
}
Gerenciadores::Gerenciador_Grafico* Principal::getGrafico(){
	return &GGrafico;
}

void Principal::Executar() {
	while (GGrafico.getTela()->isOpen()) {
		GGrafico.Limpar_Tela();
		GEventos.executar();
		Primeira_fase->executar();
		GGrafico.Exibir();
	}
}

void Principal::verifica_estado(){
}

void Principal::Inicializar(){
}

