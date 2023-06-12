#pragma once
#include "Fase.h"
#include "Mosca.h"
#include "Gosmona.h"
#include "Espinhos.h"
#include "Chefao.h"
namespace Fases {
    class Deserto :
        public Fase {

    private:
        const int pos_Moscas[5],pos_Gosmonas[5],pos_Chefao;
        const int pos_Lamas[5],pos_Espinhos[5]; 
        int num_Moscas, num_Gosmonas, num_Lamas, num_Espinhos;
    public:

        Deserto();
        ~Deserto();
        void executar();
        void CriarInimigos();
        void CriarObstaculos();
        void CriarMoscas();
        void CriarGosmonas();
        void CriarChefao();
        void CriarLamas();
        void CriarEspinhos();
        void Inicializa();
    };
}