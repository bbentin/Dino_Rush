#pragma once
#include "Obstaculo.h"
namespace Entidades {
    namespace Obstaculos {
        class Chao_Deserto :
            public Obstaculo {
        private:

        public:
            Chao_Deserto();
            ~Chao_Deserto();

            void executar();
        };
    }
}