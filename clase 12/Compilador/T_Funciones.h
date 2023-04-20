//
// Created by damihan on 18/04/23.
//

#ifndef CLASE12_T_FUNCIONES_H
#define CLASE12_T_FUNCIONES_H


#include <QString>
#include <QMap>
#include "Funcion.h"

class T_Funciones {
public:
    QMap<QString, Funcion*> *funciones;
    Funcion* funcion_actual;

    void addFuncion(QString nombre);
    void addParametro(Parametro* parametro);
    void guardarFuncion();
    Funcion* getFuncion(QString id);

    T_Funciones();

};


#endif //CLASE12_T_FUNCIONES_H
