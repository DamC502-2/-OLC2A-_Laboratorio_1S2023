//
// Created by damihan on 2/04/23.
//

#include <iostream>
#include "T_ID_e.h"

Resultado *T_ID_e::Compilar(Contexto *ctx) {
    /*auto  res = new Resultado();
    res->Dir = this->ID;
    return res;*/


    /*se escribe el codigo ya sea si la variable es:
     * por referencia, valor o  local
     * */

    ctx->gen->imprimir("//T_ID_e: " + this->ID);

    Simbolo *variable = ctx->gen->tSimbolos->getSimbolo(this->ID);

    if (variable == nullptr) {
        std::cerr << "La variable: " << this->ID.toStdString() << " no existe" << std::endl;
        return new Resultado(); //NULL
    }
    Resultado *resultado = new Resultado();
    resultado->Dir = ctx->gen->newTemp();
    resultado->Referencia = ctx->gen->newTemp();

    if (variable->tipo_variable == "Local"  ||
    variable->tipo_variable == "Valor") {
        ctx->gen->imprimir(resultado->Referencia + " = P + " +
                           QString::number(variable->pos_stack));
        ctx->gen->imprimir(resultado->Dir + " = stack["
                           + resultado->Referencia + "];");
    } else if (variable->tipo_variable == "Referencia") {
        auto temporal = ctx->gen->newTemp();
        ctx->gen->segmento_temps->remove(temporal); //se remueve para evitar guardarlo

        ctx->gen->imprimir(temporal + " = P + " +
                           QString::number(variable->pos_stack));
        ctx->gen->imprimir(resultado->Referencia + "= stack["
                           + temporal + "];");
        ctx->gen->imprimir(resultado->Dir + " = stack["
                           + resultado->Referencia + "];");

    } else {
        std::cerr << "La variable: " << this->ID.toStdString() << " tienen un tipo de referencia desconocido"
                  << std::endl;
        return new Resultado(); //NULL
    }
    return resultado;
}

T_ID_e::T_ID_e(QString ID) {
    this->ID = ID;
}


