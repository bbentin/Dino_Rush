#include "../Cabecalhos/Entidade.h"

Entidades::Entidade::Entidade(const int i, sf::Vector2f posi):Ente(i),no_ar(true),vivo(true),rapidez(2) {
	velocidade = sf::Vector2f(0.0, 0.0);
	Imagem.setPosition(posi);
}

Entidades::Entidade::~Entidade() {
}

void Entidades::Entidade::Limitar_Velocidade() {
	if (rapidez > 4) {
		rapidez = 4;
	}
	if (rapidez < 0.5) {
		rapidez = 0.5;
	}
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

const float Entidades::Entidade::getRapidez() const{
	return rapidez;
}

void Entidades::Entidade::Inicializa(){
	Textura.loadFromImage(Grafico->getImagem(getId()));
	Imagem.setTexture(Textura);
	Imagem.setScale(2.0, 2.0);
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
	Aplicar_Gravidade();
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
		empurrada->Soma_Velocidade(sf::Vector2f(empurrada->getTamanho().x, -20));
		empurrada->setNoAr(true);
	}
	else if (empurrada->getPosicao().x < getPosicao().x) {
		empurrada->Soma_Velocidade(sf::Vector2f(-empurrada->getTamanho().x, -20));
		empurrada->setNoAr(true);
	}
}

void Entidades::Entidade::multiplica_Rapidez(float sinal){
	
	rapidez *= sinal;
	Limitar_Velocidade();
}

const sf::Vector2f Entidades::Entidade::Gravidade = sf::Vector2f(0.0f,0.5f);
float Entidades::Entidade::intervalo = 0.0;
