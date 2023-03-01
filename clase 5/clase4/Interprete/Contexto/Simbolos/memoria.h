#ifndef MEMORIA_H
#define MEMORIA_H
#include <QMap>
#include "simbolo.h"
class Memoria
{
public:
    Memoria();
    explicit Memoria(Memoria* anterior);
    Memoria* anterior;
    QMap<QString, Simbolo *> variables;
    Simbolo* getSimbolo(QString nombre);
    bool existSimbolo( QString nombre);
    bool existSimboloInThisScope(QString nombre);
    void addSimbolo(QString nombre, Simbolo* simbolo);
    QString reportar();
};

#endif // MEMORIA_H
