#include "nt_tipo.h"


NT_Tipo::NT_Tipo(QString tipo) {
 this->tipo = tipo;
}

Resultado *NT_Tipo::Interpretar(Contexto *ctx) {
    return nullptr;
}

QString NT_Tipo::Graficar() {
    std::stringstream  pPosicion;
    pPosicion <<(void*)this;

    return QString::fromStdString("n" +pPosicion.str()+
    " [ label=\"Tipo" + this->tipo.toStdString() +
    "\"  shape=record fillcolor=grey];\n");
}
