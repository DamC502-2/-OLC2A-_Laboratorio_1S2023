//
// Created by damihan on 19/04/23.
//

#include <iostream>
#include "NT_Return.h"

NT_Return::NT_Return(AbsExpr *expr) {
    this->expresion = expr;
}

Resultado *NT_Return::Compilar(Contexto *ctx) {
    //se obtiene la posicion del return
    ctx->gen->imprimir("// return");
    if (this->expresion != nullptr){
        auto return_pos = ctx->gen->tSimbolos->getSimbolo("return");
        auto e  = this->expresion->Compilar(ctx);

        if (return_pos != nullptr) {
            //TODO verificar tipos e <-> return_pos
        }else {
            std::cerr<<"return inválido la funcion actual es de tipo void"<<std::endl;
            return nullptr;
        }

        auto temp = ctx->gen->newTemp();
        ctx->gen->imprimir(temp + " = P +" + QString::number( return_pos->pos_stack));
        ctx->gen->imprimir("stack[" + temp + "] = " + e->Dir);
    }
    ctx->gen->imprimir("return");
    return nullptr;
}
