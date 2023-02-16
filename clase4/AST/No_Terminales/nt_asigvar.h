#ifndef NT_ASIGVAR_H
#define NT_ASIGVAR_H

#include "../abstractexp.h"

class NT_AsigVar: public AbstractExp{
    AbstractExp* ID;
    AbstractExp* Expr;
public:
    NT_AsigVar(AbstractExp *id, AbstractExp *expr);

    Resultado *Interpretar(Contexto *ctx) override;
    QString Graficar() override;
};


#endif // NT_ASIGVAR_H
