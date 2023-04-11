//
// Created by damihan on 2/04/23.
//

#ifndef CLASE6_NT_OPEREL_H
#define CLASE6_NT_OPEREL_H


#include "ParserNodos/AST/AbsExpr.h"

class NT_Operel: public AbsExpr {
    AbsExpr* exprIzq;
    AbsExpr* exprDer;
    QString operacion;
public:

    NT_Operel(AbsExpr *exprIzq, AbsExpr *exprDer, const QString &operacion);
    Resultado *Compilar(Contexto *ctx) override;


};


#endif //CLASE6_NT_OPEREL_H
