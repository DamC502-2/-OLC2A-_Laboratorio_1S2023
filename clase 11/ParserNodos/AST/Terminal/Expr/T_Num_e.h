//
// Created by damihan on 2/04/23.
//

#ifndef CLASE6_T_NUM_E_H
#define CLASE6_T_NUM_E_H


#include "ParserNodos/AST/AbsExpr.h"

class T_Num_e: public  AbsExpr{
public:
    T_Num_e(QString Numero);
    QString Numero;

    Resultado *Compilar(Contexto *ctx) override;


};


#endif //CLASE6_T_NUM_E_H
