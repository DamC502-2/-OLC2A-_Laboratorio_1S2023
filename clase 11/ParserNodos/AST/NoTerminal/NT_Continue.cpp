//
// Created by damihan on 3/04/23.
//

#include <iostream>
#include "NT_Continue.h"

Resultado *NT_Continue::Compilar(Contexto *ctx) {
    if (ctx->Linicio.isEmpty()){
        std::cout<<"Error BREAK fuera de un ciclo"<<std::endl;
        return nullptr;
    }
    ctx->gen->imprimir( "goto " + ctx->Linicio );
    return nullptr;
}
