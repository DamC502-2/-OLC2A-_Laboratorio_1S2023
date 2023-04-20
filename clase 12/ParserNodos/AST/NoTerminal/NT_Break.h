//
// Created by damihan on 3/04/23.
//

#ifndef CLASE6_NT_BREAK_H
#define CLASE6_NT_BREAK_H


#include "ParserNodos/AST/AbsExpr.h"

class NT_Break: public AbsExpr{
public:
    NT_Break();

    Resultado *Compilar(Contexto *ctx) override;
};


#endif //CLASE6_NT_BREAK_H
