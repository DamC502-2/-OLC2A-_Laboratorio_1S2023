#include "nt_declvar.h"

Resultado *NT_DeclVar::Interpretar(Contexto *ctx) {
    Resultado* idR = this->ID->Interpretar(ctx);
    Resultado* tipoR = this->tipo->Interpretar(ctx);

    idR->tipo = tipoR->tipo;


    Simbolo * nueva_variable = new Simbolo(nullptr, idR->tipo, idR->valorS);

    if (this->Expr != nullptr) {
        Resultado * exprR = this->Expr->Interpretar(ctx);
        if (idR->tipo->Equal(exprR->tipo)) {
            nueva_variable->resultado = exprR;
        }else {
            ctx->AddError(QString("La expresión no es del mismo tipo de la expresion"));
        }
    }

    ctx->memoria->addSimbolo(idR->valorS,nueva_variable);
    return nullptr;
}

QString NT_DeclVar::Graficar() {
    std::stringstream  pPosicion, idPosicion, ePosicion, tPosicion ;
    pPosicion <<(void*)this;
    idPosicion <<(void*)this->ID;
    ePosicion <<(void*)this->Expr;
    tPosicion <<(void*)this->tipo;

    QString nodo = QString::fromStdString("n" + pPosicion.str() +
            " [ label=\"Decl Var\" shape=record, fillcolor=red];\n");
    nodo +=  QString::fromStdString("n" + pPosicion.str() + " -> n"
            + idPosicion.str()+ ";\n");
    nodo += this->ID->Graficar();
    nodo +=  QString::fromStdString("n" + pPosicion.str() + " -> n"
            + tPosicion.str()+ ";\n");
    nodo += this->tipo->Graficar();

    if (this->Expr != nullptr){
        nodo +=  QString::fromStdString("n" + pPosicion.str() + " -> n"
                + ePosicion.str()+ ";\n");
        nodo += this->Expr->Graficar();
    }
    return nodo;
}


// constructor resumido c++-style
NT_DeclVar::NT_DeclVar(AbstractExp *tipo, AbstractExp *id, AbstractExp *expr) : tipo(tipo), ID(id), Expr(expr) {}

//constructor tipo "java"
NT_DeclVar::NT_DeclVar(AbstractExp *tipo, AbstractExp *id) {
    this->Expr = nullptr;
    this->ID = id;
    this->tipo = tipo;
}
