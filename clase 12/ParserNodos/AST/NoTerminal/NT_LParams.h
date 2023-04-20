//
// Created by damihan on 19/04/23.
//

#ifndef CLASE12_NT_LPARAMS_H
#define CLASE12_NT_LPARAMS_H

class Parametro; // declaracion para evitar loops en la imporatación
#include "ParserNodos/AST/AbsExpr.h"
#include "Compilador/Funcion.h"

class NT_LParams: public  AbsExpr{
public:
    QVector<Parametro*> *parametros;
    NT_LParams();
    void addParam(std::string nombre, std::string tipo, std::string tipo_parametro );

    Resultado *Compilar(Contexto *ctx) override;
};


#endif //CLASE12_NT_LPARAMS_H
