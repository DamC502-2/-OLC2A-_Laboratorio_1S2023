//
// Created by damihan on 19/04/23.
//

#ifndef CLASE12_NT_LLAMADA_H
#define CLASE12_NT_LLAMADA_H


#include "ParserNodos/AST/AbsExpr.h"
#include "NT_LExprLLamada.h"

class NT_LLamada: public AbsExpr{
public:
    NT_LExprLLamada* lExpresiones;
    QString nombre;
    NT_LLamada( std::string nombre ,  NT_LExprLLamada* parametros);

    Resultado *Compilar(Contexto *ctx) override;

};


#endif //CLASE12_NT_LLAMADA_H
