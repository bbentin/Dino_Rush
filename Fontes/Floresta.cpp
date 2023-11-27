#include "../Cabecalhos/Floresta.h"

Fases::Floresta::Floresta() : Fase(14, 1), pos_Espinhos{8, 25, 39, 43, 60, 72},
							  pos_Gosmas{5, 20, 33, 41, 49, 65}, pos_Moscas{15, 30, 45, 53, 59, 73}
{
	srand(time(NULL));
	num_Moscas = 3 + rand() % 4;
	num_Espinhos = 3 + rand() % 4;
	num_Gosmas = 3 + rand() % 4;

	gerar_fase(k_fase);
}

Fases::Floresta::~Floresta()
{
}

void Fases::Floresta::executar(){
	desenhar();
	LEs.executar();
	VerificaMortos();
	G_Colisoes.executar();
	Player1->setIntervalo(relogio_global.restart().asMilliseconds() / 2);
}

void Fases::Floresta::CriarInimigos()
{
	CriarMoscas();
	CriarGosmas();
}

void Fases::Floresta::CriarMoscas()
{
	std::ifstream arquivo(ARQUIVOF);

	// verifica se o arquivo esta vazio:
	if (arquivo.peek() == -1 || !arquivo)
	{
		arquivo.close();
		for (int i = 0; i < num_Moscas; i++)
		{
			Entidades::Personagens::Mosca *pMosca = new Entidades::Personagens::Mosca();
			pMosca->setPosi(pos_Moscas[i] * 16, altura_spawn_inimigos);
			G_Colisoes.addInimigo(static_cast<Entidades::Personagens::Inimigo *>(pMosca));
			LEs.InserirEntidade(static_cast<Entidades::Entidade *>(pMosca));
			num_inimigos++;
		}
	}
	else
	{
		nlohmann::json json = nlohmann::json::parse(arquivo);

		Entidades::Personagens::Mosca *pMosca;

		for (auto it = json.begin(); it != json.end(); ++it)
		{
			// pega o id da entidade e converte para string para comparar com o id da Gosma
			string id = to_string((*it).front());
			if (id == "[5]")
			{
				sf::Vector2f pos = sf::Vector2f(
					(float)((*it)["posicao"][0]),
					(float)((*it)["posicao"][1]));
				float vel = (float)((*it)["velocidade"][0]);
				LEs.InserirEntidade(static_cast<Entidades::Entidade *>(pMosca = new Entidades::Personagens::Mosca(pos, vel)));
				pMosca->setPosi(pos);
				G_Colisoes.addInimigo(static_cast<Entidades::Personagens::Inimigo *>(pMosca));
				num_inimigos++;
			}
			id = "";
		}
		arquivo.close();
	}
}

void Fases::Floresta::CriarGosmas()
{
	// abre arquivo para leitura
	std::ifstream arquivo(ARQUIVOF);

	// verifica se o arquivo esta vazio:
	if (arquivo.peek() == -1 || !arquivo)
	{
		// caso esteja faz a criação padrão após fechar o arquivo
		arquivo.close();
		for (int i = 0; i < num_Gosmas; i++)
		{
			Entidades::Personagens::Gosma *pGosma = new Entidades::Personagens::Gosma();
			pGosma->setPosi(pos_Gosmas[i] * 16, altura_spawn_inimigos);
			G_Colisoes.addInimigo(static_cast<Entidades::Personagens::Inimigo *>(pGosma));
			LEs.InserirEntidade(static_cast<Entidades::Entidade *>(pGosma));
			num_inimigos++;
		}
	}
	else
	{
		// caso não esteja vazio, decodifica o arquivo com o parse
		nlohmann::json json = nlohmann::json::parse(arquivo);

		// cria aux
		Entidades::Personagens::Gosma *pGosma;

		// percorre o arquivo
		for (auto it = json.begin(); it != json.end(); ++it)
		{
			// pega o id da entidade e converte para string para comparar com o id da Gosma
			string id = to_string((*it).front());
			// compara o id lido do arquivo com o da gosma
			if (id == "[3]")
			{
				// cria auxiliar para armazenar a posição e velocidade da Gosma
				sf::Vector2f pos = sf::Vector2f(
					(float)((*it)["posicao"][0]),
					(float)((*it)["posicao"][1]));
				float vel = (float)((*it)["velocidade"][0]);
				// cria a Gosma com os valores lidos do arquivo e insere na lista de entidades
				LEs.InserirEntidade(static_cast<Entidades::Entidade *>(pGosma = new Entidades::Personagens::Gosma(pos, vel)));
				// seta posicao que foi recuperada
				pGosma->setPosi(pos);
				// adiciona no gerenciado de colisoes
				G_Colisoes.addInimigo(static_cast<Entidades::Personagens::Inimigo *>(pGosma));
				// incrementa o numero de inimigos
				num_inimigos++;
			}
			// limpa o id para não dar problema na proxima iteração
			id = "";
		}
		// fecha o arquivo
		arquivo.close();
	}
}

void Fases::Floresta::CriarObstaculos()
{
	CriarEspinhos();
}

void Fases::Floresta::CriarEspinhos()
{
	std::ifstream arquivo(ARQUIVOF);

	if (arquivo.peek() == -1 || !arquivo)
	{
		arquivo.close();
		for (int i = 0; i < num_Espinhos; i++)
		{
			Entidades::Obstaculos::Espinhos *pEspinhos = new Entidades::Obstaculos::Espinhos();
			pEspinhos->setPosi(pos_Espinhos[i] * 16, altura_spawn_obstaculos);
			G_Colisoes.addObstaculo(static_cast<Entidades::Obstaculos::Obstaculo *>(pEspinhos));
			LEs.InserirEntidade(static_cast<Entidades::Entidade *>(pEspinhos));
		}
	}
	else
	{
		nlohmann::json json = nlohmann::json::parse(arquivo);

		Entidades::Obstaculos::Espinhos *pEspinhos;

		for (auto it = json.begin(); it != json.end(); ++it)
		{
			string id = to_string((*it).front());
			if (id == "[10]")
			{
				sf::Vector2f pos = sf::Vector2f(
					(float)((*it)["posicao"][0]),
					(float)((*it)["posicao"][1]));
				int visivel = (int)((*it)["visivel"][0]);
				int tempo = (int)((*it)["tempo"][0]);
				LEs.InserirEntidade(static_cast<Entidades::Entidade *>(pEspinhos = new Entidades::Obstaculos::Espinhos(pos, tempo, static_cast<bool>(visivel))));
				pEspinhos->setPosi(pos);
				G_Colisoes.addObstaculo(static_cast<Entidades::Obstaculos::Obstaculo *>(pEspinhos));
			}
			id = "";
		}
		arquivo.close();
	}
}

void Fases::Floresta::Inicializa()
{
	ativa = true;

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

void Fases::Floresta::Apagar_save()
{
	std::ofstream arquivo(ARQUIVOF);
	if (!arquivo)
	{
		arquivo.close();
	}
	else {
		arquivo << "";
		arquivo.close();
	}
}

void Fases::Floresta::salvar()
{
	std::ofstream arquivo(ARQUIVOF);
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