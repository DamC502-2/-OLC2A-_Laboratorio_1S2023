#include "resultado.h"

Resultado::Resultado()
{
    this->valor = 0;
    this->valorD = 0;
    this->valorS = QString("");
}

Resultado::Resultado(int valor){
    this->valor = valor;
    this->valorD = 0;
    this->valorS = QString("");
}
Resultado::Resultado(double valorD){
    this->valor = 0;
    this->valorD = valorD;
    this->valorS = QString("");
}
Resultado::Resultado(QString valorS){
    this->valor = 0;
    this->valorD = 0;
    this->valorS = valorS;

}
