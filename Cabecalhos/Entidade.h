#pragma once
#include "Ente.h"
namespace Entidades {


	class Entidade :
		public Ente {
	private:
		static sf::Clock* relogio;
		sf::Vector2f forca_resultante;
	protected:
		int massa;
		sf::Vector2f posicao;
		static const sf::Vector2f Gravidade;
		void Aplicar_Forca();
		void reseta_forca_res();
		void Aplicar_Gravidade();
		void soma_forca(sf::Vector2f forza);
		void Calc_Posicao(sf::Vector2f Velocidade);
		sf::Vector2f Calc_Aceleracao(sf::Vector2f forca_r);
		sf::Vector2f Calc_Velocidade(sf::Vector2f Aceleracao);
		sf::Vector2f Limitar_Velocidade(sf::Vector2f Velocidade);

	public:
		Entidade();
		Entidade(sf::Vector2f posi);
		~Entidade();
		virtual void executar() = 0;

	protected:
		
	};


}