//
// Created by damihan on 19/04/23.
//

#ifndef CLASE12_NT_DECLA_H
#define CLASE12_NT_DECLA_H


#include "ParserNodos/AST/AbsExpr.h"

class NT_Decla: public AbsExpr {
public:
    QString id;
    QString tipo;

    NT_Decla(std::string id, std::string tipo);

    Resultado *Compilar(Contexto *ctx) override;
};


#endif //CLASE12_NT_DECLA_H
