//
// Created by damihan on 18/04/23.
//

#include "Funcion.h"

Parametro::Parametro(const QString &nombre, const QString &tipo, bool referencia) : nombre(nombre), tipo(tipo),
                                                                                    referencia(referencia) {}

Funcion::Funcion() {
    this->nombre = QString("");
    this->tipoRetorno = QString("");
    this->parametros =  QVector<Parametro*>();

}

void Funcion::insertParametro(Parametro *parametro) {
    this->parametros.push_back(parametro);
}

Parametro *Funcion::getParametro(int posicion) {

    if (this->parametros.size() <= posicion || 0 > posicion) {
        return nullptr;
    }
    return this->parametros[posicion];

}
