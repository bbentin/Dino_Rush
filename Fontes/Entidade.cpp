#include "../Cabecalhos/Entidade.h"

Entidades::Entidade::Entidade(const int i, sf::Vector2f posi):Ente(i),no_ar(true),vivo(true) {
	velocidade = sf::Vector2f(0.0, 0.0);
	Imagem.setPosition(posi);
}

Entidades::Entidade::~Entidade() {
}

sf::Vector2f Entidades::Entidade::Limitar_Velocidade() {
	sf::Vector2f Velocidade_condizente(0.0, 0.0);

	Velocidade_condizente = velocidade;
	if (velocidade.x > 30) {
		Velocidade_condizente.x = 30;
	}
	if (velocidade.y > 30) {
		Velocidade_condizente.y = 30;
	}
	if (velocidade.x < -30) {
		Velocidade_condizente.x = -30;
	}
	if (velocidade.y < -400) {
		Velocidade_condizente.y = -400;
	}
	return Velocidade_condizente;
}

const sf::Vector2f Entidades::Entidade::getPosicao(){
	return Imagem.getPosition();
}

const sf::Vector2f Entidades::Entidade::getTamanho(){
	sf::Vector2f tam;
	tam.x = Imagem.getTextureRect().width * Imagem.getScale().x;
	tam.y = Imagem.getTextureRect().height * Imagem.getScale().y;
	return tam;
}

void Entidades::Entidade::setPosi(sf::Vector2f ajeitada){
	Imagem.setPosition(ajeitada);
}

void Entidades::Entidade::setPosi(float X, float Y){
	sf::Vector2f posicao = sf::Vector2f(X, Y);
	Imagem.setPosition(posicao);
}

void Entidades::Entidade::parar_movimento_x(){
	velocidade.x = 0;
}

void Entidades::Entidade::parar_movimento_y() {
	velocidade.y = 0;
}

void Entidades::Entidade::setIntervalo(float tempo){
	intervalo = tempo;
}

sf::Vector2f Entidades::Entidade::Existe_Colisao(Entidade* proximidade){
	float distancia_x, distancia_y, limites_x, limites_y;

	distancia_x = fabs((proximidade->getPosicao().x + proximidade->getTamanho().x / 2) - (getPosicao().x + getTamanho().x / 2));
	distancia_y = fabs((proximidade->getPosicao().y + proximidade->getTamanho().y / 2) - (getPosicao().y + getTamanho().y / 2));

	limites_x = fabs(proximidade->getTamanho().x/2 + getTamanho().x/2);
	limites_y = fabs(proximidade->getTamanho().y/2 + getTamanho().y/2);

	return sf::Vector2f(distancia_x - limites_x, distancia_y - limites_y);
}

void Entidades::Entidade::Soma_Velocidade(sf::Vector2f veloc) {	
	velocidade += veloc;
}

void Entidades::Entidade::Aplicar_Gravidade() {
	Soma_Velocidade(Gravidade);
}

void Entidades::Entidade::Calc_Fisica(){
	if (no_ar) { Aplicar_Gravidade(); }
	//Calc_Posicao();
	Imagem.move(velocidade);
	parar_movimento_x();	parar_movimento_y();
}

void Entidades::Entidade::Aplica_Fisica() {
}

void Entidades::Entidade::setNoAr(bool ar){
	no_ar = ar;
}

void Entidades::Entidade::empurrar(Entidade* empurrada) {
	if (empurrada->getPosicao().x > getPosicao().x) {
		empurrada->setPosi(getPosicao().x + 10 + getTamanho().x, empurrada->getPosicao().y - 30);
		empurrada->setNoAr(true);
	}
	else if (empurrada->getPosicao().x < getPosicao().x) {
		empurrada->setPosi(getPosicao().x - 10 - getTamanho().x, empurrada->getPosicao().y - 30);
		empurrada->setNoAr(true);
	}
}

const sf::Vector2f Entidades::Entidade::Gravidade = sf::Vector2f(0.0f,0.5f);
float Entidades::Entidade::intervalo = 0.0;
