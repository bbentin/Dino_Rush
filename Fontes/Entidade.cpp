#include "../Cabecalhos/Entidade.h"

Entidades::Entidade::Entidade():Ente(),massa(5),forca_resultante(0,0) {
}

Entidades::Entidade::Entidade(sf::Vector2f posi):massa(5) {
	posicao = posi;
}

Entidades::Entidade::~Entidade() {
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

void Entidades::Entidade::Calc_Posicao(sf::Vector2f Velocidade){
	posicao.x = Velocidade.x * relogio->getElapsedTime().asMilliseconds();
	posicao.y = Velocidade.x * relogio->getElapsedTime().asMilliseconds();
}

sf::Vector2f Entidades::Entidade::Calc_Velocidade(sf::Vector2f acelera) {
	
sf::Vector2f vel;
	vel.x = acelera.x * relogio->getElapsedTime().asMilliseconds();
	vel.y = acelera.y * relogio->getElapsedTime().asMilliseconds();
	Limitar_Velocidade(vel);
	return vel;
}

sf::Vector2f Entidades::Entidade::Calc_Aceleracao(sf::Vector2f forca_r) {
	sf::Vector2f acel;
	acel.x = forca_r.x / massa;
	acel.y = forca_r.y / massa;
	return acel;
}

void Entidades::Entidade::Aplicar_Gravidade() {
	forca_resultante += Gravidade;
}

void Entidades::Entidade::Aplicar_Forca(){
	
Aplicar_Gravidade();
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
