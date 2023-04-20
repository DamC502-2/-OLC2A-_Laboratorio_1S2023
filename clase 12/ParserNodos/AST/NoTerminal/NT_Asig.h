//
// Created by damihan on 19/04/23.
//

#ifndef CLASE12_NT_ASIG_H
#define CLASE12_NT_ASIG_H


#include "ParserNodos/AST/AbsExpr.h"

class NT_Asig: public AbsExpr{
public:
    QString id;
    AbsExpr* expr;

    NT_Asig(std::string id, AbsExpr* expr);
    Resultado *Compilar(Contexto *ctx) override;

};


#endif //CLASE12_NT_ASIG_H
