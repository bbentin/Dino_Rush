#include "../Cabecalhos/Entidade.h"

Entidades::Entidade::Entidade(const int i, sf::Vector2f posi):Ente(i),massa(5),forca_resultante(0,0) {
	posicao = posi; Imagem.setPosition(posicao);
}

Entidades::Entidade::~Entidade() {
}

void Entidades::Entidade::executar(){
}

sf::Vector2f Entidades::Entidade::Limitar_Velocidade(sf::Vector2f Velocidade) {
	sf::Vector2f Velocidade_condizente(0.0, 0.0);

	Velocidade_condizente = Velocidade;
	if (Velocidade.x > 30) {
		Velocidade_condizente.x = 30;
	}
	if (Velocidade.y > 30) {
		Velocidade_condizente.y = 30;
	}

	return Velocidade_condizente;
}


sf::Vector2f Entidades::Entidade::getPosicao(){
	return posicao;
}

sf::Vector2f Entidades::Entidade::getTamanho(){
	sf::Vector2f tam;
	tam.x = Imagem.getTextureRect().width;
	tam.y = Imagem.getTextureRect().height;
	return tam;
}

void Entidades::Entidade::setPosi(sf::Vector2f ajeitada){
	posicao = ajeitada;
	Imagem.setPosition(posicao);
}

void Entidades::Entidade::setPosi(float a, float b){
	posicao = sf::Vector2f(a, b);
	Imagem.setPosition(posicao);
}

void Entidades::Entidade::parar_movimento(){
	reseta_forca_res();
	Aplicar_Forca();
}

void Entidades::Entidade::setIntervalo(float tempo){
	intervalo = tempo;
}

bool Entidades::Entidade::Colide(Entidade* proximidade){
	float distancia_x, distancia_y, limites_x, limites_y;

	distancia_x = abs(proximidade->getPosicao().x - this->getPosicao().x);
	distancia_y = abs((proximidade->getPosicao().y - this->getPosicao().y));

	limites_x = abs((proximidade->getTamanho().x / 2) - (getTamanho().x / 2));
	limites_y = abs((proximidade->getTamanho().y / 2) - (getTamanho().y / 2));


	if ((distancia_x < limites_x) && (distancia_y < limites_y)) {
		return true;
	}
	else { return false; }
}

sf::Vector2f Entidades::Entidade::Calc_Aceleracao(sf::Vector2f forca_r) {
	sf::Vector2f acel;
	acel.x = forca_r.x / massa;
	acel.y = forca_r.y / massa;
	return acel;
}

sf::Vector2f Entidades::Entidade::Calc_Velocidade(sf::Vector2f acelera) {
	
sf::Vector2f vel;
    vel.x = acelera.x * intervalo;
	vel.y = acelera.y * intervalo  ;
	vel = Limitar_Velocidade(vel);
	return vel;
}

void Entidades::Entidade::Calc_Posicao(sf::Vector2f Velocidade){
	sf::Vector2f mudanca;
	
	mudanca.y += Velocidade.y * intervalo /30;
	mudanca.x += Velocidade.x * intervalo /30; 
		
	posicao += mudanca;
	Imagem.move(mudanca);
}

void Entidades::Entidade::Aplicar_Gravidade() {
	forca_resultante += Gravidade;
}

void Entidades::Entidade::Aplicar_Forca(){
//Aplicar_Gravidade();
	Calc_Posicao(
		Calc_Velocidade(
			Calc_Aceleracao(forca_resultante)));
	reseta_forca_res();
}

void Entidades::Entidade::reseta_forca_res() {
	forca_resultante.x = 0; forca_resultante.y = 0;
}

void Entidades::Entidade::soma_forca(sf::Vector2f forza) {
	forca_resultante += forza;
}

const sf::Vector2f Entidades::Entidade::Gravidade = sf::Vector2f(0.0f,4.0f);
float Entidades::Entidade::intervalo = 0.0;