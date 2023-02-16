#ifndef NT_ID_H
#define NT_ID_H

#include "AST/abstractexp.h"

class NT_ID: public AbstractExp{
    QString id;

public:
    Resultado *Interpretar(Contexto *ctx) override;

    explicit NT_ID(const QString &id);

    QString Graficar() override;
};

#endif // NT_ID_H
