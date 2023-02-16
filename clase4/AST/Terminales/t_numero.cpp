#include "t_numero.h"



Resultado *T_Numero::Interpretar(Contexto *ctx) {
    return nullptr;
}

QString T_Numero::Graficar() {
    std::stringstream  pPosicion;
    pPosicion <<(void*)this;
    return QString::fromStdString("n" + pPosicion.str()+
    " [ label=\"T_NUM " + this->numero.toStdString() +
    "\"  shape=record fillcolor=\"#342012\"];\n");
}

T_Numero::T_Numero(QString num) {
    this->numero = num;
}

