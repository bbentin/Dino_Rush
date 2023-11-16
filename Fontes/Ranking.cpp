#include "../Cabecalhos/Ranking.h"

Ranking::Ranking() : score(0), playerName(nullptr)
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
	std::ofstream arquivo;
	arquivo.open("Imagens/Menus/Ranking/ranking.txt", std::ios::app);
	arquivo << playerName << " " << score << std::endl;
	arquivo.close();
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
}

void Ranking::executar()
{
}