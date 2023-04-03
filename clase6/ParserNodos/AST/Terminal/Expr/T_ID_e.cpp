//
// Created by damihan on 2/04/23.
//

#include "T_ID_e.h"

Resultado *T_ID_e::Compilar(Contexto *ctx) {
    auto  res = new Resultado();
    res->Dir = this->ID;
    return res;
}

T_ID_e::T_ID_e(QString ID) {
    this->ID = ID;
}


