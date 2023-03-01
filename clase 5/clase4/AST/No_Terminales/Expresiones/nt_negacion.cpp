#include "nt_negacion.h"

NT_Negacion::NT_Negacion(AbstractExp *derecha) : Derecha(derecha) {}

Resultado *NT_Negacion::Interpretar(Contexto *ctx) {
    Resultado* der = this->Derecha->Interpretar(ctx);

    if (der != nullptr){
        //TODO verificacion de tipos
        Resultado* respuesta = new Resultado();
        respuesta->valorD = -(der->valorD);
        respuesta->valorS.append(der->valorS);
        respuesta->valor = -(der->valor);
        respuesta->tipo = der->tipo;
    }
    ctx->AddError("Operacion NEGACION inválida");
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
