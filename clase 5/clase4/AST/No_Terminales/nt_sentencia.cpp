#include "nt_sentencia.h"


Resultado *NT_Sentencia::Interpretar(Contexto *ctx) {
    return  this->hijo->Interpretar(ctx);
//    return nullptr;
}

QString NT_Sentencia::Graficar() {
    std::stringstream  pPosicion, sPosicion;
    pPosicion <<(void*)this;
    sPosicion <<(void*)this->hijo;

    QString nodo = QString::fromStdString("n" + pPosicion.str() +
            " [ label=\"Sent\" fillcolor=yellow];\n");
    nodo += this->hijo->Graficar();
    nodo +=  QString::fromStdString("n" + pPosicion.str() + " -> "
            + sPosicion.str()+ ";\n");
    return nodo;

}

void NT_Sentencia::AddNodo(AbstractExp *hijo) {
    this->hijo = hijo;
}
