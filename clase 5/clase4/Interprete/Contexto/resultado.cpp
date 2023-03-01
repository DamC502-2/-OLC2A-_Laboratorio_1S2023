#include "resultado.h"

Resultado::Resultado()
{   this->valor = 0;
    this->valorD = 0;
    this->valorS = QString("");
}

Resultado::Resultado(int valor){
    this->valor = valor;
    this->valorD = 0;
    this->valorS = QString("");
    this->tipo =  new Tipo(nullptr, -1, 1, 1, 1, QString("Integer"));
}
Resultado::Resultado(double valorD){
    this->valor = 0;
    this->valorD = valorD;
    this->valorS = QString("");
    this->tipo = new Tipo(nullptr, -1, 1, 1, 1, QString("Float"));
}
Resultado::Resultado(QString valorS){
    this->valor = 0;
    this->valorD = 0;
    this->valorS = valorS;
    this->tipo = new Tipo(nullptr, -1, 1, 1, 1, QString("String"));

}
