#pragma once
#include "Inimigo.h"
namespace Entidades {
    namespace Personagens {
        class Decapitado :
            public Inimigo {
        private:

        public:
            Decapitado();
            ~Decapitado();

            void executar();
            void padrao_acao();
        };
    }
}