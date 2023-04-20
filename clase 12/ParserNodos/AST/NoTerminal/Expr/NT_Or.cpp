//
// Created by damihan on 2/04/23.
//

#include "NT_Or.h"

NT_Or::NT_Or(AbsExpr *exprIzq, AbsExpr *exprDer) : exprIzq(exprIzq), exprDer(exprDer) {}

Resultado *NT_Or::Compilar(Contexto *ctx) {
    auto resultado = new Resultado();
    auto r_izq = this->exprIzq->Compilar(ctx);
    //acciones del marcador
    ctx->gen->imprimir(r_izq->EF + ":");
    auto r_der = this->exprDer->Compilar(ctx);
    resultado->EV = r_izq->EV + ":\n" + r_der->EV;
    resultado->EF = r_der->EF;
    return resultado;
}
