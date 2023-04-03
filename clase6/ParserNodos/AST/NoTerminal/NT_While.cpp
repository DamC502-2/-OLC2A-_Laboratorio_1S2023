//
// Created by damihan on 2/04/23.
//

#include "NT_While.h"

NT_While::NT_While(AbsExpr *condicion, AbsExpr *lSentencias) : condicion(condicion), lSentencias(lSentencias) {
    this->Linicio_anterior = QString();
}

Resultado *NT_While::Compilar(Contexto *ctx) {
    //marcado1
    QString etqInicio = ctx->gen->newLabel();
    this->Linicio_anterior = ctx->Linicio;
    this->LSalida_anterior = ctx->LSalida;
    ctx->Linicio = etqInicio;
    ctx->gen->imprimir(etqInicio + ":");
    // sintetizamos condicion
    Resultado* r_codicion = this->condicion->Compilar(ctx);
    ctx->LSalida = r_codicion->EF;
    // marcador 2
    ctx->gen->imprimir(r_codicion->EV + ":");
    // sintetizada final
    this->lSentencias->Compilar(ctx);
    ctx->gen->imprimir(r_codicion->EF + ":");
    ctx->Linicio = this->Linicio_anterior;
    ctx->LSalida = this->LSalida_anterior;
    return nullptr;
}
