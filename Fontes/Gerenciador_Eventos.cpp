#include "../Cabecalhos/Gerenciador_Eventos.h"

Gerenciadores::Gerenciador_Eventos::Gerenciador_Eventos() :state() {
	Jogador1 = nullptr; Jogador2 = nullptr; Unico = nullptr; PTela = nullptr; menu_principal = nullptr; menu_pause = nullptr; menu_salvar = nullptr;
	state.push(0);
}
Gerenciadores::Gerenciador_Eventos::~Gerenciador_Eventos() {
	Jogador1 = nullptr; Jogador2 = nullptr; menu_principal = nullptr; menu_pause = nullptr; menu_salvar = nullptr;
	delete Unico;
}

Gerenciadores::Gerenciador_Eventos* Gerenciadores::Gerenciador_Eventos::Singleton() {
	if (Unico == nullptr) {
		Unico = new Gerenciador_Eventos();
	}
	return Unico;
}


void Gerenciadores::Gerenciador_Eventos::setTela(sf::RenderWindow* Tela) {
	PTela = Tela;
}

void Gerenciadores::Gerenciador_Eventos::setJogador(Entidades::Personagens::Jogador* Player) {
	if (Jogador1 == nullptr) {
		Jogador1 = Player;
	}
	else if (Jogador2 == nullptr) {
		Jogador2 = Player;
	}
}

int Gerenciadores::Gerenciador_Eventos::getstate() {
	return state.top();
}

void Gerenciadores::Gerenciador_Eventos::finaliza_atual() {
	if (state.top() == 1 || state.top() == 2) {
		menu_principal->reset();
	}
	state.pop();
}

void Gerenciadores::Gerenciador_Eventos::setMenu(Menu* men) {
	int i = men->getType();
	switch (i){
	case 0:
		menu_principal = men;
		break;
	case 1:
		menu_pause = men;
		break;
	case 2:
		menu_salvar = men;
		menu_salvar->setPressed(false);
		break;
	default:
		break;
	}
}

void Gerenciadores::Gerenciador_Eventos::executar() {
	sf::Event evento;
	while (PTela->pollEvent(evento)) {
	// controle das acoes do menu	
		if (state.top() == 0) {
			if (evento.type == sf::Event::KeyPressed) {
				switch (evento.key.code) {
 				case sf::Keyboard::Up:
					menu_principal->MoveUp();
					break;
				case sf::Keyboard::Down:
					menu_principal->MoveDown();
					break;
				case sf::Keyboard::Enter:
					menu_principal->setPressed(true);
					state.push(menu_principal->GetItem());
					break;
				default:
					break;
				}
			}
		}
	//controle das acoes dos jogadores nas fases
		if (state.top() == 1 || state.top() == 2) { // controle das acoes dos Jogadores
			if (evento.type == sf::Event::KeyPressed) {
				switch (evento.key.code) {
				case sf::Keyboard::A:
					Jogador1->setMovimento_esquerda(true);
					break;
				case sf::Keyboard::D:
					Jogador1->setMovimento_direita(true);
					break;
				case sf::Keyboard::W:
					Jogador1->pular(120);
					break;
				case sf::Keyboard::LAlt:
					Jogador1->atirar();
					break;
				case sf::Keyboard::Up:
					if (Entidades::Personagens::Jogador::getJogador2()) {
						Jogador2->pular(120);
					}
					break;
				case sf::Keyboard::Left:
					if (Entidades::Personagens::Jogador::getJogador2()) {
						Jogador2->setMovimento_esquerda(true);
					}
					break;
				case sf::Keyboard::Right:
					if (Entidades::Personagens::Jogador::getJogador2()) {
						Jogador2->setMovimento_direita(true);
					}break;
				case sf::Keyboard::RAlt:
					if (Entidades::Personagens::Jogador::getJogador2()) {
						Jogador2->atirar();
					}break;
				case sf::Keyboard::P: {
					state.push(5);
				}
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
					if (Entidades::Personagens::Jogador::getJogador2()) {
						Jogador2->setMovimento_esquerda(false);
					}
					break;
				case sf::Keyboard::Right:
					if (Entidades::Personagens::Jogador::getJogador2()) {
						Jogador2->setMovimento_direita(false);
					}
					break;
				default:
					break;
				}
			}
		}
	//controle das acoes do menu pausar
		if (state.top() == 5) {
			if (evento.type == sf::Event::KeyPressed) {
				switch (evento.key.code) {
				case sf::Keyboard::Up:
					menu_pause->MoveUp();
					break;
				case sf::Keyboard::Down:
					menu_pause->MoveDown();
					break;
				case sf::Keyboard::Enter: {
					menu_pause->setPressed(true);
					switch (menu_pause->GetItem()) {
					case 1:
						state.push(6);
						menu_pause->reset();
						break;
					case 2:
						finaliza_atual();
						break;
					case 3:
						menu_pause->setPressed(false);
						finaliza_atual();
						finaliza_atual();
						break;
					case 4:
						menu_pause->setPressed(false);
						PTela->close();
					default:
						break;
					}
				}
					break;
				default:
					break;
				}
			}
		}
	//controle das acoes do menu salvar
		if (state.top() == 6) {
			if (evento.type == sf::Event::KeyPressed) {
				switch (evento.key.code) {
				case sf::Keyboard::Up:
					menu_salvar->MoveUp();
					break;
				case sf::Keyboard::Down:
					menu_salvar->MoveDown();
					break;
				case sf::Keyboard::RShift:
					menu_salvar->setPressed(true);
					break;
				default:
					break;
				}
			}
			if (evento.type == sf::Event::TextEntered) {
				if (evento.text.unicode < 128) {
					menu_salvar->setNome(menu_salvar->getNome() + static_cast<char>(evento.text.unicode));
				}
			}
		}

		else if (evento.type == sf::Event::Closed) {
			PTela->close();
		}
	}
}
