#include "nt_imprimir.h"

Resultado *NT_Imprimir::Interpretar(Contexto *ctx) {
    // imprimimos las expresiones
    return nullptr;
}

QString NT_Imprimir::Graficar() {
    std::stringstream  pPosicion, lPosicion;
    pPosicion <<(void*)this;
    lPosicion <<(void*)this->lista_expr;


    QString nodo = QString::fromStdString("n" + pPosicion.str() +
            " [ label=\"Impr\" fillcolor=\"#8f09b8\"];\n");
    nodo += QString::fromStdString("n" + pPosicion.str()+ "1" +
            " [ label=\"(\" fillcolor=\"#8f09b8\"];\n");
    nodo +=  QString::fromStdString("n" + pPosicion.str()+ " -> n"
            + pPosicion.str()+ "1"+ ";\n");

    nodo +=  QString::fromStdString("n" + pPosicion.str() + " -> n"
            + lPosicion.str()+ ";\n");
    nodo += this->lista_expr->Graficar();

    nodo += QString::fromStdString("n" +pPosicion.str()+ "2" +
            " [ label=\")\" fillcolor=\"#8f09b8\"];\n");
    nodo +=  QString::fromStdString("n" + pPosicion.str() + " -> n"
            + pPosicion.str()+ "2"+ ";\n");

    return nodo;
}

NT_Imprimir::NT_Imprimir(NT_ListaExpr *nodo) {
    this->lista_expr = nodo;
}

