#include "t_string.h"


Resultado *T_String::Interpretar(Contexto *ctx) {
    return nullptr;
}

QString T_String::Graficar() {
    std::stringstream  pPosicion;
    pPosicion <<(void*)this;
    return QString::fromStdString("n" + pPosicion.str() +
    " [ label=\"T STR: " + this->str.toStdString().substr(1,this->str.size()-2) +
    "\"  shape=record fillcolor=\"#004376\"];\n");
}

T_String::T_String(QString str) {
    this->str = str;
}
