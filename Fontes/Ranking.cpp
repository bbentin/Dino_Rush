#include "../Cabecalhos/Ranking.h"

Ranking::Ranking() : Ente(15), pontos(), nomes(), text(), fonte()
{
	fonte.loadFromFile("Imagens/Texto/PressStart2P-Regular.ttf");
	text.setFont(fonte);
	text.setCharacterSize(30);
	text.setFillColor(sf::Color::Green);
	text.setOutlineThickness(2);
	text.setOutlineColor(sf::Color::Black);
}

Ranking::~Ranking()
{
}

void Ranking::carregar()
{
	std::ifstream arquivo(ARQUIVO);
	if (!arquivo)
	{
		cout << "Erro ao abrir arquivo de salvamento" << endl;
		exit(1);
	}

	if (arquivo.peek() == -1) {
		arquivo.close();
		cout << "Arquivo vazio" << endl;
	}
	else {
		nlohmann::json json = nlohmann::json::parse(arquivo);

		for (auto it = json.begin(); it != json.end(); ++it) {
			string id = to_string((*it)["id"][0]);
			string jogador = to_string((*it)["jogador2"][0]);
			if (id == "1")
			{
				string aux = to_string((*it)["pontos"][0]);
				pontos.push_back(aux);
				if (jogador == "0")
				{
					nomes.push_back("Jogador 1");
				}
				else if (jogador == "1")
				{
					nomes.push_back("Jogador 2");
				}
			}
		}
		arquivo.close();
	}
}

void Ranking::executar()
{
	desenha();
}

void Ranking::desenha()
{
	desenhar();
	for (int i = 0; i < pontos.size(); i++)
	{
		std::stringstream ss;
		ss << nomes[i] << " " << pontos[i];
		text.setString(ss.str());
		text.setPosition(sf::Vector2f(50, (i + 1) * 50));
		Grafico->getTela()->draw(text);
	}
}

void Ranking::Inicializa()
{
	carregar();
	Textura.loadFromImage(Grafico->getImagem(getId()));
	Imagem.setTexture(Textura);
}