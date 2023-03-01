#include "nt_asigvar.h"


NT_AsigVar::NT_AsigVar(AbstractExp *id, AbstractExp *expr) : ID(id), Expr(expr) {}

// asignamos variables a la memoria
Resultado *NT_AsigVar::Interpretar(Contexto *ctx) {
    Resultado* idR = this->ID->Interpretar(ctx);
    Resultado* exp = this->Expr->Interpretar(ctx);

    if (exp == nullptr){
        ctx->AddError(QString("Expresión incorrecta en la asignacion: " + idR->valorS + " = "));
        return nullptr;
    }

    Simbolo* simbolo = ctx->memoria->getSimbolo(idR->valorS);

    if (simbolo != nullptr) {
        //manejo de tipos simple
        if (simbolo->tipo->Equal(exp->tipo)){
            simbolo->resultado = exp;
        }else {
            ctx->AddError(QString("Tipos Incorrectos"));
        }

    }else {
        ctx->AddError(QString("No se ha podido encontrar la variable: " + idR->valorS));
    }

    return nullptr;
}

QString NT_AsigVar::Graficar() {
    std::stringstream  pPosicion, idPosicion, ePosicion ;
    pPosicion <<(void*)this;
    idPosicion <<(void*)this->ID;
    ePosicion <<(void*)this->Expr;


    QString nodo = QString::fromStdString("n" + pPosicion.str() +
            " [ label=\"AsigVar\" shape=record, fillcolor=midnightblue];\n");
    nodo +=  QString::fromStdString("n" + pPosicion.str() + " -> n"
            + idPosicion.str()+ ";\n");
    nodo += this->ID->Graficar();
    nodo +=  QString::fromStdString("n" + pPosicion.str() + " -> n"
            + ePosicion.str()+ ";\n");
    nodo += this->Expr->Graficar();
    return nodo;
}
