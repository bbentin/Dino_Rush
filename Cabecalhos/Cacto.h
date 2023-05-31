#pragma once
#include "Obstaculo.h"

namespace Entidades {
    namespace Obstaculos {
        class Cacto :
            public Obstaculo {
        private:
        public:
            Cacto();
            ~Cacto();

            void executar();
        };
    }
}