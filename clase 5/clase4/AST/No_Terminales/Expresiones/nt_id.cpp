#include "nt_id.h"

Resultado *NT_ID::Interpretar(Contexto *ctx) {
   Simbolo* variable = ctx->memoria->getSimbolo(this->id);
    if (variable != nullptr) {
        return variable->resultado;
    }
    ctx->AddError(QString("Variable " + this->id + " no encontrada"));
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
