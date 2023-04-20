//
// Created by damihan on 1/04/23.
//

#ifndef CLASE6_RESULTADO_H
#define CLASE6_RESULTADO_H


#include <QString>

class Resultado {
public:
    QString EV;
    QString EF;
    QString Dir; //valor
    QString LSalida;
    QString Linicio;
    bool isTemp;
    // manejo stack
    QString Referencia;
    QString Tipo;
    Resultado();

};


#endif //CLASE6_RESULTADO_H
