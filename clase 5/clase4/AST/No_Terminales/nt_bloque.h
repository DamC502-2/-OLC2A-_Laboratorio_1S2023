#ifndef NT_BLOQUE_H
#define NT_BLOQUE_H

#include "../abstractexp.h"

class NT_Bloque :  public  AbstractExp
{
    AbstractExp* lSentencias;
public:
    NT_Bloque();
    Resultado *Interpretar(Contexto *ctx) override;
    QString Graficar() override;
    NT_Bloque(AbstractExp* lsetencias);
    void AddLSetencias(AbstractExp* nodo);
};

#endif // NT_BLOQUE_H
