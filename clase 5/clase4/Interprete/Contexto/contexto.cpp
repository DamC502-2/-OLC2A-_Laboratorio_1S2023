#include "contexto.h"

Contexto::Contexto()
{
    this->consola = QString("");
    this->errores = QVector<QString>();
    this->tabla_tipos = new T_Tipos(0, nullptr);
    this->tabla_tipos->addTiposBásicos();
    this->memoria = new Memoria();
}

void Contexto::AddError(QString error) {
    this->errores.push_back(error);

}

void Contexto::pushAmbito() {
    this->reporte.append(this->memoria->reportar());
    this->tabla_tipos = new T_Tipos(this->tabla_tipos->nivel, this->tabla_tipos);
    this->memoria = new Memoria(this->memoria);
}

void Contexto::popAmbito() {
    // TODO aplicar destructor;
    this->reporte.push_back("Pop: ======\n");
    this->reporte.push_back(this->memoria->reportar());
    this->tabla_tipos = this->tabla_tipos->anterior;
    this->memoria = this->memoria->anterior;

}

QString Contexto::reportar() {
    QString reporte_total = QString();
    for(int i = 0; i<this->reporte.size(); i++){
        reporte_total += this->reporte[i];
    }
    return reporte_total;
}

void Contexto::Imprimir(QString entrada) {
    this->consola += entrada;
}

QString Contexto::getErrores() {
    QString salida;
    for (int i = 0; i < this->errores.size(); i++){
        salida += this->errores[i];
        salida += "\n";
    }
    return salida;
}
