#include "../Cabecalhos/Deserto.h"

Fases::Deserto::Deserto() :Fase(11, 2), pos_Moscas{ 5,15,25,40,57,70}, pos_Chefao{33, 45, 64, 74 }, pos_Lamas{ 10, 20, 30, 40, 50, 60 }
{
	srand(time(NULL));
	num_Moscas = 3 + rand() % 4;
	num_Lamas = 3 + rand() % 4;
	num_Chefoes = 3 + rand() % 1;
	gerar_fase(k_fase);
	ativa = true;
}

Fases::Deserto::~Deserto(){
}

void Fases::Deserto::executar() {
	desenhar();
	LEs.executar();
	VerificaMortos();
	G_Colisoes.executar();
	Player1->setIntervalo(relogio_global.restart().asMilliseconds() / 2);
}

void Fases::Deserto::CriarInimigos(){
	CriarMoscas();
	CriarChefao();
}

void Fases::Deserto::CriarObstaculos(){
	CriarLamas();
}

void Fases::Deserto::CriarMoscas(){
	std::ifstream arquivo(ARQUIVOD);
	// verifica se o arquivo esta vazio:
	if (arquivo.peek() == -1 || !arquivo) {
		arquivo.close();
		for (int i = 0; i < num_Moscas; i++) {
			Entidades::Personagens::Mosca* pMosca = new Entidades::Personagens::Mosca(); pMosca->setPosi(pos_Moscas[i] * 16, altura_spawn_inimigos);
			G_Colisoes.addInimigo(static_cast<Entidades::Personagens::Inimigo*>(pMosca));
			LEs.InserirEntidade(static_cast<Entidades::Entidade*> (pMosca));
			num_inimigos++;
		}
	}
	else
	{
		nlohmann::json json = nlohmann::json::parse(arquivo);

		Entidades::Personagens::Mosca* pMosca;

		for (auto it = json.begin(); it != json.end(); ++it) {
			// pega o id da entidade e converte para string para comparar com o id da Gosma
			string id = to_string((*it).front());
			if (id == "[5]") {
				sf::Vector2f pos = sf::Vector2f(
					(float)((*it)["posicao"][0]),
					(float)((*it)["posicao"][1])
				);
				float vel = (float)((*it)["velocidade"][0]);
				LEs.InserirEntidade(static_cast<Entidades::Entidade*> (pMosca = new Entidades::Personagens::Mosca(pos, vel)));
				pMosca->setPosi(pos);
				G_Colisoes.addInimigo(static_cast<Entidades::Personagens::Inimigo*>(pMosca));
				num_inimigos++;
			}
			id = "";
		}
		arquivo.close();
	}
}

void Fases::Deserto::CriarChefao(){
	std::ifstream arquivo(ARQUIVOD);
	
	if (arquivo.peek() == -1 || !arquivo) {
		arquivo.close();
		for (int i = 0; i < num_Chefoes; i++) {
			Entidades::Personagens::Chefao* pChefao = new Entidades::Personagens::Chefao(); 	pChefao->setPosi(pos_Chefao[i] * 16, altura_spawn_inimigos);
			Entidades::Projetil* pArma = new Entidades::Projetil();	pArma->setDono(static_cast<Entidades::Entidade*>(pChefao));	pChefao->setArma(pArma);
			G_Colisoes.addInimigo(static_cast<Entidades::Personagens::Inimigo*>(pChefao)); G_Colisoes.addProjetil(pArma);
			LEs.InserirEntidade(static_cast<Entidades::Entidade*> (pChefao));	LEs.InserirEntidade(static_cast<Entidades::Entidade*>(pArma));
			num_inimigos++;
		}
	}
	else
	{
		nlohmann::json json = nlohmann::json::parse(arquivo);

		Entidades::Personagens::Chefao* pChefao;

		for (auto it = json.begin(); it != json.end(); ++it) {
			string id = to_string((*it)["id"][0]);
			if (id == "4") {
				sf::Vector2f pos = sf::Vector2f(
					(float)((*it)["posicao"][0]),
					(float)((*it)["posicao"][1])
				);
				LEs.InserirEntidade(static_cast<Entidades::Entidade*> (pChefao = new Entidades::Personagens::Chefao(pos)));
				pChefao->setPosi(pos);
				G_Colisoes.addInimigo(static_cast<Entidades::Personagens::Inimigo*>(pChefao));
				num_inimigos++;
				Entidades::Projetil* pArma = pChefao->getArma();
				pArma->setDono(static_cast<Entidades::Entidade*>(pChefao));
				LEs.InserirEntidade(static_cast<Entidades::Entidade*>(pArma));
				G_Colisoes.addProjetil(pArma);
			}
			id = "";
		}
		arquivo.close();
	}
	
}

void Fases::Deserto::CriarLamas(){
	std::ifstream arquivo(ARQUIVOD);
	if (arquivo.peek() == -1 || !arquivo) {
		arquivo.close();
		for (int i = 0; i < num_Lamas; i++) {
			Entidades::Obstaculos::Lama* pLama = new Entidades::Obstaculos::Lama(); pLama->setPosi(pos_Lamas[i] * 16, altura_spawn_obstaculos);
			G_Colisoes.addObstaculo(static_cast<Entidades::Obstaculos::Obstaculo*>(pLama));
			LEs.InserirEntidade(static_cast<Entidades::Entidade*> (pLama));
		}
	}
	else
	{
		nlohmann::json json = nlohmann::json::parse(arquivo);

		Entidades::Obstaculos::Lama* pLama;

		for (auto it = json.begin(); it != json.end(); ++it) {
			string id = to_string((*it).front());
			if (id == "[7]") {
				sf::Vector2f pos = sf::Vector2f(
					(float)((*it)["posicao"][0]),
					(float)((*it)["posicao"][1])
				);
				LEs.InserirEntidade(static_cast<Entidades::Entidade*> (pLama = new Entidades::Obstaculos::Lama(pos)));
				pLama->setPosi(pos);
				G_Colisoes.addObstaculo(static_cast<Entidades::Obstaculos::Obstaculo*>(pLama));
			}
			id = "";
		}
		arquivo.close();
	}
}

void Fases::Deserto::Inicializa(){
	Textura.loadFromImage(Grafico->getImagem(getId()));
	Imagem.setTexture(Textura);
	CriarObstaculos();
	CriarInimigos();
	LEs.Inicializar();
	G_Colisoes.addJogador(Player1);
	LEs.InserirEntidade(static_cast<Entidades::Entidade*>(Player1->getArma()));
	G_Colisoes.addProjetil(Player1->getArma());
	G_Colisoes.addJogador(Player2);
	LEs.InserirEntidade(static_cast<Entidades::Entidade*>(Player2->getArma()));
	G_Colisoes.addProjetil(Player2->getArma());
}

void Fases::Deserto::salvar(){
	std::ofstream arquivo(ARQUIVOD);
	if (!arquivo)
	{
		cout << "Erro ao abrir arquivo de salvamento" << endl;
	}

	buffer.str("");
	buffer << "[";

	LEs.salvar(&buffer);

	buffer << "]";
	arquivo << buffer.str();
	arquivo.close();
}
