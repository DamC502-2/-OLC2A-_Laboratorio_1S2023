//
// Created by damihan on 2/04/23.
//

#ifndef CLASE6_NT_RESTA_H
#define CLASE6_NT_RESTA_H


#include <ParserNodos/AST/AbsExpr.h>

class NT_Resta: public AbsExpr{
public:
    NT_Resta(AbsExpr *exprIzq, AbsExpr *exprDer);
    AbsExpr* exprIzq;
    AbsExpr* exprDer;

    Resultado *Compilar(Contexto *ctx) override;
};


#endif //CLASE6_NT_RESTA_H
