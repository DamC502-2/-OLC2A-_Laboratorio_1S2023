#include "nt_suma.h"

Resultado *NT_Suma::Interpretar(Contexto *ctx) {
    return nullptr;
}

QString NT_Suma::Graficar() {
    std::stringstream  pPosicion, dPosicion, iPosicion ;
    pPosicion <<(void*)this;
    dPosicion <<(void*)this->Derecha;
    iPosicion <<(void*)this->Izquierda;

    QString nodo = QString::fromStdString("n" + pPosicion.str() +
            " [ label=\"+\" fillcolor=cornflowerblue];\n");
    nodo +=  QString::fromStdString("n" + pPosicion.str() + " -> n"
            + iPosicion.str()+ ";\n");
    nodo += this->Izquierda->Graficar();
    nodo +=  QString::fromStdString("n" + pPosicion.str()+ " -> n"
            + dPosicion.str() + ";\n" );
    nodo += this->Derecha->Graficar();
    return nodo;
}

NT_Suma::NT_Suma(AbstractExp *izquierda, AbstractExp *derecha) : Izquierda(izquierda), Derecha(derecha) {}
