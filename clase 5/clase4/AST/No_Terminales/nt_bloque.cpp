#include "nt_bloque.h"

NT_Bloque::NT_Bloque()
{
}

NT_Bloque::NT_Bloque(AbstractExp* lsentencias)
{
    this->lSentencias = lsentencias;

}

Resultado* NT_Bloque::Interpretar(Contexto* ctx){
    // push tabla simbolos tabla de tips
    ctx->pushAmbito();
    Resultado* res =  this->lSentencias->Interpretar(ctx);
    ctx->popAmbito();
    return res;
    // pop tabla simbolos
    //reportes
    //etc....
}


QString NT_Bloque::Graficar() {
    std::stringstream  pPosicion, lPosicion ;
    pPosicion <<(void*)this;
    lPosicion <<(void*)this->lSentencias;


    QString nodo = QString::fromStdString("n" + pPosicion.str() +
            " [ label=\"bloque\" fillcolor=black];\n");

    nodo += QString::fromStdString("n" + pPosicion.str()+ "1" +
            " [ label=\"{\" fillcolor=black];\n");

    nodo +=  QString::fromStdString("n" + pPosicion.str() + " -> n"
            + pPosicion.str()+ "1"+ ";\n");

    nodo +=  QString::fromStdString("n" + pPosicion.str()+ " -> n"
            + lPosicion.str()+ ";\n");

    nodo += this->lSentencias->Graficar();

    nodo += QString::fromStdString("n" + pPosicion.str()+ "2" +
            " [ label=\"}\" fillcolor=black];\n");

    nodo +=  QString::fromStdString("n" + pPosicion.str()+ " -> n"
            + pPosicion.str()+ "2"+ ";\n");
    return nodo;
}

void NT_Bloque::AddLSetencias(AbstractExp *nodo) {
    this->lSentencias = nodo;
}

