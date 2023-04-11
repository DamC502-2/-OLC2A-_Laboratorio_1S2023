//
// Created by damihan on 2/04/23.
//

#ifndef CLASE6_NT_DIV_H
#define CLASE6_NT_DIV_H


#include <ParserNodos/AST/AbsExpr.h>

class NT_Div: public AbsExpr {
public:
    AbsExpr* exprIzq;
    AbsExpr* exprDer;

    NT_Div(AbsExpr *exprIzq, AbsExpr *exprDer);

    Resultado *Compilar(Contexto *ctx) override;

};


#endif //CLASE6_NT_DIV_H
