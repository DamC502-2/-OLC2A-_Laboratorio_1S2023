#ifndef T_TIPOS_H
#define T_TIPOS_H

#include <QHash>
#include <QString>
#include "tipo.h"

class Contexto;

class T_Tipos {
    //
    QHash<QString, Tipo *> tipos;


public:
    T_Tipos *anterior;
    int nivel;

    int getSize();
    T_Tipos(int nivel, T_Tipos *anterior);
    void addTipoCtx(Tipo *nuevoTipo, Contexto* ctx);
    void addTipo(Tipo *nuevoTipo);
    void addTiposBásicos();
    Tipo *getTipo(QString id);
    bool existTipo(QString nombre);


};

#endif // T_TIPOS_H
