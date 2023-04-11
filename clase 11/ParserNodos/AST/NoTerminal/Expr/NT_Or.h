//
// Created by damihan on 2/04/23.
//

#ifndef CLASE6_NT_OR_H
#define CLASE6_NT_OR_H


#include <ParserNodos/AST/AbsExpr.h>

class NT_Or: public AbsExpr {
public:
    AbsExpr* exprIzq;
    AbsExpr* exprDer;

    NT_Or(AbsExpr *exprIzq, AbsExpr *exprDer);

    Resultado *Compilar(Contexto *ctx) override;
};


#endif //CLASE6_NT_OR_H
