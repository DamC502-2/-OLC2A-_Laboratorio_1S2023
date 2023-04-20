//
// Created by damihan on 19/04/23.
//

#include "NT_LExprLLamada.h"

NT_LExprLLamada::NT_LExprLLamada() {
    this->expresiones = new QVector<AbsExpr*>();
}

void NT_LExprLLamada::addExpr(AbsExpr *expresion) {
    this->expresiones->push_back(expresion);
}

Resultado *NT_LExprLLamada::Compilar(Contexto *ctx) {
    //lista de valores
    this->resultados = QVector<Resultado*>();

    for (auto valor : *this->expresiones){
        //se insertan los resultados al vector y se compilan las expresiones
        resultados.push_back(valor->Compilar(ctx));
    }
    //no se devuelve nada
    return nullptr;
}
