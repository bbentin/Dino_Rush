#pragma once
#include "./Cabecalhos/Obstaculo.h"


namespace Entidades {
    namespace Obstaculos {
        class Lama :
            public Obstaculo {

        private:

        public:
            Lama();
            ~Lama();
            void desacelera();
        };
    }
}
