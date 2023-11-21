#include "../Cabecalhos/Floresta.h"

Fases::Floresta::Floresta() :Fase(14, 1), pos_Espinhos{3,25,10,15,20}, pos_Lamas{10,20,30,40,50},
pos_Gosmas{10,20,45,58,32}, pos_Moscas{15,30,45,51,59} {
	srand(time(NULL));
	num_Moscas = 3 + rand() % 3;	num_Espinhos = rand() % 3 + 3;
	num_Gosmas = 3 + rand() % 3;	num_Lamas = rand() % 3 + 3;
	cout << "Moscas: " << num_Moscas << " Gosmas: " << num_Gosmas <<  endl;

	gerar_fase(k_fase);
}

Fases::Floresta::~Floresta(){
	
}

void Fases::Floresta::executar(){
	desenhar();
	LEs.executar();
	VerificaMortos();
	G_Colisoes.executar();
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
		num_inimigos++;
	}
}

void Fases::Floresta::CriarGosmas(){
	for (int i = 0; i < num_Gosmas; i++) {
		Gosma* pGosma = new Gosma(); pGosma->setPosi(pos_Gosmas[i] * 16,altura_spawn_inimigos);
		G_Colisoes.addInimigo(static_cast<Inimigo*>(pGosma));
		LEs.InserirEntidade(static_cast<Entidade*> (pGosma));
		num_inimigos++;
	}
}

void Fases::Floresta::CriarObstaculos() {
	CriarEspinhos();
	CriarLamas();
}

void Fases::Floresta::CriarEspinhos(){
	for (int i = 0; i < num_Espinhos ; i++) {
		Espinhos* pEspinhos = new Espinhos(); pEspinhos->setPosi(pos_Gosmas[i] * 16, altura_spawn_obstaculos);
		G_Colisoes.addObstaculo(static_cast<Obstaculo*>(pEspinhos));
		LEs.InserirEntidade(static_cast<Entidade*> (pEspinhos));
	}
}

void Fases::Floresta::CriarLamas(){
	for (int i = 0; i < num_Lamas; i++) {
		Lama* pLama = new Lama(); pLama->setPosi(pos_Lamas[i] * 16, altura_spawn_obstaculos);
		G_Colisoes.addObstaculo(static_cast<Obstaculo*>(pLama));
		LEs.InserirEntidade(static_cast<Entidade*> (pLama));
	}
}

void Fases::Floresta::Inicializa() {
	ativa = true;

	Textura.loadFromImage(Grafico->getImagem(getId()));
	Imagem.setTexture(Textura);
	CriarObstaculos();
	CriarInimigos();
	LEs.Inicializar();
	G_Colisoes.addJogador(Player1);
	G_Colisoes.addJogador(Player2);
	Player1->setPosi(500, 500);
	Player1->setNoAr(true);
	if (Entidades::Personagens::Jogador::getJogador2()) {
		Player2->setPosi(500, 500);
		Player2->setNoAr(true);
	}
}

void Fases::Floresta::salvar(){
}

