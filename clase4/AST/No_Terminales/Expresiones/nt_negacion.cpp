#include "nt_negacion.h"

NT_Negacion::NT_Negacion(AbstractExp *derecha) : Derecha(derecha) {}

Resultado *NT_Negacion::Interpretar(Contexto *ctx) {
    return nullptr;
}

QString NT_Negacion::Graficar() {
    std::stringstream  pPosicion ,dPosicion;
    pPosicion <<(void*)this;
    dPosicion <<(void*)this->Derecha;

    QString nodo = QString::fromStdString("n" + pPosicion.str() +
            " [ label=\"-\" fillcolor=yellowgreen];\n");
    nodo += this->Derecha->Graficar();
    nodo +=  QString::fromStdString("n" + pPosicion.str() + " -> n"
            + dPosicion.str() + ";\n");
    return nodo;

}
