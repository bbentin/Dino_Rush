#include "../Cabecalhos/Jogador.h"

Entidades::Personagens::Jogador::Jogador(const int i, sf::Vector2f posi) : Personagem(i, posi), andar_direita(false),
																		   andar_esquerda(false), arma(nullptr), altura_jogador(828), pontos(0), fase(0)
{
	pontos = 0;
	rapidez = 4;
	num_vidas = 5;
	olhando_direita = true;
	no_ar = true;
	if (!Jogador2)
	{
		Jogador2 = true;
		sou_jogador2 = false;
	}
	else
	{
		sou_jogador2 = true;
		Imagem.setColor(sf::Color::Red);
	}
}
Entidades::Personagens::Jogador::~Jogador()
{
	delete arma;
}

void Entidades::Personagens::Jogador::Colisao(Entidade *colidida, sf::Vector2f limites)
{
	int verificador = colidida->getId();

	switch (verificador)
	{
	case 3:
		Colisao_Inimigo(colidida, limites);
		break;
	case 4:
		Colisao_Inimigo(colidida, limites);
		break;
	case 5:
		Colisao_Inimigo(colidida, limites);
		break;
	case 6:
		Colisao_Inimigo(colidida, limites);
		break;
	case 9:
		Colisao_Obstaculo(colidida, limites);
		break;
	case 10:
		if (static_cast<Entidades::Obstaculos::Espinhos *>(colidida)->getVisivel())
		{
			Colisao_Obstaculo(colidida, limites);
		}
		break;
	case 7:
		Colisao_Obstaculo(colidida, limites);
	case 8:
		Colisao_Obstaculo(colidida, limites);
		break;
	default:
		no_ar = true;
		break;
	}
}

void Entidades::Personagens::Jogador::atirar()
{
	arma->atirada();
}

void Entidades::Personagens::Jogador::salvar(std::ostringstream *entrada)
{
	if (!sou_jogador2)
	{
		sf::Vector2f pos3 = getPosicao();
		float vel = getRapidez();
		(*entrada) << "{ \"id\": [" << getId() << "], \"posicao\": [" << pos3.x << "," << pos3.y << "], \"velocidade\": [" << vel << "], \"pontos\": [" << pontos << "], \"vidas\": ["
				   << num_vidas << "], \"jogador2\": [" << sou_jogador2 << "] }" << std::endl;
	}
	else if (sou_jogador2)
	{
		sf::Vector2f pos4 = getPosicao();
		float vel = getRapidez();
		(*entrada) << "{ \"id\": [" << getId() << "], \"posicao\": [" << pos4.x << "," << pos4.y << "], \"velocidade\": [" << vel << "], \"pontos\": [" << pontos << "], \"vidas\": ["
				   << num_vidas << "], \"jogador2\": [" << sou_jogador2 << "] }" << std::endl;
	}
}

const bool Entidades::Personagens::Jogador::getJogador2()
{
	return Jogador2;
}

void Entidades::Personagens::Jogador::Colisao_Inimigo(Entidade *inimigo, sf::Vector2f limites)
{
	if (limites.x < 0)
	{
		if (inimigo->getPosicao().x < getPosicao().x)
		{
			Imagem.move(-limites.x, 0);
		}
		if (inimigo->getPosicao().x > getPosicao().x)
		{
			Imagem.move(limites.x, 0);
		}
	}
	else if (limites.y < 0)
	{
		if (inimigo->getPosicao().y < getPosicao().y)
		{
			Imagem.move(0, -limites.y);
		}
		if (inimigo->getPosicao().y > getPosicao().y)
		{
			Imagem.move(0, -limites.y);
		}
	}
	static_cast<Entidades::Personagens::Inimigo *>(inimigo)->danar(this);
	no_ar = true;
}

void Entidades::Personagens::Jogador::Colisao_Obstaculo(Entidade *obstaculo, sf::Vector2f limites)
{
	if (limites.y < 0)
	{
		if (obstaculo->getPosicao().y < getPosicao().y)
		{
			Imagem.move(0, -limites.y);
			parar_movimento_y();
		}
		if (obstaculo->getPosicao().y > getPosicao().y)
		{
			Imagem.move(0, +limites.y);
			no_chao = true;
			no_ar = false;
		}
	}
	if (limites.x < 0)
	{
		if (obstaculo->getPosicao().x < getPosicao().x)
		{
			parar_movimento_x();
		}
		else if (obstaculo->getPosicao().x > getPosicao().x)
		{
			parar_movimento_x();
		}
	}
	static_cast<Entidades::Obstaculos::Obstaculo *>(obstaculo)->obstacular(this);
}

Entidades::Projetil *Entidades::Personagens::Jogador::getArma() const
{
	return arma;
}

void Entidades::Personagens::Jogador::setMovimento_direita(bool direita)
{
	andar_direita = direita;
}

void Entidades::Personagens::Jogador::setMovimento_esquerda(bool esquerda)
{
	andar_esquerda = esquerda;
}

void Entidades::Personagens::Jogador::executar()
{

	if (Imagem.getPosition().x <= 0)
	{
		setPosi(0, Imagem.getPosition().y);
	}
	else if (Imagem.getPosition().x >= 1248)
	{
		setPosi(1248, Imagem.getPosition().y);
	}

	if (arma->getPontos())
	{
		pontos++;
		std::cout << "pontuou" << std::endl;
	}
	if (andar_direita)
	{
		mover_direita(rapidez);
	}
	else if (andar_esquerda)
	{
		mover_esquerda(rapidez);
	}
	Calc_Fisica();
	desenhar();
}

