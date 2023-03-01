#ifndef NT_LSENTENCIAS_H
#define NT_LSENTENCIAS_H

#include "../abstractexp.h"

class NT_LSentencias : public AbstractExp
{
public:
    QVector<AbstractExp*>lista_sentencias;

    NT_LSentencias();
    QString Graficar() override;
    Resultado* Interpretar(Contexto* ctx) override;
    void AddSentencia(AbstractExp *nodo);
};

#endif // NT_LSENTENCIAS_H
