#ifndef NT_TIPO_H
#define NT_TIPO_H


#include "../abstractexp.h"

class NT_Tipo: public AbstractExp {
 QString tipo;
public:
    NT_Tipo(QString tipo);

    Resultado *Interpretar(Contexto *ctx) override;

    QString Graficar() override;

};


#endif // NT_TIPO_H
