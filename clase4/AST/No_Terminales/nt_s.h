#ifndef NT_S_H
#define NT_S_H


#include "../abstractexp.h"

class NT_S : public AbstractExp  {
    AbstractExp* sentencias;

public:
    NT_S(AbstractExp *sentencias);

    Resultado *Interpretar(Contexto* ctx) override;
    QString Graficar() override;
};

#endif // NT_S_H
