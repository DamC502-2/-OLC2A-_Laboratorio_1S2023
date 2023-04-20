//
// Created by damihan on 19/04/23.
//

#ifndef CLASE12_NT_LEXPRLLAMADA_H
#define CLASE12_NT_LEXPRLLAMADA_H


#include "ParserNodos/AST/AbsExpr.h"

class NT_LExprLLamada: public AbsExpr {
public:
    NT_LExprLLamada();
    QVector<AbsExpr*>* expresiones;
    QVector<Resultado*>resultados;

    void addExpr(AbsExpr* expresion);

    Resultado *Compilar(Contexto *ctx) override;


};


#endif //CLASE12_NT_LEXPRLLAMADA_H
