#pragma once
#include "Fase.h"
namespace Fases {
    class Deserto :
        public Fase {

    private:

    public:

        Deserto();
        ~Deserto();
        void executar();
        void CriarInimigosDificeis();
        void CriarInimigosFaceis();
        void CriarObstaculos();
    };
}