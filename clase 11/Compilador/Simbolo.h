//
// Created by damihan on 10/04/23.
//

#ifndef CLASE11_SIMBOLO_H
#define CLASE11_SIMBOLO_H


#include <QString>
#include <QVector>

class Simbolo {
public:
    Simbolo(const QString &nombre, int linea, int columna);

    QString nombre;
    int linea;
    int columna;
    // arreglos
    int Dimensiones;
    QVector<int>Minimo;
    QVector<int>Maximo;

    //funcnioens para arreglos
    void addDimension( int minimo, int maiximo ); //[1..2, 1..4]
    int getDimFilas(int dimension);


};


#endif //CLASE11_SIMBOLO_H
