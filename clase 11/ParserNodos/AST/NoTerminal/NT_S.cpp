//
// Created by damihan on 3/04/23.
//

#include "NT_S.h"

Resultado *NT_S::Compilar(Contexto *ctx) {
    this->hijo->Compilar(ctx);
    return nullptr;
}

NT_S::NT_S(AbsExpr *hijo) : hijo(hijo) {}
