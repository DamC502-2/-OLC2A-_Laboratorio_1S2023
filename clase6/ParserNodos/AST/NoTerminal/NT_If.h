//
// Created by damihan on 2/04/23.
//

#ifndef CLASE6_NT_IF_H
#define CLASE6_NT_IF_H


#include <ParserNodos/AST/AbsExpr.h>

class NT_If: public AbsExpr {
public:
    AbsExpr* cond;
    AbsExpr* lsentencias;
    AbsExpr* elseIf;

    NT_If(AbsExpr *cond, AbsExpr *lsentencias, AbsExpr *elseIf);

    Resultado *Compilar(Contexto *ctx) override;

};


#endif //CLASE6_NT_IF_H
