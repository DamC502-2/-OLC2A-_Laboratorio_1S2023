#ifndef RESULTADO_H
#define RESULTADO_H

#include<QString>

class Resultado
{
public:
    int valor;
    double valorD;
    QString valorS;

    Resultado();
    Resultado(int valor);
    Resultado(double valorD);
    Resultado(QString valorS);

};

#endif // RESULTADO_H
