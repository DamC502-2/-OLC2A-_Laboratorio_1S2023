//
// Created by damihan on 19/04/23.
//

#include <iostream>
#include "NT_Asig.h"

NT_Asig::NT_Asig(std::string id, AbsExpr *expr) {
    this->id = QString::fromStdString(id);
    this->expr = expr;
}

Resultado *NT_Asig::Compilar(Contexto *ctx) {
    ctx->gen->imprimir("//asignacion");

    //buscamos la variable
    auto variable = ctx->gen->tSimbolos->getSimbolo(this->id);

    //se genera el código de la expresión
    auto resultado = this->expr->Compilar(ctx);

    if (variable == nullptr) {
        std::cerr << "error no se encontró la variable: " << this->id.toStdString() << std::endl;
        return nullptr;
    }

    //se decide si se genera el código para variable local o por referencia

    if (variable->tipo_variable == "Local" ||
        variable->tipo_variable == "Valor" ) {
        auto temp = ctx->gen->newTemp();
        ctx->gen->imprimir(temp + " = P + " + QString::number(variable->pos_stack));
        ctx->gen->imprimir("stack[" + temp + "] = " + resultado->Dir);

    } else if (variable->tipo_variable == "Referencia") {
        auto temp = ctx->gen->newTemp();
        auto temp2 = ctx->gen->newTemp();
        ctx->gen->imprimir(temp + " = P + " + QString::number(variable->pos_stack));
        // se accede a la referencia
        ctx->gen->imprimir(temp2 + " = stack[" + temp + "] ");
        //se asigna el valor en el stack en base a la referencia
        ctx->gen->imprimir("stack[" + temp2 + "] = " + resultado->Dir);
    } else {
        std::cerr << "error la variable es de tipo: " << variable->tipo_variable.toStdString() << std::endl;
    }
    return nullptr;
}
