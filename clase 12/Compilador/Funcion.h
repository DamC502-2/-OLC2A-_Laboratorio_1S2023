//
// Created by damihan on 18/04/23.
//

#ifndef CLASE12_FUNCION_H
#define CLASE12_FUNCION_H


#include <QString>
#include <QVector>

class Parametro{
public:
    QString nombre;
    QString tipo;
    bool referencia;

    Parametro(const QString &nombre, const QString &tipo, bool referencia);

};


class Funcion {
public:
    QString nombre;
    QVector<Parametro*>parametros;
    QString tipoRetorno;


    Funcion();
    void insertParametro( Parametro* parametro);
    Parametro* getParametro(int posicion);




};


#endif //CLASE12_FUNCION_H
