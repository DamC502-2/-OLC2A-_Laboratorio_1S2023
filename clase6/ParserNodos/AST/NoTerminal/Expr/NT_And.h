//
// Created by damihan on 2/04/23.
//

#ifndef CLASE6_NT_AND_H
#define CLASE6_NT_AND_H


#include <ParserNodos/AST/AbsExpr.h>

class NT_And: public AbsExpr {
public:
    AbsExpr* exprIzq;
    AbsExpr* exprDer;

    NT_And(AbsExpr *exprIzq, AbsExpr *exprDer);

    Resultado *Compilar(Contexto *ctx) override;

};


#endif //CLASE6_NT_AND_H
