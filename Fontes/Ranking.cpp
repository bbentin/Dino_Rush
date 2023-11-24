#include "../Cabecalhos/Ranking.h"

Ranking::Ranking() : score(0), playerName(nullptr), Menu()
{
}

Ranking::~Ranking()
{
}

void Ranking::setScore(int s)
{
	score = s;
}

int Ranking::getScore()
{
	return score;
}

void Ranking::setPlayerName(char* name)
{
	playerName = name;
}

char* Ranking::getPlayerName()
{
	return playerName;
}

void Ranking::salvar()
{

}

void Ranking::carregar()
{
	std::ifstream arquivo;
	arquivo.open("Imagens/Menus/Ranking/ranking.txt");
	std::string linha;
	while (std::getline(arquivo, linha))
	{
		std::istringstream iss(linha);
		std::string nome;
		int pontuacao;
		iss >> nome >> pontuacao;
		std::cout << nome << " " << pontuacao << std::endl;
	}
	arquivo.close();
	ordenar();
}

void Ranking::ordenar()
{
	std::ifstream arquivo;
	arquivo.open("Imagens/Menus/Ranking/ranking.txt");
	std::string linha;
	std::vector<std::string> linhas;
	while (std::getline(arquivo, linha))
	{
		linhas.push_back(linha);
	}
	arquivo.close();
	std::sort(linhas.begin(), linhas.end());
	std::ofstream arquivo2;
	arquivo2.open("Imagens/Menus/Ranking/ranking.txt");
	for (int i = 0; i < linhas.size(); i++)
	{
		arquivo2 << linhas[i] << std::endl;
	}
	arquivo2.close();
	salvar();
}

void Ranking::executar()
{
	carregar();
	desenha();
}

void Ranking::desenha()
{
	// Abre o arquivo de ranking e faz a leitura e impressão na tela do ranking utilizando de textos do sfml na mesma tela de menu:
	std::ifstream arquivo;
	arquivo.open("Imagens/Menus/Ranking/ranking.txt");
	std::string linha;
	int i = 0;
	while (std::getline(arquivo, linha))
	{
		std::istringstream iss(linha);
		std::string nome;
		int pontuacao;
		iss >> nome >> pontuacao;
		sf::Text text;
		text.setFont(getFonte());
		text.setString(nome + " " + std::to_string(pontuacao));
		text.setCharacterSize(30);
		text.setFillColor(sf::Color::White);
		text.setPosition(100, 100 + i * 50);
		//Grafico->getTela()->draw(text);
		i++;
	}

}
