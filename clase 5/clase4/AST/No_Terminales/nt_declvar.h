#ifndef NT_DECLVAR_H
#define NT_DECLVAR_H
#include "../abstractexp.h"

class NT_DeclVar: public AbstractExp {
    AbstractExp* tipo;
    AbstractExp* ID;
    AbstractExp* Expr;

public:
    Resultado *Interpretar(Contexto *ctx) override;

    QString Graficar() override;

    NT_DeclVar(AbstractExp *tipo, AbstractExp *id, AbstractExp *expr);

    NT_DeclVar(AbstractExp *tipo, AbstractExp *id);



};



#endif // NT_DECLVAR_H
