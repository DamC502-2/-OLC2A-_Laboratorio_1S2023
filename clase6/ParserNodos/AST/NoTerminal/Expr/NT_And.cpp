//
// Created by damihan on 2/04/23.
//

#include "NT_And.h"

Resultado *NT_And::Compilar(Contexto *ctx) {
    auto resultado = new Resultado();
    auto r_izq = this->exprIzq->Compilar(ctx);
    //acciones del marcador
    ctx->gen->imprimir(r_izq->EV + ":");
    auto r_der = this->exprDer->Compilar(ctx);
    resultado->EF = r_izq->EF + ":\n" + r_der->EF;
    resultado->EV = r_der->EV;
    return resultado;
}

NT_And::NT_And(AbsExpr *exprIzq, AbsExpr *exprDer) : exprIzq(exprIzq), exprDer(exprDer) {}
