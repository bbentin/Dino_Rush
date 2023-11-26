#include "../Cabecalhos/Fase.h"

Fases::Fase::Fase(const int i, const int k) : Ente(i), relogio_global(), G_Colisoes(), LEs(), k_fase(k), Player1(nullptr), Player2(nullptr), altura_spawn_inimigos(600), altura_spawn_obstaculos(920)
, ativa(false), final(false), num_inimigos(0), recuperada(false){
}

Fases::Fase::~Fase()
{
}

void Fases::Fase::gerenciar_colisoes()
{
	G_Colisoes.executar();
}

void Fases::Fase::setJogador(Entidades::Personagens::Jogador *inserido)
{
	if (!Entidades::Personagens::Jogador::getJogador2())
	{
		Player1 = inserido;
		Player1->setFase(this->getId());
		LEs.InserirEntidade(static_cast<Entidades::Entidade *>(Player1));
	}
	else if (Entidades::Personagens::Jogador::getJogador2())
	{
		if (Player1 == nullptr)
		{
			Player1 = inserido;
			Player1->setFase(this->getId());
			LEs.InserirEntidade(static_cast<Entidades::Entidade *>(Player1));
		}
		else if (Player2 == nullptr)
		{
			Player2 = inserido;
			Player2->setFase(this->getId());
			LEs.InserirEntidade(static_cast<Entidades::Entidade *>(Player2));
		}
	}
}

sf::Clock *Fases::Fase::getRelogio()
{
	return &relogio_global;
}

void Fases::Fase::gerar_fase(int num)
{
	std::ifstream arquivoj(ARQUIVOF);
	std::ifstream arquivod(ARQUIVOD);
	if (!arquivoj || arquivoj.peek() == -1){
		arquivoj.close();
		std::fstream arquivo;
		if (num == 1)
		{
			arquivo.open("Imagens/Fase/Floresta/Floresta.txt");
			string linha;
			if (!arquivo.is_open())
			{
				std::cout << "Nao abriu o arquivo de Floresta" << std::endl;
			}
			int j = 0;
			while (getline(arquivo, linha))
			{
				for (int i = 0; i < linha.size(); i++)
				{
					if (linha[i] != ' ')
					{
						CriarChao(sf::Vector2f(i, j));
					}
				}
				j++;
			}
			arquivo.close();
		}
	}else
		{
			recuperada = true;
			nlohmann::json json = nlohmann::json::parse(arquivoj);
			for (auto it = json.begin(); it != json.end(); ++it)
			{
				string id = to_string((*it).front());
				if (id == "[9]")
				{
					CriarChao(sf::Vector2f(
													(float)((*it)["posicao"][0])/16,
													(float)((*it)["posicao"][1])/16));
				}
			}
			arquivoj.close();
		}

	if (num == 2)
	{
		if (arquivod.peek() == -1 || !arquivod){
			arquivod.close();
			std::fstream arquivoD;
			string linha;
			arquivoD.open("Imagens/Fase/Deserto/Deserto.txt");
			if (!arquivoD.is_open())
			{
				std::cout << "Nao abriu o arquivo de Deserto" << std::endl;
			}
			int j = 0;
			while (getline(arquivoD, linha))
			{
				for (int i = 0; i < linha.size(); i++)
				{
					if (linha[i] != ' ')
					{
						CriarChao(sf::Vector2f(i, j));
					}
				}
				j++;
			}
			arquivoD.close();
		}
		else
		{
			recuperada = true;
			nlohmann::json json = nlohmann::json::parse(arquivod);
			for (auto it = json.begin(); it != json.end(); ++it)
			{
				string id = to_string((*it).front());
				if (id == "[9]")
				{
					CriarChao( sf::Vector2f(
													(float)((*it)["posicao"][0])/16,
													(float)((*it)["posicao"][1])/16));
				}
			}
			arquivod.close();
		}
	}
}


void Fases::Fase::CriarChao(sf::Vector2f pos){
	Entidades::Obstaculos::Chao_Floresta *pCh_Floresta = new Entidades::Obstaculos::Chao_Floresta(pos.y * 16);
	pCh_Floresta->setPosi(pos.x * 16, pos.y * 16);
	G_Colisoes.addObstaculo(static_cast<Entidades::Obstaculos::Obstaculo *>(pCh_Floresta));
	LEs.InserirEntidade(static_cast<Entidades::Entidade *>(pCh_Floresta));
}

void Fases::Fase::VerificaMortos()
{

	Entidades::Entidade *pMorto = G_Colisoes.VerificaMortos();
	if (pMorto != nullptr)
	{
		int i = pMorto->getId();
		if (i > 2 && i < 7)
		{
			num_inimigos--;
		}
		LEs.RemoverEntidade(pMorto);
	}
}

bool Fases::Fase::verificaFinal()
{
	if (num_inimigos == 0 && ativa == true)
	{
		final = true;
	}
	if (Player1->getVidas() == 0 && Player2->getVidas() == 0)
	{
		final = true;
	}
	return final;
}

bool Fases::Fase::getAtiva()
{
	return ativa;
}

void Fases::Fase::Inicializa() {
}
