//
// Created by damihan on 2/04/23.
//

#include "T_Num_e.h"

T_Num_e::T_Num_e(QString Numero) {
    this->Numero = Numero;
}

Resultado *T_Num_e::Compilar(Contexto *ctx) {
    auto res = new Resultado();
    res->Dir = this->Numero;
    return res;
}
