//
// Created by damihan on 1/04/23.
//

#ifndef CLASE6_ABSEXPR_H
#define CLASE6_ABSEXPR_H


#include "ParserNodos/Contexto.h"
#include "Resultado.h"

class AbsExpr {
public:
    //Resultado = atributos sintetizados
    virtual Resultado* Compilar(Contexto* ctx) = 0;
};


#endif //CLASE6_ABSEXPR_H
