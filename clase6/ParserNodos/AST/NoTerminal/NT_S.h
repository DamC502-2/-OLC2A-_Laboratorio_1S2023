//
// Created by damihan on 3/04/23.
//

#ifndef CLASE6_NT_S_H
#define CLASE6_NT_S_H


#include <ParserNodos/AST/AbsExpr.h>

class NT_S: public AbsExpr {
public:
    AbsExpr* hijo;

    NT_S(AbsExpr *hijo);

    Resultado *Compilar(Contexto *ctx) override;


};


#endif //CLASE6_NT_S_H
