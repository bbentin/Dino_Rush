#pragma once
#include "Fase.h"
#include "Mosca.h"
#include "Gosmona.h"
#include "Espinhos.h"
#include "Chefao.h"

#define ARQUIVOD "Imagens/Fase/Deserto/entidades.json"

namespace Fases {
    class Deserto :
        public Fase {

    private:
        const int pos_Moscas[6],pos_Chefao[4];
        const int pos_Lamas[6]; 
        int num_Moscas, num_Lamas, num_Chefoes;
    public:

        Deserto();
        ~Deserto();
        void executar();
        void CriarInimigos();
        void CriarObstaculos();
        void CriarMoscas();
        void CriarChefao();
        void CriarLamas();
        void Inicializa();
        void salvar();
    };
}