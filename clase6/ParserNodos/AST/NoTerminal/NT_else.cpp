//
// Created by damihan on 3/04/23.
//

#include "NT_else.h"

Resultado *NT_else::Compilar(Contexto *ctx) {
    //si es: else ->ELSE if
    if (this->nt_if != nullptr){
        this->nt_if->Compilar(ctx);
    }
    // si es else -> ELSE { LSentencias } else
    if (this->Lsentencias != nullptr){
        this->Lsentencias->Compilar(ctx);
    }
    if (this->nt_else != nullptr){
        this->nt_else->Compilar(ctx);
    }
    return nullptr;
}

NT_else::NT_else(AbsExpr *lsentencias, AbsExpr *ntElse) : Lsentencias(lsentencias), nt_else(ntElse) {}

NT_else::NT_else(AbsExpr *ntIf) : nt_if(ntIf) {}
