//
// Created by damihan on 10/04/23.
//

#ifndef CLASE11_T_SIMBOLOS_H
#define CLASE11_T_SIMBOLOS_H


#include <QString>
#include <QMap>
#include "Simbolo.h"

class T_Simbolos {
public:
    T_Simbolos();
    T_Simbolos(T_Simbolos *anterior);

    T_Simbolos* anterior;
    QMap<QString, Simbolo*> *variables;
    Simbolo* getSimbolo(QString nombre);
    bool exitSimbolo(QString nombre);
    //funciones para arreglos
    //filas
    QString getTamDimF(QString id, int dimension);
    // funcion para añadir dimensiones
    void addDim(QString id, QString minimo, QString maximo);

    //atributos para stack
    int pos_libre_stack;
    //funciones para stack
    //modificado
    void addSimbolo(QString nombre, Simbolo* simbolo);




};


#endif //CLASE11_T_SIMBOLOS_H
