//
// Created by damihan on 2/04/23.
//

#include "NT_Operel.h"

NT_Operel::NT_Operel(AbsExpr *exprIzq, AbsExpr *exprDer, const QString &operacion) : exprIzq(exprIzq), exprDer(exprDer),
                                                                                     operacion(operacion) {}

Resultado *NT_Operel::Compilar(Contexto *ctx) {
    auto  resultado = new Resultado();

    //se compila en el orden deseado
    auto R_izq = this->exprIzq->Compilar(ctx);
    auto R_der = this->exprDer->Compilar(ctx);

    resultado->EV = ctx->gen->newLabel();
    resultado->EF = ctx->gen->newLabel();
    //TODO casteoo comparacion de tipos

    ctx->gen->imprimir("if " + R_izq->Dir + this->operacion + R_der->Dir +" goto " + resultado->EV);
    ctx->gen->imprimir("goto " + resultado->EF);
    return resultado;
}
