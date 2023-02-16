#ifndef T_NUMERO_H
#define T_NUMERO_H


#include "../abstractexp.h"

class T_Numero: public AbstractExp{
QString numero;

public:
    Resultado *Interpretar(Contexto *ctx) override;

    QString Graficar() override;
    explicit T_Numero(QString num);
};


#endif // T_NUMERO_H
