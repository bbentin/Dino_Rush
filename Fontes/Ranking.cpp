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

void Ranking::carregar(){
	
	std::ifstream arquivo(ARQUIVO);

	if (arquivo.peek() == -1 || !arquivo) {
		arquivo.close();
		std::cout << "Arquivo vazio" <<	std::endl;
	}
	else {
		buffer.str("");
		buffer << "[";
		nlohmann::json json = nlohmann::json::parse(arquivo);
		for (auto it = json.begin(); it != json.end(); ++it) {
			std::string name = to_string((*it)["nome"]);
			std::string points = to_string((*it)["pontos"][0]);
			buffer << "{\"nome\":" << name << ",";
			buffer << "\"pontos\": [" << points << "]}," << std::endl;
			pontos.push_back(points);
			nomes.push_back(name);
			}
		}
		arquivo.close();
	}


void Ranking::executar(){
	desenha();
}

void Ranking::desenha(){
	desenhar();
	std::list<std::string>::iterator it = pontos.begin();
	for (int i = 0; i < pontos.size(); i++){
		std::stringstream ss;
		ss << nomes[i] << " " << *it;
		text.setString(ss.str());
		text.setPosition(sf::Vector2f(50, (i + 1) * 50));
		Grafico->getTela()->draw(text);
		it++;
	}
}

void Ranking::escrever(std::string nick, int pontuacao){
	std::ofstream arquivo(ARQUIVO);
	nick.erase(nick.begin() + 0);
	nick.erase(nick.end());
	buffer << "{\"nome\":\""<<nick<<"\","<<"\"pontos\": ["<<pontuacao<<"]}"<<std::endl;
	buffer << "]";
	arquivo << buffer.str();
	arquivo.close();
}

void Ranking::Inicializa(){
	carregar();
	Textura.loadFromImage(Grafico->getImagem(getId()));
	Imagem.setTexture(Textura);
}