void Entidades::Personagens::Jogador::Inicializa()
{

	if (fase == 1)
	{
		std::ifstream arquivo(ARQUIVOF);
		if (arquivo.peek() == -1 || !arquivo)
		{
			arquivo.close();
			Textura.loadFromImage(Grafico->getImagem(getId()));
			Imagem.setTexture(Textura);
			Imagem.setScale(2.0, 2.0);
			setPosi(0, 500);
			setNoAr(true);
			criarProjetil();
		}
		else
		{
			nlohmann::json json = nlohmann::json::parse(arquivo);

			for (auto it = json.begin(); it != json.end(); ++it)
			{
				string id = to_string((*it)["id"][0]);
				string jogador = to_string((*it)["jogador2"][0]);
				if (id == "1" && jogador == "0" && !sou_jogador)
				{
					setPosi(sf::Vector2f(
						(float)((*it)["posicao"][0]),
						(float)((*it)["posicao"][1])));
					Textura.loadFromImage(Grafico->getImagem(getId()));
					Imagem.setTexture(Textura);
					Imagem.setScale(2.0, 2.0);
					pontos = (int)((*it)["pontos"][0]);
					criarProjetil();
				}
				else if (id == "1" && jogador == "1" && sou_jogador)
				{
					setPosi(sf::Vector2f(
						(float)((*it)["posicao"][0]),
						(float)((*it)["posicao"][1])));
					Textura.loadFromImage(Grafico->getImagem(getId()));
					Imagem.setTexture(Textura);
					Imagem.setScale(2.0, 2.0);
					pontos = (int)((*it)["pontos"][0]);
					criarProjetil();
				}
				id = "";
			}
			arquivo.close();
		}
	}
	if (fase == 2)
	{
		std::ifstream arquivod(ARQUIVOD);
		if (arquivod.peek() == (-1) || !arquivod)
		{
			arquivod.close();
			Textura.loadFromImage(Grafico->getImagem(getId()));
			Imagem.setTexture(Textura);
			Imagem.setScale(2.0, 2.0);
			setPosi(0, 500);
			setNoAr(true);
			criarProjetil();
		}
		else
		{
			nlohmann::json json = nlohmann::json::parse(arquivod);

			for (auto it = json.begin(); it != json.end(); ++it)
			{
				string id = to_string((*it)["id"][0]);
				string jogador = to_string((*it)["jogador2"][0]);
				if (id == "1" && jogador == "0" && !sou_jogador2)
				{
					setPosi(sf::Vector2f(
						(float)((*it)["posicao"][0]),
						(float)((*it)["posicao"][1])));
					Textura.loadFromImage(Grafico->getImagem(getId()));
					Imagem.setTexture(Textura);
					Imagem.setScale(2.0, 2.0);
					pontos = (int)((*it)["pontos"][0]);
					criarProjetil();
				}
				else if (id == "1" && jogador == "1" && sou_jogador2)
				{
					setPosi(sf::Vector2f(
						(float)((*it)["posicao"][0]),
						(float)((*it)["posicao"][1])));
					Textura.loadFromImage(Grafico->getImagem(getId()));
					Imagem.setTexture(Textura);
					Imagem.setScale(2.0, 2.0);
					pontos = (int)((*it)["pontos"][0]);
					criarProjetil();
				}
				id = "";
			}
			arquivod.close();
		}
	}
}

int Entidades::Personagens::Jogador::getPontos()
{
	return pontos;
}

void Entidades::Personagens::Jogador::Reseta_Vidas()
{
	num_vidas = 3;
}

void Entidades::Personagens::Jogador::criarProjetil()
{
	if (fase == 1)
	{
		std::ifstream arquivo(ARQUIVO);

		if (arquivo.peek() == -1 || !arquivo)
		{
			arquivof.close();
			arma = new Projetil();
			arma->setDono(this);
		}
		else
		{
			nlohmann::json json = nlohmann::json::parse(arquivof);

			for (auto it = json.begin(); it != json.end(); ++it)
			{
				string id = to_string((*it)["id"][0]);
				if (id == "12")
				{
					sf::Vector2f pos = sf::Vector2f(
						(float)((*it)["posicao"][0]),
						(float)((*it)["posicao"][1]));
					float vel = (float)((*it)["velocidade"][0]);
					int visivel = (int)((*it)["visibilidade"][0]);
					arma = new Projetil(pos, static_cast<Entidade *>(this), vel, static_cast<bool>(visivel));
					arma->setDono(this);
				}
				id = "";
			}
			arquivof.close();
		}
	}

	if (fase == 2)
	{
		std::ifstream arquivod(ARQUIVOD);

		if (arquivod.peek() == -1 || !arquivod)
		{
			arquivod.close();
			arma = new Projetil();
			arma->setDono(this);
		}
		else
		{
			nlohmann::json json = nlohmann::json::parse(arquivod);

			for (auto it = json.begin(); it != json.end(); ++it)
			{
				string id = to_string((*it)["id"][0]);
				if (id == "12")
				{
					sf::Vector2f pos = sf::Vector2f(
						(float)((*it)["posicao"][0]),
						(float)((*it)["posicao"][1]));
					float vel = (float)((*it)["velocidade"][0]);
					int visivel = (int)((*it)["visibilidade"][0]);
					arma = new Projetil(pos, static_cast<Entidade *>(this), vel, static_cast<bool>(visivel));
					arma->setDono(this);
				}
				id = "";
			}
			arquivod.close();
		}
	}
}

void Entidades::Personagens::Jogador::setFase(int f)
{
	fase = f;
}

// define o primeiro jogador
bool Entidades::Personagens::Jogador::Jogador2 = false;