//
// Created by damihan on 19/04/23.
//

#ifndef CLASE12_NT_RETURN_H
#define CLASE12_NT_RETURN_H


#include "ParserNodos/AST/AbsExpr.h"

class NT_Return: public AbsExpr{
public:
    NT_Return(AbsExpr* expr);
    AbsExpr* expresion;

    Resultado *Compilar(Contexto *ctx) override;

};


#endif //CLASE12_NT_RETURN_H
