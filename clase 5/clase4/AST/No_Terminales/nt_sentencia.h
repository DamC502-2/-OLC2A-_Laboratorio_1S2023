#ifndef NT_SENTENCIA_H
#define NT_SENTENCIA_H

#include "../abstractexp.h"

class NT_Sentencia: public AbstractExp {
    AbstractExp* hijo;

public:
    Resultado *Interpretar(Contexto *ctx) override;
    QString Graficar() override;
    void AddNodo(AbstractExp* hijo);

};


#endif // NT_SENTENCIA_H
