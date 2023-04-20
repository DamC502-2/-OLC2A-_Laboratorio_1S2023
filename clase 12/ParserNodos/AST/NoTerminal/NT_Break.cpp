//
// Created by damihan on 3/04/23.
//

#include <iostream>
#include "NT_Break.h"

NT_Break::NT_Break() {}

Resultado *NT_Break::Compilar(Contexto *ctx) {
    if (ctx->LSalida.isEmpty()){
        std::cout<<"Error BREAK fuera de un ciclo"<<std::endl;
        return nullptr;
    }
    ctx->gen->imprimir( "goto " + ctx->LSalida );
    return nullptr;
}
