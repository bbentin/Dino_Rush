#include "../Cabecalhos/Menu.h"

Menu::Menu() :Ente(13){
    fonte.loadFromFile("Imagens/Texto/Arial.ttf");
    textos[0].setFont(fonte); textos[1].setFont(fonte); textos[2].setFont(fonte);
    textos[0].setString(" 1 - Jogar fase 1"); textos[1].setString("2 - Jogar fase 2"); textos[2].setString("3 - Sair");
    textos[0].setPosition(sf::Vector2f(150,100)); textos[1].setPosition(sf::Vector2f(150, 300)); textos[2].setPosition(sf::Vector2f(150, 500));
}
Menu::~Menu() {

}

int Menu::Menu_Principal(){
    return 0;
}

int Menu::Menu_Jogo(){
    return 0;
}

int Menu::Menu_Select_Fase(){
    return 0;
}

void Menu::Menu_Salvar(){
}

void Menu::executar(){
    for (int i = 0; i < 3; i++) {
        Grafico->getTela()->draw(textos[i]);
    }
}
