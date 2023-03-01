#ifndef NT_SUMA_H
#define NT_SUMA_H


#include "../../abstractexp.h"

class NT_Suma: public AbstractExp {
    AbstractExp* Izquierda;
    AbstractExp* Derecha;
public:
    Resultado *Interpretar(Contexto *ctx) override;

    QString Graficar() override;

    NT_Suma(AbstractExp *izquierda, AbstractExp *derecha);

};


#endif // NT_SUMA_H
