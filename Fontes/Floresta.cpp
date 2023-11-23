#include "../Cabecalhos/Floresta.h"
#include "../Cabecalhos/Lista.h"
#include "../json.hpp"
#include <fstream>
#include <sstream>
#include <string>

#define ARQUIVO "Imagens/Fase/Floresta/entidades.json"

Fases::Floresta::Floresta() :Fase(14, 1), pos_Espinhos{ 3,25,10,15,20 }, pos_Lamas{ 10,20,30,40,50 },
pos_Gosmas{ 10,20,45,58,32 }, pos_Moscas{ 15,30,45,51,59 } {
	srand(time(NULL));
	num_Moscas = 3 + rand() % 3;	num_Espinhos = 3 + rand() % 3;
	num_Gosmas = 3 + rand() % 3;	num_Lamas = 3 + rand() % 3;

	gerar_fase(k_fase);
}

Fases::Floresta::~Floresta() {

}

void Fases::Floresta::executar() {
	desenhar();
	LEs.executar();
	VerificaMortos();
	G_Colisoes.executar();
	Player1->setIntervalo(relogio_global.restart().asMilliseconds() / 2);
}

void Fases::Floresta::CriarInimigos() {
	CriarMoscas();
	CriarGosmas();
}

void Fases::Floresta::CriarMoscas() {
	std::ifstream arquivo(ARQUIVO);
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
	}
}

void Fases::Floresta::CriarGosmas() {
	// abre arquivo para leitura
	std::ifstream arquivo(ARQUIVO);
	if (!arquivo)
	{
		cout << "Erro ao abrir arquivo de salvamento" << endl;
		exit(1);
	}

	// verifica se o arquivo esta vazio:
	if (arquivo.peek() == -1) {
		// caso esteja faz a criação padrão após fechar o arquivo
		arquivo.close();
		for (int i = 0; i < num_Gosmas; i++) {
			Gosma* pGosma = new Gosma(); pGosma->setPosi(pos_Gosmas[i] * 16, altura_spawn_inimigos);
			G_Colisoes.addInimigo(static_cast<Inimigo*>(pGosma));
			LEs.InserirEntidade(static_cast<Entidade*> (pGosma));
			num_inimigos++;
		}
	}
	else
	{
		// caso não esteja vazio, decodifica o arquivo com o parse
		nlohmann::json json = nlohmann::json::parse(arquivo);

		// cria aux
		Gosma* pGosma;

		// percorre o arquivo
		for (auto it = json.begin(); it != json.end(); ++it) {
			// pega o id da entidade e converte para string para comparar com o id da Gosma
			string id = to_string((*it).front());
			// compara o id lido do arquivo com o da gosma
			if (id == "[3]") {
				// cria auxiliar para armazenar a posição e velocidade da Gosma
				sf::Vector2f pos = sf::Vector2f(
					(float)((*it)["posicao"][0]),
					(float)((*it)["posicao"][1])
				);
				float vel = (float)((*it)["velocidade"][0]);
				// cria a Gosma com os valores lidos do arquivo e insere na lista de entidades
				LEs.InserirEntidade(static_cast<Entidade*> (pGosma = new Gosma(pos, vel)));
				// seta posicao que foi recuperada
				pGosma->setPosi(pos);
				// adiciona no gerenciado de colisoes
				G_Colisoes.addInimigo(static_cast<Inimigo*>(pGosma));
				// incrementa o numero de inimigos
				num_inimigos++;
			}
			// limpa o id para não dar problema na proxima iteração
			id = "";
		}
	}
}

void Fases::Floresta::CriarObstaculos() {
	CriarEspinhos();
	CriarLamas();
}

void Fases::Floresta::CriarEspinhos() {
	for (int i = 0; i < num_Espinhos; i++) {
		Espinhos* pEspinhos = new Espinhos(); pEspinhos->setPosi(pos_Gosmas[i] * 16, altura_spawn_obstaculos);
		G_Colisoes.addObstaculo(static_cast<Obstaculo*>(pEspinhos));
		LEs.InserirEntidade(static_cast<Entidade*> (pEspinhos));
	}
}

void Fases::Floresta::CriarLamas() {
	std::ifstream arquivo(ARQUIVO);
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
	}
}

void Fases::Floresta::Inicializa() {
	ativa = true;

	Textura.loadFromImage(Grafico->getImagem(getId()));
	Imagem.setTexture(Textura);
	CriarObstaculos();
	CriarInimigos();
	LEs.Inicializar();
	G_Colisoes.addJogador(Player1);
	G_Colisoes.addJogador(Player2);
	Player1->setPosi(500, 500);
	Player1->setNoAr(true);
	if (Entidades::Personagens::Jogador::getJogador2()) {
		Player2->setPosi(500, 500);
		Player2->setNoAr(true);
	}
}

void Fases::Floresta::salvar() {
	std::ofstream arquivo(ARQUIVO);
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