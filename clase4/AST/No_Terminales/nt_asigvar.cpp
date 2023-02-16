#include "nt_asigvar.h"


NT_AsigVar::NT_AsigVar(AbstractExp *id, AbstractExp *expr) : ID(id), Expr(expr) {}

// asignamos variables a la memoria
Resultado *NT_AsigVar::Interpretar(Contexto *ctx) {
    return nullptr;
}

QString NT_AsigVar::Graficar() {
    std::stringstream  pPosicion, idPosicion, ePosicion ;
    pPosicion <<(void*)this;
    idPosicion <<(void*)this->ID;
    ePosicion <<(void*)this->Expr;


    QString nodo = QString::fromStdString("n" + pPosicion.str() +
            " [ label=\"AsigVar\" shape=record, fillcolor=midnightblue];\n");
    nodo +=  QString::fromStdString("n" + pPosicion.str() + " -> n"
            + idPosicion.str()+ ";\n");
    nodo += this->ID->Graficar();
    nodo +=  QString::fromStdString("n" + pPosicion.str() + " -> n"
            + ePosicion.str()+ ";\n");
    nodo += this->Expr->Graficar();
    return nodo;
}
