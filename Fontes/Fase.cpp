#include"../Cabecalhos/Fase.h"

Fases::Fase::Fase(const int i, const int k):Ente(i),relogio_global(),G_Colisoes(),LEs(),Player1(nullptr),Player2(nullptr),k_fase(k)
,altura_spawn_inimigos(160),altura_spawn_obstaculos(240) {

}

Fases::Fase::~Fase() {
}

void Fases::Fase::gerenciar_colisoes(){
	G_Colisoes.executar();
}

void Fases::Fase::setJogador(Entidades::Personagens::Jogador* inserido){
	if (!Player1) {
		Player1 = inserido;
		LEs.InserirEntidade(static_cast<Entidade*>(Player1));
		LEs.InserirEntidade(static_cast<Entidade*>(Player1->getArma()));
	}
	else if (!Player2) {
		Player2 = inserido;
		LEs.InserirEntidade(static_cast<Entidade*>(Player1->getArma()));
	}
}

sf::Clock* Fases::Fase::getRelogio() {
	return &relogio_global;
}

void Fases::Fase::gerar_fase(int num) {	
	std::fstream arquivo;
	if (num == 2) {
		arquivo.open("C:/Users/rbben/Documents/Projetos/Jogo_C++/Jogo/Jogo_Simao/Imagens/Fase/Deserto/Deserto.txt");
		string linha;
		if (!arquivo.is_open()) {
				std::cout << "Nao abriu o Arquivo de Deserto" << std::endl;
			}
		int j = 0;
		while (getline(arquivo, linha)) {
			for (int i = 0; i < linha.size(); i++) {
				if (linha[i] != ' ') {
					CriarEntidades(linha[i], sf::Vector2f(i, j));
				}
			}
			j++;
		}
	}
	else if (num == 1) {
		string linha;
		arquivo.open("C:/Users/rbben/Documents/Projetos/Jogo_C++/Jogo/Jogo_Simao/Imagens/Fase/Floresta/Floresta.txt");
		if (!arquivo.is_open()) {
			std::cout << "Nao abriu" << std::endl;
		}
		int j = 0;
		while (getline(arquivo, linha)) {
			for (int i = 0; i < linha.size(); i++) {
				if (linha[i] != ' ') {
					CriarEntidades(linha[i], sf::Vector2f(i, j));
				}
			}
			j++;
		}
	}
}

void Fases::Fase::CriarEntidades(char leitura, sf::Vector2f pos){
	switch (leitura) {
	case '1':
		if (Player1) {
			Player1->setPosi(pos.x * 16, 2);
		}
		break;
	case '2':
		if (Player2) {
			Player2->setPosi(pos.x * 16, pos.y * 16);
		}
		break;
	case '3':
		CriarChao(1, pos);
		break;
	case '4':
		CriarChao(2, pos);
		break;
	default:
		std::cout << "Caractere invalido" << std::endl;
		break;
	}
}

void Fases::Fase::CriarChao(int tipo_obs, sf::Vector2f pos) {
	switch (tipo_obs){
	case 1 :
	{Chao_Floresta* pCh_Floresta = new Chao_Floresta(pos.y *16);  	pCh_Floresta->setPosi(pos.x *16, 500);
	G_Colisoes.addObstaculo(pCh_Floresta);
	LEs.InserirEntidade(static_cast<Entidade*> (pCh_Floresta));
	}break;
	case 2 :
	{Chao_Deserto* pCh_Deserto = new Chao_Deserto(pos.y * 16);  	pCh_Deserto->setPosi(pos.x *16, 500);
	G_Colisoes.addObstaculo(static_cast<Obstaculo*>(pCh_Deserto));
	LEs.InserirEntidade(static_cast<Entidade*> (pCh_Deserto));
	}break;
	default:
		std::cout << "Chao Invalido" << std::endl;
	}
}




void Fases::Fase::Inicializa() {
	Textura.loadFromImage(Grafico->getImagem(getId()));
	Imagem.setTexture(Textura);
	G_Colisoes.addJogador(Player1);
	gerar_fase(k_fase);
	LEs.Inicializar();
	Player1->Inicializa();
}