#ifndef CONTEXTO_H
#define CONTEXTO_H

#include<QString>
#include<QVector>
#include <Interprete/Contexto/Tipos/t_tipos.h>
#include <Interprete/Contexto/Simbolos/memoria.h>
#include <Interprete/Contexto/Simbolos/simbolo.h>
#include <Interprete/Contexto/Tipos/tipo.h>
#include "resultado.h"

class Contexto
{

    QVector<QString> reporte;
    QVector<QString> errores;
public:
    QString consola;
    T_Tipos* tabla_tipos;
    Memoria* memoria;
    Contexto();
    void AddError(QString error);
    void pushAmbito();
    void popAmbito();
    void Imprimir(QString entrada);
    QString reportar();

    QString getErrores();
};

#endif // CONTEXTO_H
