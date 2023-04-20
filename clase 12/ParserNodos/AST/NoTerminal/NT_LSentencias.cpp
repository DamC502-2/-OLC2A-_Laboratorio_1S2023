//
// Created by damihan on 3/04/23.
//

#include "NT_LSentencias.h"


NT_LSentencias::NT_LSentencias() {
    this->nodos = QVector<AbsExpr*>();

}

Resultado *NT_LSentencias::Compilar(Contexto *ctx) {
    // for c++11
    for (auto nodo: this->nodos) {
        //se compilan todas las sentencias
        nodo->Compilar(ctx);

        //se elimina el bloque de temporales
        ctx->gen->limpiarTemporales();
    }
    return nullptr; //Lsentencias no retorna nada
}

void NT_LSentencias::addNodo(AbsExpr *nodo) {
    this->nodos.push_back(nodo);
}
