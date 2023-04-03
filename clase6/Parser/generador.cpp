#include "generador.h"

generador::generador()
{
    this->contadorEtq = 0;
    this->contadorTemp = 0;
    this->salida = QString("");
    this->display = QStack<duplaDisplay*>();
}

QString generador::newLabel(){
    QString etiqueta =  "L" + QString::number(this->contadorEtq)  ;
    this->contadorEtq++;
    return etiqueta;
}

QString generador::newTemp() {
    QString temporal = "T" + QString::number(this->contadorTemp);
    this->contadorTemp++;
    return temporal;
}

QString generador::newTempB(bool expr1, bool expr2){
    if (expr1){
        this->contadorTemp--;
    }
    if (expr2){
        this->contadorTemp--;
    }
    QString temporal = "T" + QString::number(this->contadorTemp);
    this->contadorTemp++;
    return temporal;
}

void generador::imprimir(QString entrada) {
    this->salida += entrada + "\n";
}
//E -> E + E
// E1 ? temp  -> temporal--
// E2 ? temp ?  temporal--
/*
T1  T2  3
3 -1 = 2
        2 - 1 = 1

t1 = t1 + t2
*/

void generador::pushDisplay(QString EtqV, QString EtqF, QString EtqInicio) {
    duplaDisplay *segmentoDisplay = new duplaDisplay;
    segmentoDisplay->EF= EtqF;
    segmentoDisplay->EV = EtqV;
    segmentoDisplay->LInicio = EtqInicio;
    this->display.push(segmentoDisplay);
}

QString generador::peekEtqV() {
    return this->display.top()->EV;
}

QString generador::peekEtqF() {
    return this->display.top()->EF;
}

QString generador::peekEtqInicio() {
    return this->display.top()->LInicio;
}

void generador::popDisplay() {
    this->display.pop();
}






