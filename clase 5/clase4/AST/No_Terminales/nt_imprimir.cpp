#include "nt_imprimir.h"

Resultado *NT_Imprimir::Interpretar(Contexto *ctx) {
    // imprimimos las expresiones
    Resultado *expr;
    for (int i = 0; i < this->lista_expr->lista_expresiones.size(); i++) {
        expr = this->lista_expr->lista_expresiones[i]->Interpretar(ctx);
        if (expr != nullptr) {


            if (QString::compare(expr->tipo->Nombre, QString("Integer"), Qt::CaseSensitive)== 0 ) {
                ctx->Imprimir(QString::number(expr->valor));

            } else if (QString::compare(expr->tipo->Nombre, QString("Float"), Qt::CaseSensitive ) == 0 ) {
                ctx->Imprimir(QString::number(expr->valorD));

            } else if (QString::compare(expr->tipo->Nombre, QString("String"), Qt::CaseSensitive ) == 0 ){
                ctx->Imprimir(expr->valorS);
            }
        }
    }
    ctx->Imprimir("\n");
    return nullptr;
}

QString NT_Imprimir::Graficar() {
    std::stringstream pPosicion, lPosicion;
    pPosicion << (void *) this;
    lPosicion << (void *) this->lista_expr;


    QString nodo = QString::fromStdString("n" + pPosicion.str() +
                                          " [ label=\"Impr\" fillcolor=\"#8f09b8\"];\n");
    nodo += QString::fromStdString("n" + pPosicion.str() + "1" +
                                   " [ label=\"(\" fillcolor=\"#8f09b8\"];\n");
    nodo += QString::fromStdString("n" + pPosicion.str() + " -> n"
                                   + pPosicion.str() + "1" + ";\n");

    nodo += QString::fromStdString("n" + pPosicion.str() + " -> n"
                                   + lPosicion.str() + ";\n");
    nodo += this->lista_expr->Graficar();

    nodo += QString::fromStdString("n" + pPosicion.str() + "2" +
                                   " [ label=\")\" fillcolor=\"#8f09b8\"];\n");
    nodo += QString::fromStdString("n" + pPosicion.str() + " -> n"
                                   + pPosicion.str() + "2" + ";\n");

    return nodo;
}

NT_Imprimir::NT_Imprimir(NT_ListaExpr *nodo) {
    this->lista_expr = nodo;
}

