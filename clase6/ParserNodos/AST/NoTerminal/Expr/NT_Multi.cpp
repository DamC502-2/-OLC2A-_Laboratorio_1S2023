//
// Created by damihan on 2/04/23.
//

#include "NT_Multi.h"

NT_Multi::NT_Multi(AbsExpr *exprIzq, AbsExpr *exprDer) : exprIzq(exprIzq), exprDer(exprDer) {}

Resultado *NT_Multi::Compilar(Contexto *ctx) {
    auto  resultado = new Resultado();
    auto temp = ctx->gen->newTemp();

    //se compila en el orden deseado
    auto R_izq = this->exprIzq->Compilar(ctx);
    auto R_der = this->exprDer->Compilar(ctx);
    ctx->gen->imprimir(temp + " = " + R_izq->Dir  +  " * " + R_der->Dir);
    resultado->Dir = temp;
    return resultado;
}
