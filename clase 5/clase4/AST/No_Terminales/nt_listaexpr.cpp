#include "nt_listaexpr.h"

Resultado *NT_ListaExpr::Interpretar(Contexto *ctx) {
    return nullptr;
}

QString NT_ListaExpr::Graficar() {
    std::stringstream  pPosicion, lPosicion;
    pPosicion <<(void*)this;


    QString nodo = QString::fromStdString("n" + pPosicion.str()  +
            " [ label=\"ListE\" fillcolor=slateblue];\n");

    for (int i = 0; i < this->lista_expresiones.size(); i++ ){
        lPosicion.str(std::string());
        lPosicion.clear();
        lPosicion << (void*)this->lista_expresiones[i];
        nodo +=  QString::fromStdString("n" + pPosicion.str() + " -> n"
                + lPosicion.str() + ";\n");
        nodo += this->lista_expresiones[i]->Graficar();
    }
    return nodo;
}

NT_ListaExpr::NT_ListaExpr(AbstractExp* expr) {
    this->lista_expresiones = QVector<AbstractExp*>();
    this->lista_expresiones.push_back(expr);

}

void NT_ListaExpr::AddNodo(AbstractExp *nodo) {
    this->lista_expresiones.push_back(nodo);
}
