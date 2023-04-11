//
// Created by damihan on 2/04/23.
//

#ifndef CLASE6_NT_MULTI_H
#define CLASE6_NT_MULTI_H


#include <ParserNodos/AST/AbsExpr.h>

class NT_Multi: public AbsExpr {
public:
    AbsExpr* exprIzq;
    AbsExpr* exprDer;
    NT_Multi(AbsExpr *exprIzq, AbsExpr *exprDer);
    Resultado *Compilar(Contexto *ctx) override;
};


#endif //CLASE6_NT_MULTI_H
