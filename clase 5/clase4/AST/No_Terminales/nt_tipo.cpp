#include "nt_tipo.h"


NT_Tipo::NT_Tipo(QString tipo) {
 this->tipo = tipo;
}

Resultado *NT_Tipo::Interpretar(Contexto *ctx) {
    Tipo* tipo  = ctx->tabla_tipos->getTipo(this->tipo);

    if (tipo == nullptr) {
        ctx->AddError(QString("tipo no encontrado: " + this->tipo));
    }
    Resultado* resultado = new Resultado();
    resultado->tipo = tipo;

    return resultado;
}

QString NT_Tipo::Graficar() {
    std::stringstream  pPosicion;
    pPosicion <<(void*)this;

    return QString::fromStdString("n" +pPosicion.str()+
    " [ label=\"Tipo " + this->tipo.toStdString() +
    "\"  shape=record fillcolor=grey];\n");
}
