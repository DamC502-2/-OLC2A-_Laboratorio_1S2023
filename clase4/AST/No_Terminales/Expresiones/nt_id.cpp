#include "nt_id.h"

Resultado *NT_ID::Interpretar(Contexto *ctx) {
    return nullptr;
}

QString NT_ID::Graficar() {
    std::stringstream pPosicion ;
    pPosicion << (void*)this;
    return QString::fromStdString("n" + pPosicion.str() +
                                  " [ label=\"EXP: ID" + this->id.toStdString() +
                                  "\"  shape=record fillcolor=tomato];\n");
}

NT_ID::NT_ID(const QString &id) : id(id) {
}
