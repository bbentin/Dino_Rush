#include "../Cabecalhos/Floresta.h"

Fases::Floresta::Floresta() :Fase(14, 1), pos_Espinhos{3,25,10,15,20}, pos_Lamas{10,20,30,40,50},
pos_Gosmas{10,20,45,58,32}, pos_Moscas{15,30,45,51,59} {
	srand(time(NULL));
	num_Moscas = rand() % 4 + 2;	num_Espinhos = rand() % 3 + 3;
	num_Gosmas = rand() % 4 + 2;	num_Lamas = rand() % 3 + 3;
	gerar_fase(k_fase);
}

Fases::Floresta::~Floresta(){
	
}

void Fases::Floresta::executar(){
	desenhar();
	VerificaMortos();
	G_Colisoes.executar();
	LEs.executar();
	Player1->setIntervalo(relogio_global.restart().asMilliseconds() / 2);
}

void Fases::Floresta::CriarInimigos(){
	CriarMoscas();
	CriarGosmas();
}

void Fases::Floresta::CriarMoscas(){
	for (int i = 0; i < num_Moscas; i++) {
		Mosca* pMosca = new Mosca(); pMosca->setPosi(pos_Moscas[i] * 16,altura_spawn_inimigos);
		G_Colisoes.addInimigo(static_cast<Inimigo*>(pMosca));
		LEs.InserirEntidade(static_cast<Entidade*> (pMosca));
	}
}

void Fases::Floresta::CriarGosmas(){
	for (int i = 0; i < num_Gosmas; i++) {
		Gosma* pGosma = new Gosma(); pGosma->setPosi(pos_Gosmas[i] * 16,altura_spawn_inimigos);
		G_Colisoes.addInimigo(static_cast<Inimigo*>(pGosma));
		LEs.InserirEntidade(static_cast<Entidade*> (pGosma));
	}
}

void Fases::Floresta::CriarObstaculos() {
	//CriarEspinhos();
	//CriarLamas();
}

void Fases::Floresta::CriarEspinhos(){

}

void Fases::Floresta::CriarLamas(){
	for (int i = 0; i < num_Lamas; i++) {
		Lama* pLama = new Lama(); pLama->setPosi(pos_Gosmas[i] * 16, altura_spawn_obstaculos);
		G_Colisoes.addObstaculo(static_cast<Obstaculo*>(pLama));
		LEs.InserirEntidade(static_cast<Entidade*> (pLama));
	}
}

void Fases::Floresta::Inicializa() {

	Textura.loadFromImage(Grafico->getImagem(getId()));
	Imagem.setTexture(Textura);
	CriarObstaculos();
	CriarInimigos();
	G_Colisoes.addJogador(Player1);
	G_Colisoes.addJogador(Player2);
	LEs.Inicializar();
	Player1->Inicializa();
	Player1->setPosi(16, 828);
	if (Entidades::Personagens::Jogador::getJogador2()) {
		Player2->Inicializa();
		Player2->setPosi(64, 828);
	}
}

void Fases::Floresta::salvar(){
}

