//
// Created by damihan on 2/04/23.
//

#include "NT_If.h"

Resultado *NT_If::Compilar(Contexto *ctx) {
    auto r_cond = this->cond->Compilar(ctx);
    //marcador 1
    ctx->gen->imprimir(r_cond->EV + ":");

    this->lsentencias->Compilar(ctx);
    QString LSalida = ctx->gen->newLabel();

    if (this->elseIf != nullptr){
        //marcador 2
        ctx->gen->imprimir("goto " + LSalida + ":");
        // sintetizaciónde elfeif
        this->elseIf->Compilar(ctx);
    }
    ctx->gen->imprimir(r_cond->EF + ":");
    ctx->gen->imprimir(LSalida + ":");
    return nullptr; //se devuelve null al no usarse el if como expresion
}

NT_If::NT_If(AbsExpr *cond, AbsExpr *lsentencias, AbsExpr *elseIf) : cond(cond), lsentencias(lsentencias),
                                                                     elseIf(elseIf) {}
