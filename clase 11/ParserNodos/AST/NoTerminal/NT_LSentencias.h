//
// Created by damihan on 3/04/23.
//

#ifndef CLASE6_NT_LSENTENCIAS_H
#define CLASE6_NT_LSENTENCIAS_H


#include "ParserNodos/AST/AbsExpr.h"

class NT_LSentencias: public AbsExpr{
public:
    QVector<AbsExpr*> nodos;
    NT_LSentencias();
    Resultado *Compilar(Contexto *ctx) override;
    void addNodo( AbsExpr* nodo);
};


#endif //CLASE6_NT_LSENTENCIAS_H
