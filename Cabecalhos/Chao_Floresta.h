#pragma once
#include "Obstaculo.h"

namespace Entidades {
    namespace Obstaculos {
        class Chao_Floresta :
            public Obstaculo {
        private:

        public:
            Chao_Floresta();
            ~Chao_Floresta();

            void executar();
        };
    }
}