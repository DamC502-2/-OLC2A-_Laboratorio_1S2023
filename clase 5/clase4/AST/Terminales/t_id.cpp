#include "t_id.h"

#include <sstream>
Resultado *T_ID::Interpretar(Contexto *ctx) {
    Resultado* resultado = new Resultado();
    resultado->valorS = this->id;
    return resultado;
}

QString T_ID::Graficar() {
    std::stringstream  pPosicion ;
    pPosicion <<(void*)this;

    return QString::fromStdString("n" + pPosicion.str() +
    " [ label=\"T ID" + this->id.toStdString() +
    "\"  shape=record fillcolor=\"#12342c\"];\n");
}

T_ID::T_ID( QString id)  {
    this->id = id;
}
