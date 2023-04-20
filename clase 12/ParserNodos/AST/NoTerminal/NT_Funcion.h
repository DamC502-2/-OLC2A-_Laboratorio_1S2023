//
// Created by damihan on 19/04/23.
//

#ifndef CLASE12_NT_FUNCION_H
#define CLASE12_NT_FUNCION_H


#include "ParserNodos/AST/AbsExpr.h"
#include "NT_LParams.h"
#include "NT_LSentencias.h"

class NT_Funcion : public AbsExpr {

public:
    QString tipo_retorno;
    NT_LParams* parametros;
    NT_LSentencias * lSentencias;
    QString nombre;

    NT_Funcion(std::string id, std::string tipo_retorno, NT_LParams* parametros, NT_LSentencias* sentencias );

    Resultado *Compilar(Contexto *ctx) override;

};


#endif //CLASE12_NT_FUNCION_H
