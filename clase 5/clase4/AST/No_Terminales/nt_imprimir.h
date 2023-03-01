#ifndef NT_IMPRIMIR_H
#define NT_IMPRIMIR_H

#include "../abstractexp.h"
#include "nt_listaexpr.h"

class NT_Imprimir: public AbstractExp {
    NT_ListaExpr* lista_expr;
public:
    Resultado *Interpretar(Contexto *ctx) override;
    QString Graficar() override;
    explicit NT_Imprimir(NT_ListaExpr* nodo);
};


#endif // NT_IMPRIMIR_H
