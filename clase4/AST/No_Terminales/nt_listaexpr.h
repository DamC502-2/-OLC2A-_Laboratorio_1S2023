#ifndef NT_LISTAEXPR_H
#define NT_LISTAEXPR_H

#include "../abstractexp.h"

class NT_ListaExpr: public  AbstractExp{
public:
    NT_ListaExpr(AbstractExp* expr);
    QVector<AbstractExp*>lista_expresiones;
    Resultado *Interpretar(Contexto *ctx) override;
    QString Graficar() override;
    void AddNodo(AbstractExp* nodo);
};


#endif // NT_LISTAEXPR_H
