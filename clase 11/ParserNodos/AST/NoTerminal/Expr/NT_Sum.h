//
// Created by damihan on 2/04/23.
//

#ifndef CLASE6_NT_SUM_H
#define CLASE6_NT_SUM_H


#include <ParserNodos/AST/AbsExpr.h>

class NT_Sum: public AbsExpr{
public:
    AbsExpr* exprIzq;
    AbsExpr* exprDer;
    NT_Sum(AbsExpr *exprIzq, AbsExpr *exprDer);

    Resultado *Compilar(Contexto *ctx) override;
};


#endif //CLASE6_NT_SUM_H
