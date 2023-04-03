//
// Created by damihan on 3/04/23.
//

#ifndef CLASE6_NT_CONTINUE_H
#define CLASE6_NT_CONTINUE_H


#include <ParserNodos/AST/AbsExpr.h>

class NT_Continue : public AbsExpr {
public:
    Resultado *Compilar(Contexto *ctx) override;
};


#endif //CLASE6_NT_CONTINUE_H
