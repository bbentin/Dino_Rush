#include "../Cabecalhos/Deserto.h"

Fases::Deserto::Deserto() :Fase(11, 2), pos_Moscas{ 5,15,30,40,50 }, pos_Gosmonas{15,25,36,48,50},pos_Chefao(65),
pos_Lamas{ 10, 20, 25, 30, 40 }, pos_Espinhos{ 15,30,35,40,55 } {
	num_Moscas = rand() % 3 + 3;	num_Gosmonas = rand() % 3 + 3;
	num_Lamas = rand() % 3 + 3;		num_Espinhos = rand() % 3 + 3;
}

Fases::Deserto::~Deserto(){
}

void Fases::Deserto::executar() {
	desenhar();
	LEs.executar();

	G_Colisoes.executar();
	Player1->setIntervalo(relogio_global.restart().asMilliseconds() / 2);
}

void Fases::Deserto::CriarInimigos(){
	CriarMoscas();
	CriarGosmonas();
	CriarChefao();
}

void Fases::Deserto::CriarObstaculos(){
	CriarLamas();
}

void Fases::Deserto::CriarMoscas(){
	for (int i = 0; i < num_Moscas; i++) {
		Mosca* pMosca = new Mosca(); pMosca->setPosi(pos_Moscas[i] * 16, altura_spawn_inimigos);
		G_Colisoes.addInimigo(static_cast<Inimigo*>(pMosca));
		LEs.InserirEntidade(static_cast<Entidade*> (pMosca));
	}
}

void Fases::Deserto::CriarGosmonas(){
	for (int i = 0; i < num_Gosmonas; i++) {
		Gosmona* pGosmona = new Gosmona; pGosmona->setPosi(pos_Gosmonas[i] * 16, altura_spawn_inimigos);
		G_Colisoes.addInimigo(static_cast<Inimigo*>(pGosmona));
		LEs.InserirEntidade(static_cast<Entidade*> (pGosmona));
	}
}

void Fases::Deserto::CriarChefao(){
	Chefao* pChefao = new Chefao(); 	pChefao->setPosi(pos_Chefao* 16,altura_spawn_inimigos);
	Projetil* pArma = new Projetil();	pArma->setDono(static_cast<Entidade*>(pChefao));	pChefao->setArma(pArma);
	G_Colisoes.addInimigo(static_cast<Inimigo*>(pChefao)); G_Colisoes.addProjetil(pArma);
	LEs.InserirEntidade(static_cast<Entidade*> (pChefao));	LEs.InserirEntidade(static_cast<Entidade*>(pArma));
}

void Fases::Deserto::CriarLamas(){
	for (int i = 0; i < num_Lamas; i++) {
		Lama* pLama = new Lama(); 	pLama->setPosi(pos_Lamas[i] * 16, altura_spawn_obstaculos);
		G_Colisoes.addObstaculo(static_cast<Obstaculo*>(pLama));
		LEs.InserirEntidade(static_cast<Entidade*> (pLama));
	}
}

void Fases::Deserto::CriarEspinhos(){
	for (int i = 0; i < num_Espinhos; i++) {
		Espinhos* pEspinhos = new Espinhos();	pEspinhos->setPosi(pos_Espinhos[i] * 16, altura_spawn_obstaculos);
		G_Colisoes.addObstaculo(static_cast<Obstaculo*>(pEspinhos));
		LEs.InserirEntidade(static_cast<Entidade*> (pEspinhos));
	}
}

void Fases::Deserto::Inicializa(){

	Textura.loadFromImage(Grafico->getImagem(getId()));
	Imagem.setTexture(Textura);
	CriarInimigos();
	CriarObstaculos();
	G_Colisoes.addJogador(Player1);
	gerar_fase(k_fase);
	LEs.Inicializar();
	Player1->Inicializa();
	
}
