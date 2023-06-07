#include"../Cabecalhos/Fase.h"

Fases::Fase::Fase(const int i, const int k):Ente(i),relogio_global(),G_Colisoes(),LEs(),Player1(nullptr),Player2(nullptr),k_fase(k) {

}

Fases::Fase::~Fase() {
}

void Fases::Fase::gerenciar_colisoes(){
	G_Colisoes.executar();
}

void Fases::Fase::setJogador(Entidades::Personagens::Jogador* inserido){
	if (!Player1) {
		Player1 = inserido;
	}
	else if (!Player2) {
		Player2 = inserido;
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
			Player1->setPosi(pos.x * 16, pos.y * 16);
		}
		break;
	case '2':
		if (Player2) {
			Player2->setPosi(pos.x * 16, pos.y * 16);
		}
		break;
	case '3':
		CriarInimigo(1, pos);
		break;
	case '4':
		CriarInimigo(2, pos);
		break;
	case '5':
		CriarInimigo(3, pos);
		break;
	case '6':
		CriarInimigo(4, pos);
		break;
	case '7':
		CriarObstaculo(1, pos);
		break;
	case '8':
		CriarObstaculo(2, pos);
		break;
	case '9':
		CriarObstaculo(3, pos);
		break;
	case 'A':
		CriarObstaculo(4, pos);
		break;
	case 'B':
		CriarInimigo(5, pos);
		break;
	case 'C':
		CriarInimigo(6, pos);
		break;
	default:
		std::cout << "Caracter invalido" << std::endl;
		break;
	}
}

void Fases::Fase::CriarInimigo(int tipo_ini, sf::Vector2f pos){
	
	switch (tipo_ini){
	case 1: {
	Gosma* pGosma = new Gosma();	pGosma->setPosi(pos.x * 16, pos.y * 16);
	G_Colisoes.addInimigo(static_cast<Inimigo*>(pGosma));
	LEs.InserirEntidade(static_cast<Entidade*> (pGosma)); 
	}break;
	case 2:{
	Decapitado* pDecapitado = new Decapitado();	pDecapitado->setPosi(pos.x *16, pos.y * 16);
	G_Colisoes.addInimigo(static_cast<Inimigo*>(pDecapitado));
	LEs.InserirEntidade(static_cast<Entidade*> (pDecapitado));	
	}break;
	case 3:{
	Mosca* pMosca = new Mosca(); pMosca->setPosi(pos.x * 16, pos.y * 16);
	G_Colisoes.addInimigo(static_cast<Inimigo*>(pMosca));
	LEs.InserirEntidade(static_cast<Entidade*> (pMosca));	
	}break;
	case 4:{
	Chefao* pChefao = new Chefao(); 	pChefao->setPosi(pos.x * 16, pos.y * 16);
	G_Colisoes.addInimigo(static_cast<Inimigo*>(pChefao));
	LEs.InserirEntidade(static_cast<Entidade*> (pChefao));
	}break;
	case 5: {
	Moscona* pMoscona = new Moscona();	pMoscona->setPosi(pos.x * 16, pos.y * 16);
	G_Colisoes.addInimigo(static_cast<Inimigo*>(pMoscona));
	LEs.InserirEntidade(static_cast<Entidade*> (pMoscona));
	}break;
	case 6: {
	Gosmona* pGosmona = new Gosmona; pGosmona->setPosi(pos.x * 16, pos.y * 16);
	G_Colisoes.addInimigo(static_cast<Inimigo*>(pGosmona));
	LEs.InserirEntidade(static_cast<Entidade*> (pGosmona));
	}break;
	default:
		std::cout << "Inimigo invalido" << std::endl;
		break;
	}
}

void Fases::Fase::CriarObstaculo(int tipo_obs, sf::Vector2f pos) {
	switch (tipo_obs){
	case 1: {
		Espinhos* pEspinhos = new Espinhos();	pEspinhos->setPosi(pos.x * 16, pos.y * 16);
		G_Colisoes.addObstaculo(static_cast<Obstaculo*>(pEspinhos));
		LEs.InserirEntidade(static_cast<Entidade*> (pEspinhos));
	}
		break;
	case 2 :
	{Lama* pLama = new Lama(); 	pLama->setPosi(pos.x * 16, pos.y * 16);
	G_Colisoes.addObstaculo(static_cast<Obstaculo*>(pLama));
	LEs.InserirEntidade(static_cast<Entidade*> (pLama));
	}break;
	case 3 :
	{Chao_Deserto* pCh_Deserto = new Chao_Deserto();  	pCh_Deserto->setPosi(pos.x *16, pos.y * 16);
	G_Colisoes.addObstaculo(static_cast<Obstaculo*>(pCh_Deserto));
	LEs.InserirEntidade(static_cast<Entidade*> (pCh_Deserto));
	}break;
	case 4 :
	{Chao_Floresta* pCh_Floresta = new Chao_Floresta();  	pCh_Floresta->setPosi(pos.x *16, pos.y *16);
	G_Colisoes.addObstaculo(pCh_Floresta);
	LEs.InserirEntidade(static_cast<Entidade*> (pCh_Floresta));
	}break;
	default:
		std::cout << "Obstaculo Invalido" << std::endl;
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