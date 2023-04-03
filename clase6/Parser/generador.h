#ifndef GENERADOR_H
#define GENERADOR_H

#include<QString>
#include<QStack>

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

};

#endif // GENERADOR_H
