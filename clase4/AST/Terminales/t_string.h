#ifndef T_STRING_H
#define T_STRING_H


#include "../abstractexp.h"

class T_String: public AbstractExp {
    QString str;
public:
    Resultado *Interpretar(Contexto *ctx) override;

    QString Graficar() override;

    T_String(QString str);

};


#endif // T_STRING_H
