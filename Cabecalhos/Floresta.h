#pragma once
#include "Fase.h"
namespace Fases {
    class Floresta :
        public Fase {

    private:
        const int pos_Moscas[5];
        const int pos_Gosmas[5];
        const int pos_Cactos[2];
        int num_Moscas,num_Gosmas;
    public:

        Floresta();
        ~Floresta();
        void executar();

        void CriarInimigos();
        void CriarInimigosDificeis();
        void CriarInimigosFaceis();
        void CriarObstaculos();
    };
}