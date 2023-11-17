#pragma once
#include "Ente.h"
#include <stdlib.h>

namespace Entidades {
	class Entidade :
		public Ente {
	private:
	protected:
		
		static float intervalo;
		static const sf::Vector2f Gravidade;
		sf::Vector2f posicao,velocidade;
		bool no_ar,vivo;
		void Aplicar_Gravidade();
		void Calc_Posicao();
		sf::Vector2f Limitar_Velocidade();

	public:
		
		Entidade(const int i = 0, sf::Vector2f posi = sf::Vector2f(0, 0));
		~Entidade();

		sf::Vector2f Existe_Colisao(Entidade* proxima);
		const sf::Vector2f getPosicao();
		const sf::Vector2f getTamanho();
		void setNoAr(bool ar);
	    void Soma_Velocidade(sf::Vector2f Soma);
		void setPosi(sf::Vector2f arrumada);
		void setPosi(float a, float b);
		void Calc_Fisica();
		void parar_movimento_x();
		void parar_movimento_y();
		void empurrar(Entidade* empurrada);

		static void setIntervalo(float tempo);
		virtual void Colisao(Entidade* colidida,sf::Vector2f limites) = 0;
		virtual void executar() = 0;
		virtual void salvar() = 0;

	};

}
