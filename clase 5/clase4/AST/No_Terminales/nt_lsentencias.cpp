#include "nt_lsentencias.h"

NT_LSentencias::NT_LSentencias()
{
      this->lista_sentencias = QVector<AbstractExp*>();

}

Resultado* NT_LSentencias::Interpretar(Contexto* ctx) {
    Resultado* temp;
    for (int i = 0; i < this->lista_sentencias.size(); i ++){

        temp = this->lista_sentencias[i]->Interpretar(ctx);
        /// es un return? es un break, es un continue, etc....
    }
    //
    return nullptr;
}


QString NT_LSentencias::Graficar() {
    std::stringstream  pPosicion, lPosicion;
    pPosicion <<(void*)this;
    QString nodo = QString::fromStdString("n" + pPosicion.str()  +
            " [ label=\"ListS\" fillcolor=springgreen];\n");

    for (int i = 0; i < this->lista_sentencias.size(); i++ ){
        lPosicion.str(std::string());
        lPosicion.clear();
        lPosicion << (void*)this->lista_sentencias[i];
        nodo +=  QString::fromStdString("n" + pPosicion.str() + " -> n"
                + lPosicion.str()+ ";\n");
        nodo += this->lista_sentencias[i]->Graficar();
    }
    return nodo;
}

void NT_LSentencias::AddSentencia(AbstractExp *nodo){
    this->lista_sentencias.push_back(nodo);

}
