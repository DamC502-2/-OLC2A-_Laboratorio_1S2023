#ifndef GENERADOR_H
#define GENERADOR_H

#include<QString>
#include<QStack>
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
    QString newTemp();
    QString newTempB( bool expr1, bool expr2 );
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


};

#endif // GENERADOR_H
