#pragma once
#include "Fase.h"
#include "Mosca.h"
#include "Espinhos.h"
#include "Gosma.h"
#include <time.h>
#include <sstream>
#include <fstream>

namespace Fases {
    class Floresta :
        public Fase {

    private:
        const int pos_Moscas[5], pos_Gosmas[5];
        const int pos_Espinhos[5], pos_Lamas[5];
        int num_Moscas,num_Gosmas,num_Espinhos,num_Lamas;
        std::ostringstream buffer;

    public:

        Floresta();
        ~Floresta();
        void executar();

        void CriarInimigos();
        void CriarMoscas();
        void CriarGosmas();
        void CriarObstaculos();
        void CriarEspinhos();
        void CriarLamas();
        void Inicializa();
        void salvar();
    };
}