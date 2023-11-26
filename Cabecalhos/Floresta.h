#pragma once
#include "Fase.h"
#include "Mosca.h"
#include "Espinhos.h"
#include "Gosma.h"

#define ARQUIVOF "Imagens/Fase/Floresta/entidades.json"

namespace Fases {
    class Floresta :
        public Fase {

    private:
        const int pos_Moscas[6], pos_Gosmas[6];
        const int pos_Espinhos[6];
        int num_Moscas, num_Gosmas, num_Espinhos;

    public:

        Floresta();
        ~Floresta();
        void executar();

        void CriarInimigos();
        void CriarMoscas();
        void CriarGosmas();
        void CriarObstaculos();
        void CriarEspinhos();
        void Inicializa();
        void salvar();
    };
}