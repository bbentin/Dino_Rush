#include "../Cabecalhos/Gerenciador_Eventos.h"

Gerenciadores::Gerenciador_Eventos::Gerenciador_Eventos():state(0) {
	Jogador1 = nullptr; Jogador2 = nullptr; Unico = nullptr; PTela = nullptr;
}
Gerenciadores::Gerenciador_Eventos::~Gerenciador_Eventos() {
	Jogador1 = nullptr; Jogador2 = nullptr; delete Unico;
}

Gerenciadores::Gerenciador_Eventos* Gerenciadores::Gerenciador_Eventos::Singleton(){
	if (Unico == nullptr) {
		Unico  = new Gerenciador_Eventos();
	}
	return Unico;
}


void Gerenciadores::Gerenciador_Eventos::setTela(sf::RenderWindow* Tela){
	PTela = Tela;
}

void Gerenciadores::Gerenciador_Eventos::setJogador(Entidades::Personagens::Jogador* Player){
	if (Jogador1 == nullptr) {
		Jogador1 = Player;
	}
	else if (Jogador2 == nullptr) {
		Jogador2 = Player;
	}
}

int Gerenciadores::Gerenciador_Eventos::getstate(){
	return state;
}



void Gerenciadores::Gerenciador_Eventos::executar() {
	sf::Event evento;
	while (PTela->pollEvent(evento)){
		if (evento.type == sf::Event::KeyPressed) {
			switch (evento.key.code) {
			case sf::Keyboard::A:
				Jogador1->setMovimento_esquerda(true);
				break;
			case sf::Keyboard::D:
				Jogador1->setMovimento_direita(true);
				break;
			case sf::Keyboard::W:
				Jogador1->pular();
				break;
			case sf::Keyboard::LAlt:
				Jogador1->atirar();
				break;
			case sf::Keyboard::Up:
				if (Entidades::Personagens::Jogador::Jogador2) {
					Jogador2->pular();
				}
				break;
			case sf::Keyboard::Left:
				if (Entidades::Personagens::Jogador::Jogador2) {
					Jogador2->setMovimento_esquerda(true);
				}
				break;
			case sf::Keyboard::Right:
				if (Entidades::Personagens::Jogador::Jogador2) {
					Jogador2->setMovimento_direita(true);
				}
			case sf::Keyboard::Num1:
				state = 1;
				break;
			case sf::Keyboard::Num2:
				state = 2;
				break;
			case sf::Keyboard::Num3:
				state = 3;
				break;
			default:
				break;
			}
		}
		else if (evento.type == sf::Event::KeyReleased) {
			switch (evento.key.code) {
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
		else if (evento.type == sf::Event::Closed) {
			PTela->close();
		}
	}
}
