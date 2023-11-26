#include "../Cabecalhos/Floresta.h"

Fases::Floresta::Floresta() : Fase(14, 1), pos_Espinhos{8, 25, 39, 43, 60, 72},
							  pos_Gosmas{5, 20, 33, 41, 48, 65}, pos_Moscas{15, 30, 45, 53, 59, 73}
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

void Fases::Floresta::executar()
{
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
	std::ifstream arquivo(ARQUIVO);

	// verifica se o arquivo esta vazio:
	if (arquivo.peek() == -1 || !arquivo)
	{
		arquivo.close();
		for (int i = 0; i < num_Moscas; i++)
		{
			Mosca *pMosca = new Mosca();
			pMosca->setPosi(pos_Moscas[i] * 16, altura_spawn_inimigos);
			G_Colisoes.addInimigo(static_cast<Inimigo *>(pMosca));
			LEs.InserirEntidade(static_cast<Entidade *>(pMosca));
			num_inimigos++;
		}
	}
	else
	{
		nlohmann::json json = nlohmann::json::parse(arquivo);

		Mosca *pMosca;

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
				LEs.InserirEntidade(static_cast<Entidade *>(pMosca = new Mosca(pos, vel)));
				pMosca->setPosi(pos);
				G_Colisoes.addInimigo(static_cast<Inimigo *>(pMosca));
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
	std::ifstream arquivo(ARQUIVO);

	// verifica se o arquivo esta vazio:
	if (arquivo.peek() == -1 || !arquivo)
	{
		// caso esteja faz a criação padrão após fechar o arquivo
		arquivo.close();
		for (int i = 0; i < num_Gosmas; i++)
		{
			Gosma *pGosma = new Gosma();
			pGosma->setPosi(pos_Gosmas[i] * 16, altura_spawn_inimigos);
			G_Colisoes.addInimigo(static_cast<Inimigo *>(pGosma));
			LEs.InserirEntidade(static_cast<Entidade *>(pGosma));
			num_inimigos++;
		}
	}
	else
	{
		// caso não esteja vazio, decodifica o arquivo com o parse
		nlohmann::json json = nlohmann::json::parse(arquivo);

		// cria aux
		Gosma *pGosma;

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
				LEs.InserirEntidade(static_cast<Entidade *>(pGosma = new Gosma(pos, vel)));
				// seta posicao que foi recuperada
				pGosma->setPosi(pos);
				// adiciona no gerenciado de colisoes
				G_Colisoes.addInimigo(static_cast<Inimigo *>(pGosma));
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
	std::ifstream arquivo(ARQUIVO);

	if (arquivo.peek() == -1 || !arquivo)
	{
		arquivo.close();
		for (int i = 0; i < num_Espinhos; i++)
		{
			Espinhos *pEspinhos = new Espinhos();
			pEspinhos->setPosi(pos_Espinhos[i] * 16, altura_spawn_obstaculos);
			G_Colisoes.addObstaculo(static_cast<Obstaculo *>(pEspinhos));
			LEs.InserirEntidade(static_cast<Entidade *>(pEspinhos));
		}
	}
	else
	{
		nlohmann::json json = nlohmann::json::parse(arquivo);

		Espinhos *pEspinhos;

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
				LEs.InserirEntidade(static_cast<Entidade *>(pEspinhos = new Espinhos(pos, tempo, static_cast<bool>(visivel))));
				pEspinhos->setPosi(pos);
				G_Colisoes.addObstaculo(static_cast<Obstaculo *>(pEspinhos));
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
	Player1->setFase(1);
	Player2->setFase(1);
	G_Colisoes.addJogador(Player1);
	G_Colisoes.addJogador(Player2);
	LEs.Inicializar();
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