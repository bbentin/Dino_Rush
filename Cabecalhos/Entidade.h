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
		sf::Vector2f posicao,velocidade;
		bool no_ar;
		void Aplicar_Gravidade();
		void Calc_Posicao(sf::Vector2f Velocidade);
		sf::Vector2f Calc_Aceleracao(sf::Vector2f forca_r);
		sf::Vector2f Calc_Velocidade(sf::Vector2f Aceleracao);
		sf::Vector2f Limitar_Velocidade(sf::Vector2f Velocidade);

	public:
		Entidade(const int i = 0, sf::Vector2f posi = sf::Vector2f(0, 0));
		~Entidade();


		sf::Vector2f Colide(Entidade* proxima);
		sf::Vector2f Get_Velocidade();
		const sf::Vector2f getPosicao();
		const sf::Vector2f getTamanho();
		
		void soma_forca(sf::Vector2f forza);
		void setNoAr(bool ar);
		void reseta_forca_res();
		void reseta_forca_res_x();
		void reseta_forca_res_y();
		void setVelo(sf::Vector2f velo);
		void setPosi(sf::Vector2f arrumada);
		void setPosi(float a, float b);
		void Calc_Fisica();;
		void parar_movimento();
		
		static void setIntervalo(float tempo);
		virtual void Colisao(Entidade* colidida,sf::Vector2f limites) = 0;
		virtual void executar();

	};

}
