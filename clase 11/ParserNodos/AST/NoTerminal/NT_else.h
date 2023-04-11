//
// Created by damihan on 3/04/23.
//

#ifndef CLASE6_NT_ELSE_H
#define CLASE6_NT_ELSE_H


#include "ParserNodos/AST/AbsExpr.h"

class NT_else: public AbsExpr {
public:
    AbsExpr* nt_if;
    AbsExpr* Lsentencias;
    AbsExpr* nt_else;

    NT_else(AbsExpr *lsentencias, AbsExpr *ntElse);
    NT_else(AbsExpr *ntIf);

    Resultado *Compilar(Contexto *ctx) override;


};


#endif //CLASE6_NT_ELSE_H
