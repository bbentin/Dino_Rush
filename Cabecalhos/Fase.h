#pragma once
#include "Ente.h"
class Fase :
    public Ente{
    

public:
    
    Fase();
    ~Fase();
    
    virtual void executar() = 0;
    void gerenciar_colisoes();
    virtual void gerar_fase() = 0;
};

