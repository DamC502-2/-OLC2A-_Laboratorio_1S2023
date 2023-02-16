#ifndef T_ID_H
#define T_ID_H
#include "../abstractexp.h"

class T_ID : public AbstractExp{
    QString id ;

public:
    Resultado *Interpretar(Contexto *ctx) override;

    QString Graficar() override;

    T_ID(QString id);

};


#endif // T_ID_H
