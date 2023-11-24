#include "../Cabecalhos/Jogador.h"
#include <sstream>

#define ARQUIVO "Imagens/Fase/Floresta/entidades.json"

Entidades::Personagens::Jogador::Jogador(const int i, sf::Vector2f posi) :Personagem(i, posi),
andar_direita(false),andar_esquerda(false),arma(nullptr),altura_jogador(828){
	pontos = 0;
	rapidez = 4;
	num_vidas = 5; 
	olhando_direita = true;
	criarProjetil();
	no_ar = true;
	if (!Jogador2) {
		Jogador2 = true;
		sou_jogador2 = false;
	}
	else {
		sou_jogador2 = true;
		Imagem.setColor(sf::Color::Red);
	}
}
Entidades::Personagens::Jogador::~Jogador() {
	delete arma;
}

void Entidades::Personagens::Jogador::Colisao(Entidade* colidida, sf::Vector2f limites) {
	int verificador = colidida->getId();
	
	switch (verificador){
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
		if (static_cast<Entidades::Obstaculos::Espinhos*>(colidida)->getVisivel()) {
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

void Entidades::Personagens::Jogador::atirar(){
	arma->atirada();
}

void Entidades::Personagens::Jogador::salvar(std::ostringstream* entrada){
		sf::Vector2f pos = getPosicao();
		float vel = getRapidez();
		(*entrada) << "{ \"id\": [" << getId() << "], \"posicao\": [" << pos.x << "," << pos.y << "], \"velocidade\": [" << vel << "], \"pontos\": [" << pontos << "], \"vidas\": [" 
			<< num_vidas << "], \"jogador2\": [" << sou_jogador2 << "] }" << std::endl;
}

const bool Entidades::Personagens::Jogador::getJogador2(){
	return Jogador2;
}

void Entidades::Personagens::Jogador::Colisao_Inimigo(Entidade* inimigo, sf::Vector2f limites){
	if (limites.x < 0) {
		if (inimigo->getPosicao().x < getPosicao().x) {
			//setPosi(getPosicao().x - limites.x, getPosicao().y);
			parar_movimento_x();
		}
		if (inimigo->getPosicao().x > getPosicao().x) {
			//setPosi(getPosicao().x + limites.x, getPosicao().y);
			parar_movimento_x();
		}
		no_ar = true;
	}else if (limites.y < 0) {
		if (inimigo->getPosicao().y < getPosicao().y) {
		//setPosi(getPosicao().x, getPosicao().y - (limites.y));
			parar_movimento_y();
		}
		if (inimigo->getPosicao().y > getPosicao().y) {
			//setPosi(getPosicao().x, getPosicao().y + (limites.y));
			parar_movimento_y();
		}
	}
	static_cast<Entidades::Personagens::Inimigo*>(inimigo)->danar(this);
	no_ar = true;
}

void Entidades::Personagens::Jogador::Colisao_Obstaculo(Entidade* obstaculo, sf::Vector2f limites) {
	if (limites.y < 0) {
		if (obstaculo->getPosicao().y < getPosicao().y){
			//setPosi(getPosicao().x, getPosicao().y - limites.y);
			parar_movimento_y();
		}
		if (obstaculo->getPosicao().y > getPosicao().y){
			//setPosi(getPosicao().x, getPosicao().y + (limites.y));
			parar_movimento_y();
			no_chao = true;
			no_ar = false;
		}
	}
	if (limites.x < 0) {
		if (obstaculo->getPosicao().x < getPosicao().x) {
			//setPosi(getPosicao().x + limites.x, getPosicao().y);
			parar_movimento_x();
		}
		else if (obstaculo->getPosicao().x > getPosicao().x) {
			//setPosi(getPosicao().x - limites.x, getPosicao().y);
			parar_movimento_x();
		}
	}
	static_cast<Entidades::Obstaculos::Obstaculo*>(obstaculo)->obstacular(this);
}

Entidades::Projetil* Entidades::Personagens::Jogador::getArma() const{
	return arma;
}

void Entidades::Personagens::Jogador::setMovimento_direita(bool direita){
	andar_direita = direita;
}

void Entidades::Personagens::Jogador::setMovimento_esquerda(bool esquerda){
	andar_esquerda = esquerda;
}

void Entidades::Personagens::Jogador::executar() {
	if (andar_direita) {
		mover_direita(rapidez);
	}
	else if (andar_esquerda) {
		mover_esquerda(rapidez);
	}
	Calc_Fisica();
	desenhar();
}

void Entidades::Personagens::Jogador::Inicializa() {
	std::ifstream arquivo(ARQUIVO);
	if (!arquivo)
	{
		cout << "Erro ao abrir arquivo de salvamento" << endl;
		exit(1);
	}

	if (arquivo.peek() == -1) {
		arquivo.close();
		cout << "Arquivo de salvamento vazio" << endl;
		Textura.loadFromImage(Grafico->getImagem(getId()));
		Imagem.setTexture(Textura);
		Imagem.setScale(2.0, 2.0);
		setPosi(16, 828);
	}
	else
	{
		cout << "Arquivo de salvamento encontrado" << endl;
		nlohmann::json json = nlohmann::json::parse(arquivo);

		for (auto it = json.begin(); it != json.end(); ++it) {
			string id = to_string((*it).front());
			string jogador = to_string((*it)["jogador2"][0]);
			if (id == "[1]" && jogador == "[false]") {
				sf::Vector2f pos = sf::Vector2f(
					(float)((*it)["posicao"][0]),
					(float)((*it)["posicao"][1])
				);
				Textura.loadFromImage(Grafico->getImagem(getId()));
				Imagem.setTexture(Textura);
				Imagem.setScale(2.0, 2.0);
				setPosi(pos);
				pontos = (int)((*it)["pontos"][0]);
			}
			else if (id == "[1]" && jogador == "[true]") {
				sf::Vector2f pos = sf::Vector2f(
					(float)((*it)["posicao"][0]),
					(float)((*it)["posicao"][1])
				);
				Textura.loadFromImage(Grafico->getImagem(2));
				Imagem.setTexture(Textura);
				Imagem.setScale(2.0, 2.0);
				Imagem.setColor(sf::Color::Red);
				setPosi(pos);
				pontos = (int)((*it)["pontos"][0]);
			}
			id = "";
		}
		arquivo.close();
		cout << "Jogadores inicializados" << endl;
	}
}

int Entidades::Personagens::Jogador::getPontos(){
	return pontos;
}

void Entidades::Personagens::Jogador::zeraPontos(){
	pontos = 0;
}

void Entidades::Personagens::Jogador::criarProjetil() {
	/*std::ifstream arquivo(ARQUIVO);
	if (!arquivo)
	{
		cout << "Erro ao abrir arquivo de salvamento" << endl;
		exit(1);
	}

	if (arquivo.peek() == -1) {
		arquivo.close();*/
		arma = new Projetil();
		arma->setDono(this);/*
	}
	else
	{
		nlohmann::json json = nlohmann::json::parse(arquivo);

		Projetil* pProjetil;

		for (auto it = json.begin(); it != json.end(); ++it) {
			string id = to_string((*it).front());
			if (id == "[12]") {
				sf::Vector2f pos = sf::Vector2f(
					(float)((*it)["posicao"][0]),
					(float)((*it)["posicao"][1])
				);
			    float vel = (float)((*it)["velocidade"][0]);
				int visivel = (int)((*it)["visibilidade"][0]);
				pProjetil = new Projetil(pos, static_cast<Entidade*>(this), vel, static_cast<bool>(visivel));
				pProjetil->setPosi(pos);
				pProjetil->setDono(this);
				arma = pProjetil;
			}
			id = "";
		}
	}*/
}

// define o primeiro jogador
bool Entidades::Personagens::Jogador::Jogador2 = false;