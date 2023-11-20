#include "../Cabecalhos/Chefao.h"

Entidades::Personagens::Chefao::Chefao() :Inimigo(4),arma(nullptr) {
	arma = new Entidades::Projetil();
	num_vidas = 10;
}
Entidades::Personagens::Chefao::~Chefao() {
	delete arma;
}

void Entidades::Personagens::Chefao::executar(){
	if (iniciar) { padrao_acao(); }
	Calc_Fisica();
	desenhar();
}

void Entidades::Personagens::Chefao::padrao_acao() {
	arma->atirada();
}

void Entidades::Personagens::Chefao::Colisao(Entidade* colidida, sf::Vector2f limites){
	int verificador = colidida->getId();
	if ((verificador == 8) || (verificador == 9)) {
		Colisao_Chao(colidida, limites);
		iniciar = true;
	}
}

void Entidades::Personagens::Chefao::danar(Entidade* Afetada){
	empurrar(Afetada);
	empurrar(Afetada);
	static_cast<Entidades::Personagens::Personagem*>(Afetada)->operator--();
}

void Entidades::Personagens::Chefao::Colisao_Chao(Entidade* colidida, sf::Vector2f limites){
	if (limites.y < 0) {
		setPosi(getPosicao().x, getPosicao().y + limites.y);
		parar_movimento_y();
		no_ar = false;
	}
}

void Entidades::Personagens::Chefao::setArma(Entidades::Projetil* gun){
	arma = gun;
}

void Entidades::Personagens::Chefao::salvar(){
}


