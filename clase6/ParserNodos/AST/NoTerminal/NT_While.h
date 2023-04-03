//
// Created by damihan on 2/04/23.
//

#ifndef CLASE6_NT_WHILE_H
#define CLASE6_NT_WHILE_H


#include <ParserNodos/AST/AbsExpr.h>

class NT_While: public AbsExpr {

public:
    AbsExpr* condicion;
    AbsExpr* lSentencias;
    QString Linicio_anterior;
    QString LSalida_anterior;
    NT_While(AbsExpr *condicion, AbsExpr *lSentencias);
    Resultado *Compilar(Contexto *ctx) override;

};


#endif //CLASE6_NT_WHILE_H
