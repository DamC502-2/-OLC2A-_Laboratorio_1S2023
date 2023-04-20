//
// Created by damihan on 2/04/23.
//

#ifndef CLASE6_T_ID_E_H
#define CLASE6_T_ID_E_H


#include <ParserNodos/AST/AbsExpr.h>

class T_ID_e : public AbsExpr {
public:
    T_ID_e(QString ID);
    QString ID;
    Resultado *Compilar(Contexto *ctx) override;

};


#endif //CLASE6_T_ID_E_H
