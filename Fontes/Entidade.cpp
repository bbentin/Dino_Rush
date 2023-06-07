#include "../Cabecalhos/Entidade.h"

Entidades::Entidade::Entidade(const int i, sf::Vector2f posi):Ente(i),massa(5),forca_resultante(0,0),no_ar(true) {
	posicao = posi; Imagem.setPosition(posicao);
}

Entidades::Entidade::~Entidade() {
}

sf::Vector2f Entidades::Entidade::Get_Velocidade(){
	return velocidade;
}

void Entidades::Entidade::executar(){
}

void Entidades::Entidade::setVelo(sf::Vector2f velo){
	velocidade = velo;
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
	Calc_Fisica();
}

void Entidades::Entidade::setIntervalo(float tempo){
	intervalo = tempo;
}


sf::Vector2f Entidades::Entidade::Colide(Entidade* proximidade){
	float distancia_x, distancia_y, limites_x, limites_y;

	distancia_x = fabs((proximidade->getPosicao().x + proximidade->getTamanho().x / 2) - (getPosicao().x + getTamanho().x / 2));
	distancia_y = fabs((proximidade->getPosicao().y + proximidade->getTamanho().y / 2) - (getPosicao().y + getTamanho().y / 2));

	limites_x = fabs(proximidade->getTamanho().x/2 + getTamanho().x/2);
	limites_y = fabs(proximidade->getTamanho().y/2 + getTamanho().y/2);

	return sf::Vector2f(distancia_x - limites_x, distancia_y - limites_y);
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

}

void Entidades::Entidade::Aplicar_Gravidade() {
	forca_resultante += Gravidade;
}

void Entidades::Entidade::Calc_Fisica(){
	if (no_ar) {
		Aplicar_Gravidade();
	}
	velocidade = Calc_Velocidade(Calc_Aceleracao(forca_resultante));
	Calc_Posicao(velocidade);
	setPosi(posicao);
	reseta_forca_res();
}


void Entidades::Entidade::reseta_forca_res() {
	forca_resultante.x = 0; forca_resultante.y = 0;
	velocidade.x = 0; velocidade.y = 0;
}

void Entidades::Entidade::reseta_forca_res_x(){
	forca_resultante.x = 0;
}

void Entidades::Entidade::reseta_forca_res_y(){
	forca_resultante.y = 0;
}


void Entidades::Entidade::soma_forca(sf::Vector2f forza) {
	forca_resultante += forza;
}

void Entidades::Entidade::set_velocidade(sf::Vector2f vel){
	velocidade = vel;
}

const sf::Vector2f Entidades::Entidade::Gravidade = sf::Vector2f(0.0f,4.0f);
float Entidades::Entidade::intervalo = 0.0;