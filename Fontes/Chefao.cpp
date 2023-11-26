#include "../Cabecalhos/Chefao.h"

Entidades::Personagens::Chefao::Chefao(sf::Vector2f pos) :Inimigo(4), arma(nullptr) {
	criarArma();
	num_vidas = 10;
}
Entidades::Personagens::Chefao::~Chefao() {
	delete arma;
}

void Entidades::Personagens::Chefao::executar() {
	if (iniciar) { padrao_acao(); }
	Calc_Fisica();
	desenhar();
}

void Entidades::Personagens::Chefao::padrao_acao() {
	arma->atirada();
}

void Entidades::Personagens::Chefao::Colisao(Entidade* colidida, sf::Vector2f limites) {
	int verificador = colidida->getId();
	if ((verificador == 8) || (verificador == 9)) {
		Colisao_Chao(colidida, limites);
		iniciar = true;
	}
}

void Entidades::Personagens::Chefao::danar(Entidade* Afetada) {
	empurrar(Afetada);
	empurrar(Afetada);
	static_cast<Entidades::Personagens::Personagem*>(Afetada)->operator--();
}

void Entidades::Personagens::Chefao::Colisao_Chao(Entidade* colidida, sf::Vector2f limites) {
	if (limites.y < 0) {
		setPosi(getPosicao().x, getPosicao().y + limites.y);
		parar_movimento_y();
		no_ar = false;
	}
}

void Entidades::Personagens::Chefao::setArma(Entidades::Projetil* gun) {
	arma = gun;
}

Entidades::Projetil* Entidades::Personagens::Chefao::getArma() const {
	return arma;
}

void Entidades::Personagens::Chefao::criarArma() {
	std::ifstream arquivo(ARQUIVOD);
	if (!arquivo)
	{
		cout << "Erro ao abrir arquivo de salvamento" << endl;
		exit(1);
	}

	if (arquivo.peek() == -1) {
		arquivo.close();
		arma = new Projetil();
		arma->setDono(this);
	}
	else
	{
		nlohmann::json json = nlohmann::json::parse(arquivo);

		for (auto it = json.begin(); it != json.end(); ++it) {
			string id = to_string((*it)["id"][0]);
			string dono = to_string((*it)["dono"][0]);
			if (id == "12") {
				sf::Vector2f pos = sf::Vector2f(
					(float)((*it)["posicao"][0]),
					(float)((*it)["posicao"][1])
				);
				float vel = (float)((*it)["velocidade"][0]);
				int visivel = (int)((*it)["visibilidade"][0]);
				arma = new Projetil(pos, static_cast<Entidade*>(this), vel, static_cast<bool>(visivel));
				arma->setPosi(pos);
				arma->setDono(this);
			}
			id = "";
		}
	}
}

void Entidades::Personagens::Chefao::salvar(std::ostringstream* entrada) {
	sf::Vector2f pos = getPosicao();
	(*entrada) << "{ \"id\": [" << getId() << "], \"posicao\": [" << pos.x << "," << pos.y << "] }" << std::endl;
}