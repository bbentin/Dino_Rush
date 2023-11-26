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
	if (!arquivo)
	{
		cout << "Erro ao abrir arquivo de salvamento" << endl;
		exit(1);
	}

	// verifica se o arquivo esta vazio:
	if (arquivo.peek() == -1) {
		arquivo.close();
		for (int i = 0; i < num_Moscas; i++) {
			Mosca* pMosca = new Mosca(); pMosca->setPosi(pos_Moscas[i] * 16, altura_spawn_inimigos);
			G_Colisoes.addInimigo(static_cast<Inimigo*>(pMosca));
			LEs.InserirEntidade(static_cast<Entidade*> (pMosca));
			num_inimigos++;
		}
	}
	else
	{
		nlohmann::json json = nlohmann::json::parse(arquivo);

		Mosca* pMosca;

		for (auto it = json.begin(); it != json.end(); ++it) {
			// pega o id da entidade e converte para string para comparar com o id da Gosma
			string id = to_string((*it).front());
			if (id == "[5]") {
				sf::Vector2f pos = sf::Vector2f(
					(float)((*it)["posicao"][0]),
					(float)((*it)["posicao"][1])
				);
				float vel = (float)((*it)["velocidade"][0]);
				LEs.InserirEntidade(static_cast<Entidade*> (pMosca = new Mosca(pos, vel)));
				pMosca->setPosi(pos);
				G_Colisoes.addInimigo(static_cast<Inimigo*>(pMosca));
				num_inimigos++;
			}
			id = "";
		}
		arquivo.close();
	}
}

void Fases::Deserto::CriarChefao(){
	std::ifstream arquivo(ARQUIVOD);
	if (!arquivo)
	{
		cout << "Erro ao abrir arquivo de salvamento" << endl;
		exit(1);
	}
	
	if (arquivo.peek() == -1) {
		arquivo.close();
		for (int i = 0; i < num_Chefoes; i++) {
			Chefao* pChefao = new Chefao(); 	pChefao->setPosi(pos_Chefao[i] * 16, altura_spawn_inimigos);
			Projetil* pArma = new Projetil();	pArma->setDono(static_cast<Entidade*>(pChefao));	pChefao->setArma(pArma);
			G_Colisoes.addInimigo(static_cast<Inimigo*>(pChefao)); G_Colisoes.addProjetil(pArma);
			LEs.InserirEntidade(static_cast<Entidade*> (pChefao));	LEs.InserirEntidade(static_cast<Entidade*>(pArma));
			num_inimigos++;
		}
	}
	else
	{
		nlohmann::json json = nlohmann::json::parse(arquivo);

		Chefao* pChefao;

		for (auto it = json.begin(); it != json.end(); ++it) {
			string id = to_string((*it)["id"][0]);
			if (id == "4") {
				sf::Vector2f pos = sf::Vector2f(
					(float)((*it)["posicao"][0]),
					(float)((*it)["posicao"][1])
				);
				LEs.InserirEntidade(static_cast<Entidade*> (pChefao = new Chefao(pos)));
				pChefao->setPosi(pos);
				G_Colisoes.addInimigo(static_cast<Inimigo*>(pChefao));
				num_inimigos++;
				Projetil* pArma = pChefao->getArma();
				pArma->setDono(static_cast<Entidade*>(pChefao));
				LEs.InserirEntidade(static_cast<Entidade*>(pArma));
				G_Colisoes.addProjetil(pArma);
			}
			id = "";
		}
		arquivo.close();
	}
	
}

void Fases::Deserto::CriarLamas(){
	std::ifstream arquivo(ARQUIVOD);
	if (!arquivo)
	{
		cout << "Erro ao abrir arquivo de salvamento" << endl;
		exit(1);
	}

	if (arquivo.peek() == -1) {
		arquivo.close();
		for (int i = 0; i < num_Lamas; i++) {
			Lama* pLama = new Lama(); pLama->setPosi(pos_Lamas[i] * 16, altura_spawn_obstaculos);
			G_Colisoes.addObstaculo(static_cast<Obstaculo*>(pLama));
			LEs.InserirEntidade(static_cast<Entidade*> (pLama));
		}
	}
	else
	{
		nlohmann::json json = nlohmann::json::parse(arquivo);

		Lama* pLama;

		for (auto it = json.begin(); it != json.end(); ++it) {
			string id = to_string((*it).front());
			if (id == "[7]") {
				sf::Vector2f pos = sf::Vector2f(
					(float)((*it)["posicao"][0]),
					(float)((*it)["posicao"][1])
				);
				LEs.InserirEntidade(static_cast<Entidade*> (pLama = new Lama(pos)));
				pLama->setPosi(pos);
				G_Colisoes.addObstaculo(static_cast<Obstaculo*>(pLama));
			}
			id = "";
		}
		arquivo.close();
	}
}

void Fases::Deserto::Apagar_save() {
	std::ofstream arquivo(ARQUIVOD);
	if (!arquivo)
	{
		cout << "Erro ao abrir arquivo de salvamento" << endl;
		exit(1);
	}
	arquivo << "";
	arquivo.close();
}

void Fases::Deserto::Inicializa(){
	Textura.loadFromImage(Grafico->getImagem(getId()));
	Imagem.setTexture(Textura);
	CriarObstaculos();
	CriarInimigos();
	G_Colisoes.addJogador(Player1);
	G_Colisoes.addJogador(Player2);
	Player1->setFase(2);
	Player2->setFase(2);
	LEs.Inicializar();
}

void Fases::Deserto::salvar(){
	std::ofstream arquivo(ARQUIVOD);
	if (!arquivo)
	{
		cout << "Erro ao abrir arquivo de salvamento" << endl;
		exit(1);
	}

	buffer.str("");
	buffer << "[";

	LEs.salvar(&buffer);

	buffer << "]";
	arquivo << buffer.str();
	arquivo.close();
}
