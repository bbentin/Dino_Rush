#pragma once
#include "Ente.h"
namespace Entidades {


	class Entidade :
		public Ente {
	protected:
		sf::Vector2f posicao, velocidade, aceleracao;
		int massa;
		static const int Gravidade;
	public:
		Entidade();
		Entidade(sf::Vector2f posi);
		~Entidade();

		virtual void executar() = 0;
		void Aplicar_Gravidade();
		void Aplicar_Forca(sf::Vector2f forca);
		sf::Vector2f Calc_Aceleracao(sf::Vector2f Forca);
		sf::Vector2f Calc_Velocidade(sf::Vector2f Aceleracao);
		sf::Vector2f Calc_Posicao(sf::Vector2f Velocidade);
		sf::Vector2f Limitar_Velocidade(sf::Vector2f Velocidade);
	};


}