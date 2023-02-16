#ifndef NT_NEGACION_H
#define NT_NEGACION_H



#include "../../abstractexp.h"

class NT_Negacion : public AbstractExp{
    AbstractExp* Derecha;
public:
    NT_Negacion(AbstractExp *derecha);
    Resultado *Interpretar(Contexto *ctx) override;
    QString Graficar() override;
};


#endif // NT_NEGACION_H
