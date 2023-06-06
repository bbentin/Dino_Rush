#include "../Cabecalhos/Gerenciador_Eventos.h"

Gerenciadores::Gerenciador_Eventos::Gerenciador_Eventos():evento() {
	Jogador1 = nullptr; Jogador2 = nullptr; Unico = nullptr; PTela = nullptr;
}
Gerenciadores::Gerenciador_Eventos::~Gerenciador_Eventos() {
	Jogador1 = nullptr; Jogador2 = nullptr; delete Unico;
}

Gerenciadores::Gerenciador_Eventos* Gerenciadores::Gerenciador_Eventos::Singleton(){
	if (Unico = nullptr) {
		Unico  = new Gerenciador_Eventos();
	}
	return Unico;
}


void Gerenciadores::Gerenciador_Eventos::Leitura_teclado() {

}

void Gerenciadores::Gerenciador_Eventos::setTela(sf::RenderWindow* Tela){
	PTela = Tela;
}

void Gerenciadores::Gerenciador_Eventos::executar_menu(){
}

void Gerenciadores::Gerenciador_Eventos::setJogador(Entidades::Personagens::Jogador* Player){
	if (Jogador1 == nullptr) {
		Jogador1 = Player;
	}
	else if (Jogador2 == nullptr) {
		Jogador2 = Player;
	}
}

void Gerenciadores::Gerenciador_Eventos::executar_fases(){
	PTela->pollEvent(evento);

	if (evento.type == sf::Event::KeyPressed) {
		switch (evento.key.code) {
		case sf::Keyboard::A:
			Jogador1->setMovimento_esquerda(true);
			break;
		case sf::Keyboard::D :
			Jogador1->setMovimento_direita(true);
			break;
		case sf::Keyboard::W :
			Jogador1->pular();
			break;
		case sf::Keyboard::Up :
			if (Entidades::Personagens::Jogador::Jogador2) {
				Jogador2->pular();
			}
			break;
		case sf::Keyboard::Left :
			if (Entidades::Personagens::Jogador::Jogador2) {
				Jogador2->setMovimento_esquerda(true);
			}
			break;
		case sf::Keyboard::Right :
			if (Entidades::Personagens::Jogador::Jogador2) {
				Jogador2->setMovimento_direita(true);
			}
			break;
		default:
		break;
		}
	}
	else if (evento.type == sf::Event::KeyReleased) {
		switch (evento.key.code){
		case sf::Keyboard::A:
			Jogador1->setMovimento_esquerda(false);
			break;
		case sf::Keyboard::D:
			Jogador1->setMovimento_direita(false);
			break;
		case sf::Keyboard::Left:
			if (Entidades::Personagens::Jogador::Jogador2) {
				Jogador2->setMovimento_esquerda(false);
			}
			break;
		case sf::Keyboard::Right:
			if (Entidades::Personagens::Jogador::Jogador2) {
				Jogador2->setMovimento_direita(false);
			}
			break;
		default:
			break;
		}
	}
}