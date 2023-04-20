#ifndef GENERADOR_H
#define GENERADOR_H

#include<QString>
#include<QStack>
#include <QMap>
#include "Compilador/T_Funciones.h"
#include "Compilador/T_Simbolos.h"

struct duplaDisplay {
    QString EV;
    QString EF;
    QString LInicio;
};

class generador
{
public:
    generador();
    QString salida;
    int contadorEtq;
    int contadorTemp;
    QString newLabel();

    void imprimir(QString entrada);
    //manejo de display
    QStack<duplaDisplay*> display;
    void pushDisplay(QString EtqV, QString EtqF, QString EtqInicio);
    QString peekEtqV();
    QString peekEtqF();
    QString peekEtqInicio();
    void popDisplay();
    //tabla de simbolos
    T_Simbolos* tSimbolos;


    //manejo de funciones:
    T_Funciones *tFunciones;
    void addParametro(QString nombre, QString tipo, QString tipo_parametro );

    //manejo de temporales para segmento

    QString newTemp(); //modificado
    QString newTempB( bool expr1, bool expr2 ); //modificado

    //nuevas funciones para temporales
    QMap<QString, QString>* segmento_temps;
    void popTemporales(); //escribe el pop de los terminales al stack
    void pushTemporales(); //escribe el push de los terminales al stack
    void limpiarTemporales(); //limpia los temporales







};

#endif // GENERADOR_H
