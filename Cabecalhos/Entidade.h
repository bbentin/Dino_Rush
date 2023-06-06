#pragma once
#include "Ente.h"
#include <stdlib.h>
namespace Entidades {
	class Entidade :
		public Ente {
	private:
		sf::Vector2f forca_resultante;
	protected:
		int massa;
		static float intervalo;
		static const sf::Vector2f Gravidade;
		sf::Vector2f posicao;

		void reseta_forca_res();
		void Aplicar_Forca();
		void Aplicar_Gravidade();
		void soma_forca(sf::Vector2f forza);
		void Calc_Posicao(sf::Vector2f Velocidade);
		sf::Vector2f Calc_Aceleracao(sf::Vector2f forca_r);
		sf::Vector2f Calc_Velocidade(sf::Vector2f Aceleracao);
		sf::Vector2f Limitar_Velocidade(sf::Vector2f Velocidade);
		bool Colide(Entidade* colidida);

	public:
		Entidade(const int i = 0, sf::Vector2f posi = sf::Vector2f(0, 0));
		~Entidade();
		sf::Vector2f getPosicao();
		sf::Vector2f getTamanho();
		virtual void executar();
		void setPosi(sf::Vector2f arrumada);
		void setPosi(float a, float b);
		void parar_movimento();
		static void setIntervalo(float tempo);

	};

}
