//
// Created by damihan on 18/04/23.
//

#include <iostream>
#include "T_Funciones.h"

T_Funciones::T_Funciones() {
    this->funciones = new QMap<QString, Funcion *>();
    this->funcion_actual = nullptr;

}

void T_Funciones::addFuncion(QString nombre) {
    this->funcion_actual = new Funcion();
    this->funcion_actual->nombre = nombre;
}

void T_Funciones::addParametro(Parametro *parametro) {
    if (funcion_actual == nullptr) {
        std::cerr << "Error: añadiendo parametro: " << parametro->nombre.toStdString()
                  << "a una función inválida" << std::endl;
        return;
    }
    this->funcion_actual->insertParametro(parametro);
}

void T_Funciones::guardarFuncion() {

    if (this->funciones->contains(this->funcion_actual->nombre)){
        std::cerr<<"Error: la funcion:"<<this->funcion_actual->nombre.toStdString()<<
        " ya fue defninida previamente"<<std::endl;
        return;
    }
    this->funciones->insert(this->funcion_actual->nombre, this->funcion_actual);
}

Funcion *T_Funciones::getFuncion(QString id) {
    if (this->funciones->contains(id)){
        return this->funciones->value(id);
    }
    return nullptr;
}
